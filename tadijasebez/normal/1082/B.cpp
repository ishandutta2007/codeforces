#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
char s[N];
int l[N],r[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='G') l[i]=l[i-1]+1;
		else l[i]=0;
	}
	int cnt=0;
	for(i=n;i>=1;i--)
	{
		if(s[i]=='G') r[i]=r[i+1]+1,cnt++;
		else r[i]=0;
	}
	int ans=0;
    for(i=1;i<=n;i++)
	{
		ans=max(ans,l[i]+1);
		if(l[i]==0) ans=max(ans,l[i-1]+r[i+1]+1);
	}
	ans=min(ans,cnt);
	printf("%i\n",ans);
	return 0;
}