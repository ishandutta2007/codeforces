#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int lim=1e5;
set<int> st[2][2];
int a[N],b[N];
char s[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) a[i]=s[i]-'0';
	scanf("%s",s+1);
	for(i=1;i<=n;i++) b[i]=s[i]-'0';
    for(i=1;i<=n;i++)
	{
		if(a[i]!=0) st[i&1][0].insert(i);
		if(a[i]!=9) st[i&1][1].insert(i);
	}
	st[0][0].insert(n+1);
	st[0][1].insert(n+1);
	st[1][0].insert(n+1);
	st[1][1].insert(n+1);
	vector<pair<int,int>> ans;
	ll cnt=0;
	for(i=1;i<n;i++)
	{
		if(st[i&1][0].count(i)) st[i&1][0].erase(i);
		if(st[i&1][1].count(i)) st[i&1][1].erase(i);
		while(a[i]<b[i])
		{
			int c=i&1,p=c^1;
			int w=min(*st[p][1].begin(),*st[c][0].begin());
			if(w==n+1) return 0*printf("-1\n");
            cnt+=w-i;
            for(int j=w-1;ans.size()<lim && j>=i;j--)
			{
				ans.pb({j,((j&1)==c)?1:-1});
			}
			if((w&1)==c)
			{
				a[w]--;
				if(a[w]==0) st[c][0].erase(w);
			}
			else
			{
				a[w]++;
				if(a[w]==9) st[p][1].erase(w);
			}
			//printf("%i %i\n",w,a[w]);
			a[i]++;
		}
		while(a[i]>b[i])
		{
			int c=i&1,p=c^1;
			int w=min(*st[c][1].begin(),*st[p][0].begin());
			if(w==n+1) return 0*printf("-1\n");
            cnt+=w-i;
            for(int j=w-1;ans.size()<lim && j>=i;j--)
			{
				ans.pb({j,((j&1)==c)?-1:1});
			}
			if((w&1)==c)
			{
				a[w]++;
				if(a[w]==9) st[c][1].erase(w);
			}
			else
			{
				a[w]--;
				if(a[w]==0) st[p][0].erase(w);
			}
			//printf("%i %i\n",w,a[w]);
			a[i]--;
		}
	}
	if(a[n]!=b[n]) return 0*printf("-1\n");
	printf("%lld\n",cnt);
	for(auto p:ans) printf("%i %i\n",p.first,p.second);
	return 0;
}