#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 205
struct Node{int v,r;};
Node max(Node a,Node b)
{
	if(a.v>b.v||(a.v==b.v&&a.r>b.r)) return a;
	else return b;
}
struct Vec{int x,y;}a[N];
Vec operator - (Vec a,Vec b) {return (Vec){a.x-b.x,a.y-b.y};}
int cross(Vec a,Vec b) {return a.x*b.y-a.y*b.x;}
Node f[N][N]; int n,m;
bool chk(int mid)
{
	for(int i=1;i<=n;i++) for(int j=i+2;j<=n;j++) f[i][j]=(Node){-inf,-inf};
	for(int len=3;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=i+1;k<=j;k++)
			{
				Node go=(Node){f[i][k].v+f[k][j].v,f[i][k].r+f[k][j].r+cross(a[i]-a[j],a[k]-a[i])};
				if(go.r>=mid) go.v++,go.r=0;
				f[i][j]=max(f[i][j],go);
			}
		}
	}
	return f[1][n].v>=m;
}
signed main()
{
	cin>>n>>m; m++;
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	int l=0,r=INF,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}