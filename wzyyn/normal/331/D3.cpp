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
const int N=200005,T=51;
int sgn(int x){
	return x?(x>0?1:-1):0;
}
struct arrow *null;
struct arrow{
	int sx,sy,tx,ty,dx,dy;
	arrow *to[T];
	ll dis[T];
	arrow(){
		to[0]=NULL;
	}
	void init(){
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		dx=sgn(tx-sx); dy=sgn(ty-sy);
		//cout<<dx<<' '<<dy<<' '<<sx<<' '<<tx<<endl;
	}
	void init2(){
		char c;
		scanf("%d%d %c",&sx,&sy,&c);
		tx=sx; ty=sy;
		if (c=='L') dx--;
		if (c=='R') dx++;
		if (c=='U') dy++;
		if (c=='D') dy--;
	}
}a[N];
int id[N];
int n,B,Q;
ll lim[N];
bool cmpx0(int x,int y){
	return min(a[x].sx,a[x].tx)>min(a[y].sx,a[y].tx);
}
bool cmpx1(int x,int y){
	return max(a[x].sx,a[x].tx)<max(a[y].sx,a[y].tx);
}
bool cmpy0(int x,int y){
	return min(a[x].sy,a[x].ty)>min(a[y].sy,a[y].ty);
}
bool cmpy1(int x,int y){
	return max(a[x].sy,a[x].ty)<max(a[y].sy,a[y].ty);
}
void solve(int dx,int dy,bool (*cmp)(int,int)){
	For(i,1,n+Q) id[i]=n+Q+1-i;
	stable_sort(id+1,id+n+Q+1,cmp);
	multimap<int,arrow*> S;
	S.clear();
	For(i,1,n+Q){
		if (id[i]<=n){
			int v1,v2;
			if (dy!=0) v1=a[id[i]].sx,v2=a[id[i]].tx;
			else v1=a[id[i]].sy,v2=a[id[i]].ty;
			if (v1>v2) swap(v1,v2);
			//cout<<id[i]<<' '<<v1<<' '<<v2<<' '<<a[id[i]].sy<<endl; 
			auto lo=S.lower_bound(v1);
			auto hi=S.upper_bound(v2);
			for (auto it=lo;it!=hi;S.erase(it++)){
				arrow *ia=it->se;
				ia->to[0]=a+id[i];
				ia->dis[0]=abs(ia->tx-a[id[i]].tx)+
						   abs(ia->ty-a[id[i]].ty);
			}
		}
		if (a[id[i]].dx==dx&&a[id[i]].dy==dy)
			S.insert(make_pair(dx?a[id[i]].ty:a[id[i]].tx,a+id[i]));
	}
	for (auto i:S){
		i.se->to[0]=null;
		i.se->dis[0]=1ll<<60;
	}
}
int main(){
	//freopen("1.in","r",stdin);
	null=a;
	scanf("%d%d",&n,&B);
	For(i,1,n) a[i].init();
	scanf("%d",&Q);
	For(i,1,Q){
		a[i+n].init2();
		scanf("%lld",&lim[i]);
	}
	solve(-1,0,cmpx0);
	solve( 1,0,cmpx1);
	solve(0,-1,cmpy0);
	solve(0, 1,cmpy1);
	null->to[0]=null;
	//For(j,1,n)
	//	printf("%d %d %d %d\n",a[j].sx,a[j].sy,a[j].tx,a[j].ty);
	For(j,0,n+Q){
		///cout<<j<<endl;
		//cout<<j<<' '<<(a[j].to[0]-a)<<' '<<a[j].dis[0]<<endl;
		assert(a[j].to[0]!=NULL);
	}
	For(i,1,T-1) For(j,0,n+Q){
		a[j].to[i]=a[j].to[i-1]->to[i-1];
		a[j].dis[i]=min(1ll<<60,a[j].dis[i-1]+a[j].to[i-1]->dis[i-1]);
	}
	//cout<<233<<endl;
	For(i,1,Q){
		arrow* x=a+n+i;
		//cout<<(x-a)<<endl;
		Rep(j,T-1,0)
			if (x->dis[j]<=lim[i])
				lim[i]-=x->dis[j],x=x->to[j];
		//cout<<(x-a)<<endl;
		if (x->to[0]!=null&&lim[i]>=x->dx*(x->to[0]->tx-x->tx)+
									x->dy*(x->to[0]->ty-x->ty))
			lim[i]-=x->dis[0],x=x->to[0];
		printf("%lld %lld\n",min(max(x->tx+x->dx*lim[i],0ll),1ll*B),
							 min(max(x->ty+x->dy*lim[i],0ll),1ll*B));
	}
}