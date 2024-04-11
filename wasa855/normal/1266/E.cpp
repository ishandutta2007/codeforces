#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
typedef pair<int,int> pii;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int ans;
map<int,int> b[N];
int a[N],cnt[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read(),ans+=a[i];
	int q=read();
	while(q--)
	{
		int u=read(),v=read(),w=read();
		if(b[u][v])
		{
			int d=b[u][v];
			cnt[d]--;
			if(cnt[d]<a[d]) ans++;
		}
		b[u][v]=w;
		if(b[u][v])
		{
			int d=b[u][v];
			cnt[d]++;
			if(cnt[d]<=a[d]) ans--;
		}
		printf("%lld\n",ans);
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}