#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=300050;
int cnt[3];
char s[N];
int main()
{
	scanf("%*i");
	scanf("%s",s+1);
	int n=strlen(s+1);
	int need=n/3;
	for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
	vector<int> ins;
	for(int i=need;i>cnt[0];i--) ins.pb(0);
	for(int i=need;i>cnt[1];i--) ins.pb(1);
	for(int i=need;i>cnt[2];i--) ins.pb(2);
	int t=0,sz=ins.size();
	for(int i=1;i<=n;i++)
	{
		if(t<sz && cnt[s[i]-'0']>need && ins[t]<s[i]-'0')
		{
			cnt[s[i]-'0']--;
			s[i]=ins[t]+'0';
			t++;
		}
	}
	int r=sz-1;
	for(int i=n;i>=1;i--)
	{
		if(r>=t && cnt[s[i]-'0']>need)
		{
			cnt[s[i]-'0']--;
			s[i]=ins[r]+'0';
			r--;
		}
	}
	printf("%s",s+1);
	return 0;
}