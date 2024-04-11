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
#define N 300005
int a[N];
int b[N];
vector<int> v[N];
int pre[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=b[i]=read();
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
//	cout<<"\n";
	for(int i=1;i<=m;i++) v[i].clear();
	for(int i=1;i<=n;i++) v[a[i]].pb(i);
	int ans=1;
	pre[1]=1;
	for(int i=1;i<m;i++)
	{
		if(v[i].back()<v[i+1].front()) pre[i+1]=pre[i]+1;
		else pre[i+1]=1;
		if(pre[i+1]>ans) ans=pre[i+1];
	}
	cout<<m-ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}