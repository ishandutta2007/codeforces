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
const int N=1000005;
struct TR1{
	int fa[N],id[N],v[N],n;
	void init(int _n){
		n=_n;
		For(i,1,n) fa[i]=id[i]=i;
	}
	int get(int x){
		if (x==fa[x]) return x;
		int tmp=get(fa[x]);
		v[x]=max(v[x],v[fa[x]]);
		return fa[x]=tmp;
	}
	void merge(int x,int y){
		int tmp=x;
		x=id[x]; y=id[y];
		fa[x]=fa[y]=++n;
		fa[n]=id[tmp]=n;
	}
	void change(int x,int T){
		v[id[x]]=T;
	}
	int ask(int x){
		get(x);
		return v[x];
	}
}T1;
struct TR2{
	int fa[N],id[N],sz[N],n;
	ll v[N];
	void init(int _n){
		n=_n;
		For(i,1,n){
			fa[i]=id[i]=i;
			sz[i]=1;
		}
	}
	int get(int x){
		if (x==fa[x]) return x;
		int tmp=get(fa[x]);
		if (tmp!=fa[x]) v[x]+=v[fa[x]];
		return fa[x]=tmp;
	}
	void merge(int x,int y){
		int tmp=x;
		x=id[x]; y=id[y];
		fa[x]=fa[y]=++n;
		sz[n]=sz[x]+sz[y];
		fa[n]=id[tmp]=n;
	}
	void update(int x){
		x=id[x];
		v[x]+=sz[x];
	}
	ll ask(int x){
		int y=get(x);
		return v[x]+(y==x?0:v[y]);
	}
}T2;
struct query{
	int tp,x,y,v,id;
	bool operator <(const query &a)const{
		return v==a.v?tp<a.tp:v<a.v;
	}
}q[N];
int n,Q,top;
ll ans[N];
int main(){
	scanf("%d%d",&n,&Q);
	T1.init(n);
	T2.init(n);
	For(i,1,Q){
		char s[5];
		int x,y;
		scanf("%s%d",s,&x);
		if (s[0]=='U'){
			scanf("%d",&y);
			q[++top]=(query){1,x,y,i};
		}
		if (s[0]=='M'){
			scanf("%d",&y);
			T1.merge(x,y);
		}
		if (s[0]=='A')
			q[++top]=(query){2,x,0,i};
		if (s[0]=='Z')
			T1.change(x,i);
		if (s[0]=='Q'){
			++*ans;
			q[++top]=(query){3,int(*ans),-1,T1.ask(x),x};
			q[++top]=(query){3,int(*ans),1,i,x};
		}
	}
	sort(q+1,q+top+1);
	For(i,1,top)
		if (q[i].tp==1)
			T2.merge(q[i].x,q[i].y);
		else if (q[i].tp==2)
			T2.update(q[i].x);
		else ans[q[i].x]+=q[i].y*T2.ask(q[i].id);
	For(i,1,*ans)
		printf("%lld\n",ans[i]);
}