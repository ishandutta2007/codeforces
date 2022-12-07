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
int n,m,deg[N],fa[N];
ll val[N],v[N],dif[N];
struct ZKW{
	ll mn[N*4],mx[N*4];
	int nn;
	void build(int n){
		for (nn=1;nn<=n+1;nn<<=1);
		For(i,0,2*nn-1)	mn[i]=1ll<<60,mx[i]=-(1ll<<60);
	}
	void change(int x,ll v1,ll v2){
		x+=nn;
		mn[x]=v1; mx[x]=v2;
		for (x>>=1;x;x>>=1){
			mn[x]=min(mn[x<<1],mn[x<<1|1]);
			mx[x]=max(mx[x<<1],mx[x<<1|1]);
		}
	}
}ANS;
struct HEAP{
	priority_queue<pll> Q1,Q2,Q3,Q4;
	void push(int x){
		Q1.push(pll(val[x],x));
		Q3.push(pll(-val[x],x));
	}
	void erase(int x){
		Q2.push(pll(val[x],x));
		Q4.push(pll(-val[x],x));
	}
	ll askmx(){
		for (;!Q1.empty()&&!Q2.empty()&&Q1.top()==Q2.top();) Q1.pop(),Q2.pop();
		return Q1.empty()?-(1ll<<60):Q1.top().fi;
	}
	ll askmn(){
		for (;!Q3.empty()&&!Q4.empty()&&Q3.top()==Q4.top();) Q3.pop(),Q4.pop();
		return Q3.empty()?1ll<<60:-Q3.top().fi;
	}
}Q[N];
void update(int x){
	ANS.change(x,Q[x].askmn()+dif[x],Q[x].askmx()+dif[x]);
}
void erase(int x){
	int y=fa[x],z=fa[y];
	Q[y].erase(x);
	Q[z].erase(y);
	Q[fa[z]].erase(z);
	val[z]-=dif[y]; val[y]-=dif[x];
	val[y]-=v[y]-dif[y]*(deg[y]-1);
	val[x]-=v[x]-dif[x]*(deg[x]-1);
	--deg[x]; --deg[y];
	dif[x]=v[x]/deg[x];
	dif[y]=v[y]/deg[y];
	val[y]+=v[y]-dif[y]*(deg[y]-1);
	val[x]+=v[x]-dif[x]*(deg[x]-1);
	val[z]+=dif[y];
	Q[z].push(y);
	Q[fa[z]].push(z);
	update(x);
	update(y);
	update(z);
	update(fa[z]);
}
void insert(int x){
	int y=fa[x],z=fa[y];
	Q[z].erase(y);
	Q[fa[z]].erase(z);
	val[z]-=dif[y];
	val[y]-=v[y]-dif[y]*(deg[y]-1);
	val[x]-=v[x]-dif[x]*(deg[x]-1);
	++deg[x]; ++deg[y];
	dif[x]=v[x]/deg[x];
	dif[y]=v[y]/deg[y];
	val[y]+=v[y]-dif[y]*(deg[y]-1);
	val[x]+=v[x]-dif[x]*(deg[x]-1);
	val[z]+=dif[y]; val[y]+=dif[x];
	Q[y].push(x);
	Q[z].push(y);
	Q[fa[z]].push(z);
	update(x);
	update(y);
	update(z);
	update(fa[z]);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,1,n) deg[i]=2;
	For(i,1,n) scanf("%lld",&v[i]);
	For(i,1,n) scanf("%d",&fa[i]),++deg[fa[i]];
	For(i,1,n){
		val[i]+=v[i]-v[i]/deg[i]*(deg[i]-1);
		val[fa[i]]+=v[i]/deg[i];
		dif[i]=v[i]/deg[i];
	}
	ANS.build(n);
	For(i,1,n) Q[fa[i]].push(i);
	For(i,1,n) update(i);
	while (m--){
		//printf("%d ",m);
		int tp,x;
		scanf("%d",&tp);
		if (tp==1){
			int x;
			scanf("%d",&x);
			erase(x);
			scanf("%d",&fa[x]);
			insert(x);
		}
		else if (tp==2){
			scanf("%d",&x);
			printf("%lld\n",val[x]+dif[fa[x]]);
		}
		else
			printf("%lld %lld\n",ANS.mn[1],ANS.mx[1]);
	}
}
/*



*/