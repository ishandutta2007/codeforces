#include <stdio.h>
#include <set>
using namespace std;
const int N=1050;
set<int> s,t;
int cnt1[10],cnt2[10];
char word[N];
int a[N];
int sol,ans;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",word+1);
	for(i=1;i<=n;i++) a[i]=word[i]-'0';
	scanf("%s",word+1);
	for(i=1;i<=n;i++)
	{
		s.insert(word[i]-'0');
		cnt1[word[i]-'0']++;
		t.insert(word[i]-'0');
		cnt2[word[i]-'0']++;
	}
	set<int>::iterator it;
	for(i=1;i<=n;i++)
	{
		it=s.lower_bound(a[i]);
		if(it!=s.end())
		{
			sol++;
			cnt1[*it]--;
			if(!cnt1[*it]) s.erase(*it);
		}
	}
	for(i=1;i<=n;i++)
	{
		it=t.upper_bound(a[i]);
		if(it!=t.end())
		{
			ans++;
			cnt2[*it]--;
			if(!cnt2[*it]) t.erase(*it);
		}
	}
	printf("%i\n%i\n",n-sol,ans);
	return 0;
}