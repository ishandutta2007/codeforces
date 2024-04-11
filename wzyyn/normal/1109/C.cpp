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
const int N=100005;
int rnd(){
	int x=0;
	For(i,1,9)
		x=x*10+rand()%10;
	return x; 
}
struct node{
	int lT,rT,rV;
	ll dif,mn;
}t[N];
int nd,Q,rt;
int T[N],V[N],rp[N];
int ls[N],rs[N];
node operator +(node a,node b){
	node ans;
	ans.lT=a.lT; ans.rT=b.rT; ans.rV=b.rV;
	ans.dif=a.dif+b.dif+1ll*(b.lT-a.rT)*a.rV;
	ans.mn=min(a.mn,a.dif+1ll*(b.lT-a.rT)*a.rV+b.mn);
	return ans;
}
void init(int k){
	t[k].lT=t[k].rT=T[k];
	t[k].rV=V[k];
	t[k].dif=t[k].mn=0;
}
void pushup(int k){
	init(k);
	if (ls[k]) t[k]=t[ls[k]]+t[k];
	if (rs[k]) t[k]=t[k]+t[rs[k]];
}
void split(int k,int T,int &l,int &r){
	if (!k){
		l=0; r=0;
		return;
	}
	if (::T[k]<=T){
		split(rs[k],T,l,r);
		rs[k]=l; l=k;
	}
	else{
		split(ls[k],T,l,r);
		ls[k]=r; r=k;
	}
	pushup(k);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	if (rp[x]<rp[y]){
		rs[x]=merge(rs[x],y);
		pushup(x);
		return x;
	}
	else{
		ls[y]=merge(x,ls[y]);
		pushup(y);
		return y;
	}
}
void ask(int k,ll v,int rT){
	//cout<<k<<' '<<v<<' '<<rT<<' '<<ls[k]<<' '<<rs[k]<<endl;
	if (!k) return puts("-1"),void(0);
	ll dif=(rs[k]?t[rs[k]].lT:rT);
	if (t[k].mn+v>0&&1ll*t[k].rV*(rT-t[k].rT)+t[k].dif+v>0)
		return puts("-1"),void(0);
	if (ls[k])
		if (t[ls[k]].mn+v<=0||
			t[ls[k]].dif+1ll*t[ls[k]].rV*(T[k]-t[ls[k]].rT)+v<=0)
			return ask(ls[k],v,T[k]);
		else v+=t[ls[k]].dif+1ll*t[ls[k]].rV*(T[k]-t[ls[k]].rT);
	if (v+1ll*V[k]*(dif-T[k])<=0)
		return printf("%.10lf\n",T[k]+1.0*v/(-V[k])),void(0);
	else v+=1ll*V[k]*(dif-T[k]);
	//cout<<v<<endl;
	if (rs[k])
		if (t[rs[k]].mn+v<=0||
			t[rs[k]].dif+1ll*t[rs[k]].rV*(rT-t[rs[k]].rT)+v<=0)
			return ask(rs[k],v,rT);
		else v+=t[rs[k]].dif+1ll*t[rs[k]].rV*(rT-t[rs[k]].rT);
	assert(0);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&Q);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int x,y;
			rp[++nd]=rnd();
			scanf("%d%d",&T[nd],&V[nd]);
			init(nd);
			split(rt,T[nd],x,y);
			rt=merge(merge(x,nd),y);
			//cout<<rt<<' '<<t[rt].dif<<endl;
		}
		if (tp==2){
			int x,y,z,T;
			scanf("%d",&T);
			split(rt,T-1,x,y);
			split(y,T,y,z);
			rt=merge(x,z);
		}
		if (tp==3){
			int l,r,v,x,y,z;
			scanf("%d%d%d",&l,&r,&v);
			if (!v){
				printf("%d\n",l);
				continue;
			}
			split(rt,l-1,x,y);
			split(y,r,y,z);
			//cout<<x<<' '<<y<<' '<<z<<endl;
			ask(y,v,r);
			rt=merge(merge(x,y),z);
		}
	}
}