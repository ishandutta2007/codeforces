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
const int N=1000005;
int n,m;
vector<pii> vc[N];
vector<pii> vq[N];
int t[N];
ll p,e;
void change(int x,int v){
	for (;x<N;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
void INSX(int lx,int rx,int y){
	vc[lx].PB(pii(y+1,1));
	vc[rx+1].PB(pii(y+1,-1));
}
void INSY(int ly,int ry,int x){
	vq[x].PB(pii(ly+1,ry+1));
}
int main(){
	scanf("%d%d",&n,&m);
	INSX(0,1e6,0);
	INSX(0,1e6,1e6);
	INSY(0,1e6,0);
	INSY(0,1e6,1e6);
	For(i,1,n){
		int lx,rx,y;
		scanf("%d%d%d",&y,&lx,&rx);
		INSX(lx,rx,y);
	}
	For(i,1,m){
		int ly,ry,x;
		scanf("%d%d%d",&x,&ly,&ry);
		INSY(ly,ry,x);
	}
	p=2*(n+m+4);
	e=n+m+4;
	For(i,0,N-1){
		for (auto j:vc[i])
			change(j.fi,j.se);
		for (auto j:vq[i]){
			int val=ask(j.se)-ask(j.fi-1);
			p+=val; e+=val*2;
			//cout<<val<<endl;
		}
	}
	//cout<<p<<' '<<e<<endl;
	printf("%lld\n",e-p+1);
}