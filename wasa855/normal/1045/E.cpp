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
#define ll long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1005
struct Vec
{
	int x,y,col,id;
	Vec(int a=0,int b=0,int c=0) {x=a,y=b,col=c;}
};
Vec operator + (Vec x,Vec y) {return Vec(x.x+y.x,x.y+y.y);}
Vec operator - (Vec x,Vec y) {return Vec(x.x-y.x,x.y-y.y);}
int operator * (Vec x,Vec y) {return x.x*y.x+x.y*y.y;}
int cross(Vec x,Vec y) {return x.x*y.y-x.y*y.x;}
int operator == (Vec x,Vec y) {return x.x==y.x&&x.y==y.y;}
int operator != (Vec x,Vec y) {return !(x==y);}
int sgn(int x) {return x>0?1:(x==0?0:-1);}
int isin(Vec a,Vec b,Vec c,Vec x) {return sgn(cross(x-a,b-a))==sgn(cross(x-b,c-b))&&sgn(cross(x-b,c-b))==sgn(cross(x-c,a-c));}
Vec a[N];
bool cmp(Vec x,Vec y) {return cross(x-a[1],y-a[1])<0;}
int vis[N],st[N],tmp[N],tp,n;
void convex()
{
	for(int i=1;i<=n;i++) if(a[i].x<a[1].x) swap(a[1],a[i]);
	sort(a+2,a+n+1,cmp);
	st[++tp]=1;
	// for(int i=1;i<=n;i++) printf("%d %d %d,%d\n",a[i].x,a[i].y,a[i].id,a[i].col);
	for(int i=2;i<=n;i++)
	{
		// printf("^ %d %d %d - %d\n",i,st[tp],st[tp-1],cross(a[st[tp]]-a[i],a[st[tp-1]]-a[st[tp]]));
		while(tp>=2&&cross(a[st[tp]]-a[i],a[st[tp-1]]-a[st[tp]])<0) tp--;
		st[++tp]=i;
	}
	// for(int i=1;i<=tp;i++) printf("%d%c",st[i]," \n"[i==tp]);
}
void solve(Vec x,Vec y,Vec z)
{
	if(x.col==z.col) swap(y,z);
	else if(y.col==z.col) swap(x,z);
	assert(x.col==y.col&&x.col!=z.col);
	// printf("^ %d %d %d\n",x.id,y.id,z.id);
	for(int i=1;i<=n;i++) if(a[i]!=x&&a[i]!=y&&a[i]!=z&&isin(x,y,z,a[i]))
	{
		if(a[i].col==x.col) continue;
		printf("%d %d\n",a[i].id,z.id);
		solve(x,y,a[i]),solve(x,z,a[i]),solve(y,z,a[i]);
		return ;
	}
	for(int i=1;i<=n;i++) if(a[i]!=x&&a[i]!=y&&a[i]!=z&&isin(x,y,z,a[i])) printf("%d %d\n",a[i].id,x.id);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].col=read(),a[i].id=i-1;
	// cout<<isin(a[6],a[5],a[4],a[7])<<endl;
	// exit(0);
	convex();
	int dif=a[st[1]].col!=a[st[tp]].col;
	for(int i=1;i<tp;i++) dif+=a[st[i]].col!=a[st[i+1]].col;
	// cout<<dif<<endl;
	if(dif>=3) return cout<<"Impossible\n",0;
	int als=1; for(int i=1;i<n;i++) als&=a[i].col==a[i+1].col;
	if(als)
	{
		cout<<n-1<<endl;
		for(int i=1;i<n;i++) printf("%d %d\n",i,0);
		return 0;
	}
	cout<<n-2<<endl;
	if(dif==0)
	{
		int C=a[st[1]].col;
		for(int i=1;i<=n;i++) if(a[i].col!=C)
		{
			for(int j=1;j<tp;j++) solve(a[i],a[st[j]],a[st[j+1]]);
			solve(a[i],a[st[1]],a[st[tp]]);
			for(int j=1;j<tp;j++) printf("%d %d\n",a[st[j]].id,a[st[j+1]].id);
			break;
		}
	}
	else
	{
		// for(int i=1;i<=tp;i++) printf("%d%c",a[st[i]].id," \n"[i==tp]);
		int dpos=0;
		for(int i=1;i<tp;i++) if(a[st[i]].col!=a[st[i+1]].col) dpos=i+1;
		memcpy(tmp,st,sizeof(tmp)); int cnt=0;
		for(int i=dpos;i<=tp;i++) st[++cnt]=tmp[i];
		for(int i=1;i<dpos;i++) st[++cnt]=tmp[i];
		for(int i=1;i<tp;i++) if(a[st[i]].col!=a[st[i+1]].col) dpos=i;
		// for(int i=1;i<=tp;i++) printf("%d%c",a[st[i]].id," \n"[i==tp]);
		// cout<<dpos<<endl;
		for(int i=dpos+1;i<tp;i++) solve(a[st[1]],a[st[i]],a[st[i+1]]);
		for(int i=1;i<dpos;i++) solve(a[st[dpos+1]],a[st[i]],a[st[i+1]]);
		for(int i=1;i<dpos;i++) printf("%d %d\n",a[st[i]].id,a[st[i+1]].id);
		for(int i=dpos+1;i<tp;i++) printf("%d %d\n",a[st[i]].id,a[st[i+1]].id);
	}
	return 0;
}