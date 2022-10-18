#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 505
struct Node
{
	int a,b,k;
};
Node a[N];
bool cmp(Node x,Node y)
{
	return x.b>y.b;
}
int f[N][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].a=read(),a[i].b=read(),a[i].k=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[i][j]=f[i-1][j]+max(0LL,a[i].a-a[i].b*a[i].k);
			if(j!=0) f[i][j]=max(f[i][j],f[i-1][j-1]+max(0LL,a[i].a-(j-1)*a[i].b));
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[n][i]);
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}