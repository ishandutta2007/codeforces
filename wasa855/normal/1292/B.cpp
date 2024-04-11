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
#define INF ((int)1e16)
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 75
int x[N],y[N];
int x0,y0,ax,ay,bx,by,xs,ys,T;
int dis(int i,int j){return abs(x[i]-x[j])+abs(y[i]-y[j]);}
int rdis(int i){return abs(x[i]-xs)+abs(y[i]-ys);}
signed main()
{
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>T;
	int n=1; x[n]=x0,y[n]=y0;
	while(x[n]<INF&&y[n]<INF)
	{
		n++;
		x[n]=ax*x[n-1]+bx,y[n]=ay*y[n-1]+by;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=T;
		if(t<rdis(i)) continue;
		t-=rdis(i); int cur=1;
		for(int j=i-1;j>=1;j--)
		{
			if(t<dis(j,j+1)) break;
			t-=dis(j,j+1);
			cur++;
		}
		if(i!=n&&t>=dis(1,i+1))
		{
			t-=dis(1,i+1); cur++;
			for(int j=i+2;j<=n;j++)
			{
				if(t<dis(j,j-1)) break;
				t-=dis(j,j-1);
				cur++;
			}
		}
		ans=max(ans,cur);
	}
	cout<<ans<<endl;
	return 0;
}