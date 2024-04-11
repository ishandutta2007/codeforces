#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
struct frac{
	ll x,y;
	bool operator <(const frac &a)const{
		return 1ll*x*a.y<1ll*y*a.x;
	}
};
priority_queue<pii> Q[4][N];
int k,n,m,nn;
int mx[N*4],type[N];
frac val[N*2];
ll a[N],b[N];
vector<int> Q1,Q2,Q3;
int Mx(int x,int y){
	return val[x]<val[y]?y:x;
}
void build(int n){
	for (nn=1;nn<=n+1;nn<<=1);
	For(i,0,nn-1) val[i]=(frac){0,1},mx[i+nn]=i;
	Rep(i,nn-1,1) mx[i]=Mx(mx[i*2],mx[i*2+1]);
}
void update(int x){
	val[x]=(frac){0,1};
	frac tmp;
	if (Q[1][x].empty()) tmp=(frac){0,1};
	else tmp=(frac){Q[1][x].top().fi-a[x],b[x]};
	if (!(tmp<val[x])) val[x]=tmp,type[x]=1;
	
	if (Q[2][x].empty()) tmp=(frac){0,1};
	else tmp=(frac){Q[2][x].top().fi,b[x]};
	if (!(tmp<val[x])) val[x]=tmp,type[x]=2;
	
	if (Q[3][x].empty()) tmp=(frac){0,1};
	else tmp=(frac){Q[3][x].top().fi-1,1};
	if (!(tmp<val[x])) val[x]=tmp,type[x]=3;
	
	for (x=(x+nn)>>1;x;x>>=1)
		mx[x]=Mx(mx[x*2],mx[x*2+1]);
}
int main(){
	scanf("%d%d%d",&k,&n,&m);
	For(i,1,k) scanf("%lld",&a[i]),b[i]=a[i];
	For(i,1,n){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		Q[x][y].push(pii(v,i));
	}
	build(k);
	For(i,1,k) update(i);
	For(i,1,m){
		frac tmp=val[mx[1]];
		//printf("%d %d %d\n",tmp.x,tmp.y,mx[1]);
		if (!((frac){0,1}<tmp)) break;
		int x=mx[1];
		if (type[x]==1){
			Q1.PB(Q[1][x].top().se);
			int v=Q[1][x].top().fi-a[x];
			a[x]+=v; b[x]+=v;
			Q[1][x].pop();
			update(x);
		}
		else if (type[x]==2){
			Q2.PB(Q[2][x].top().se);
			b[x]+=Q[2][x].top().fi;
			Q[2][x].pop();
			update(x);
		}
		else{
			Q3.PB(Q[3][x].top().se);
			Q[3][x].pop();
			update(x);
		}
	}
	printf("%d\n",Q1.size()+Q2.size()+Q3.size());
	For(i,0,Q1.size()-1) printf("%d ",Q1[i]);
	For(i,0,Q2.size()-1) printf("%d ",Q2[i]);
	For(i,0,Q3.size()-1) printf("%d ",Q3[i]);
}