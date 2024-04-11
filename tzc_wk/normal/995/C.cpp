/*
Contest: -
Problem: Codeforces 995C
Author: tzc_wk
Time: 2020.10.16
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
const double pi=acos(-1);
inline double cross(double x1,double y1,double x2,double y2){
	return x1*x2+y1*y2;
}
inline double len(double x,double y){
	return sqrt(x*x+y*y);
}
inline double angle(double x1,double y1,double x2,double y2){
	if(x1==0&&y1==0) return pi;
	if(x2==0&&y2==0) return pi;
	return acos(cross(x1,y1,x2,y2)/len(x1,y1)/len(x2,y2));
}
int n,x[100005],y[100005],cur=0;
struct data{
	double tx,ty;
	int fx,fy;
	int cx,cy;
	data operator ~(){
		data ans=*this;
		ans.tx=-ans.tx;ans.ty=-ans.ty;
		ans.cx=-ans.cx;ans.cy=-ans.cy;
		return ans;
	}
} d[100005<<5];
inline data add(int x,int y,int cx,int cy){
	data ans;
	ans.tx=d[x].tx*cx+d[y].tx*cy;
	ans.ty=d[x].ty*cx+d[y].ty*cy;
	ans.cx=cx;ans.cy=cy;
	ans.fx=x;ans.fy=y;
	return ans;
}
int neg[100005<<5];
inline void dump(int x){
	if(x<=n) return;
//	printf("%d %d %d\n",x,d[x].fx,d[x].fy);
	neg[d[x].fx]=neg[x]*d[x].cx;
	neg[d[x].fy]=neg[x]*d[x].cy;
	dump(d[x].fx);dump(d[x].fy);
}
inline void dfs(int x,int y,int z,int w){
	if(z==n+1){
		d[++cur]=~d[x];d[++cur]=~d[y];
		vector<int> t;t.pb(x);t.pb(y);t.pb(cur-1);t.pb(cur);
		for(int i=0;i<4;i+=2) for(int j=1;j<4;j+=2){
			int u=t[i],v=t[j];
			if(len(d[u].tx+d[v].tx,d[u].ty+d[v].ty)<=1500000.0){
				if(i==2) neg[x]=-1;else neg[x]=1;
				if(j==3) neg[y]=-1;else neg[y]=1;
				dump(x);dump(y);return;
			}
		}
	}
	d[++cur]=~d[x];d[++cur]=~d[y];d[++cur]=~d[z];
	vector<int> t;t.pb(x);t.pb(y);t.pb(z);
	t.pb(cur-2);t.pb(cur-1);t.pb(cur);
	for(int i=0;i<6;i++) for(int j=0;j<i;j++){
		if((i%3)==(j%3)) continue;
		int a=t[i],b=t[j];
		if(angle(d[a].tx,d[a].ty,d[b].tx,d[b].ty)>=2.0*pi/3){
			d[++cur]=add(a,b,1,1);int nxt=3-(i%3)-(j%3);
//			printf("%d %d\n",a,b);
			if(nxt==0) dfs(cur,x,w,w+1);
			if(nxt==1) dfs(cur,y,w,w+1);
			if(nxt==2) dfs(cur,z,w,w+1);
			return;
		}
	}
}
int main(){
	scanf("%d",&n);if(n==1) return puts("1"),0;
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		d[i].tx=x[i];d[i].ty=y[i];
		d[i].fx=i;d[i].fy=0;
		d[i].cx=1;d[i].cy=0;
	}
	cur=n;dfs(1,2,3,4);
	for(int i=1;i<=n;i++) printf("%d ",neg[i]);
	return 0;
}