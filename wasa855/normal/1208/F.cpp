#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N (1<<21)
int cnt[N],a[N];
void update(int dep,int x)
{
	if(cnt[x]>=2) return ;
	if(dep==-1) {cnt[x]++; return ;}
	update(dep-1,x);
	if(x&(1<<dep)) update(dep-1,x^(1<<dep));
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		if(i<=n-2)
		{
			int now=0,t=0;
			for(int j=20;j>=0;j--)
			{
				if(a[i]&(1<<j)) now|=(1<<j);
				else if(cnt[t|(1<<j)]>=2) now|=(1<<j),t|=(1<<j);
			}
			if(now>ans) ans=now;
		}
		update(20,a[i]);
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}