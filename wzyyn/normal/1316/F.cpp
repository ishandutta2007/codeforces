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
const int mo=1000000007;
const int N=300005;
int RP(){
	int x=0;
	For(i,1,9)
		x=x*10+rand()%10;
	return x;
}
struct node{
	int p,pl,pr,sum;
}t[N],v[N];
int ls[N],rs[N],rp[N];
int a[N],fa[N],n,rt,Q;
node operator +(node a,node b){
	node ans;
	ans.p=1ll*a.p*b.p%mo;
	ans.pl=(a.pl+1ll*a.p*b.pl)%mo;
	ans.pr=(b.pr+1ll*b.p*a.pr)%mo;
	ans.sum=(a.sum+b.sum+1ll*a.pr*b.pl)%mo;
	return ans; 
}
void pushup(int x){
	v[x]=t[x];
	if (ls[x]) fa[ls[x]]=x,v[x]=v[ls[x]]+v[x];
	if (rs[x]) fa[rs[x]]=x,v[x]=v[x]+v[rs[x]];
}
void init(int x,int val){
	t[x].p=(mo+1)/2;
	t[x].pl=1ll*(mo+1)/2*val%mo;
	t[x].pr=1ll*(mo+1)/2*val%mo;
	t[x].sum=0;
	pushup(x);
}
pii split(int k,pii val){
	if (!k) return pii(0,0);
	if (pii(a[k],k)<=val){
		pii ans=split(rs[k],val);
		rs[k]=ans.fi; ans.fi=k;
		pushup(k); return ans;
	}
	else{
		pii ans=split(ls[k],val);
		ls[k]=ans.se; ans.se=k;
		pushup(k); return ans;
	} 
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
void output(int k){
	if (!k) return;
	printf("YYN! %d %d %d %d\n",k,ls[k],rs[k],fa[k]);
	output(ls[k]); output(rs[k]);
}
void Erase(int id){
	int x=merge(ls[id],rs[id]);
	if (id==rt) rt=x;
	else{
		if (ls[fa[id]]==id)
			ls[fa[id]]=x;
		else rs[fa[id]]=x;
		for (x=fa[id];;x=fa[x]){
			pushup(x);
			if (x==rt) break;
		}
	}
	ls[id]=rs[id]=fa[id]=0;
	//output(rt);
}
void Insert(int id){
	pii tmp=split(rt,pii(a[id],id-1));
	rt=merge(merge(tmp.fi,id),tmp.se);
	//output(rt);
}
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		rp[i]=RP();
		init(i,a[i]);
		Insert(i);
	}
	printf("%d\n",v[rt].sum);
	scanf("%d",&Q);
	while (Q--){
		int x;
		scanf("%d",&x);
		Erase(x);
		scanf("%d",&a[x]);
		init(x,a[x]);
		Insert(x);
		printf("%d\n",v[rt].sum);
	}
}
/*
 


 
*/