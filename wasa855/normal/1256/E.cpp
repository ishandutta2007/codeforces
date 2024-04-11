#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
struct Node
{
	int a,pl;
};
bool cmp(Node x,Node y)
{
	return x.a<y.a;
}
Node b[N];
int a[N];
int sum[N];
int f[N];
int las[N];
int ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) b[i].a=read(),b[i].pl=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++) a[i]=b[i].a;
//	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int minn=-a[1],pl=0;
	f[1]=f[2]=n*1000000000LL;
	for(int i=3;i<=n;i++)
	{
		f[i]=minn+a[i];
		las[i]=pl;
		if(f[i-2]-a[i-1]<minn) minn=f[i-2]-a[i-1],pl=i-2;
	}
//	for(int i=3;i<=n;i++) printf("%lld ",f[i]);
//	cout<<"\n";
	vector<int> v;
	v.pb(n);
	for(int i=n;i!=0;i=las[i])
	{
		v.pb(las[i]);
	}
	cout<<f[n]<<" "<<v.size()-1<<endl;
	int cnt=0;
	for(int i=v.size()-1;i>0;i--)
	{
		cnt++;
		for(int j=v[i]+1;j<=v[i-1];j++) ans[b[j].pl]=cnt;
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//