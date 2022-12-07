#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=205;
int n;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
}p[N];
int vis[N][N],top;
vector<int> id[N],vec[N*N];
struct Mat{
	double a[N][N];
	Mat(){
		memset(a,0,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat ans;
		For(i,1,n) For(j,1,n) For(k,1,n)
			ans.a[i][k]+=a[i][j]*b.a[j][k];
		return ans;
	}
}B[15];
double f[N],g[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	For(i,1,n) For(j,i+1,n) if (!vis[i][j]){
		++top;
		For(k,1,n)
			if ((p[i]-p[k])*(p[j]-p[k])==0)
				vec[top].PB(k);
		for (auto p1:vec[top]) id[p1].PB(top);
		for (auto p1:vec[top])
			for (auto p2:vec[top])
				vis[p1][p2]=1;
	}
	For(i,1,n)
		for (auto j:id[i]){
			double tmp=1.0/id[i].size()/vec[j].size();
			for (auto k:vec[j]) B[0].a[i][k]+=tmp;
		}
	For(i,1,13) B[i]=B[i-1]*B[i-1];
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int p,T;
		scanf("%d%d",&p,&T);
		memset(f,0,sizeof(f));
		f[p]=1; --T;
		For(i,0,13) if (T&(1<<i)){
			memset(g,0,sizeof(g));
			For(j,1,n) For(k,1,n)
				g[k]+=f[j]*B[i].a[k][j];
			memcpy(f,g,sizeof(f));
		}
		double ans=0;
		For(i,1,top){
			double tmp=0;
			for (auto j:vec[i]) tmp+=f[j];
			tmp/=vec[i].size();
			ans=max(ans,tmp);
		}
		printf("%.10lf\n",ans);
	}
}