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
const int M=3000005;
int n,Q,top;
ll dep[N];
pll opt[M];
namespace LCT{
	int fa[N],cov[N],tag[N],ch[N][2];
	bool isroot(int x){
		return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
	}
	void pushdown(int x){
		if (!tag[x]) return;
		if (ch[x][0]) cov[ch[x][0]]=tag[ch[x][0]]=cov[x];
		if (ch[x][1]) cov[ch[x][1]]=tag[ch[x][1]]=cov[x];
		tag[x]=0;
	}
	void Down(int x){
		if (!isroot(x)) Down(fa[x]);
		pushdown(x);
	}
	void rotate(int x){
		int y=fa[x],z=fa[y];
		int l=(ch[y][1]==x),r=l^1;
		if (!isroot(y)) ch[z][ch[z][1]==y]=x;
		fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
		ch[y][l]=ch[x][r]; ch[x][r]=y;
	}
	void splay(int x){
		Down(x);
		for (;!isroot(x);rotate(x)){
			int y=fa[x],z=fa[y];
			if (!isroot(y)) rotate((ch[y][0]==x)^(ch[z][0]==y)?x:y);
		}
	}
	void access(int x,int T){
		int fir=0;	
		//cout<<"access "<<x<<' '<<fa[x]<<' '<<T<<endl;
		for (int y=0;x;y=x,x=fa[x]){
			splay(x);
			if (!fir){
				fir=1;
				if (ch[x][0]&&T!=-1)
					cov[ch[x][0]]=tag[ch[x][0]]=T;
				continue;
			}
			if (T!=-1){
				ll tl=(cov[x]?cov[x]+dep[x]+1:1);
				ll tr=dep[x]+T;
				//cout<<"ins "<<tl<<' '<<tr<<' '<<x<<' '<<dep[x]<<' '<<T<<' '<<cov[x]<<endl;
				opt[++top]=pll(tl,tr);
				cov[x]=T;
				if (ch[x][0]&&T!=-1)
					cov[ch[x][0]]=tag[ch[x][0]]=T;
			}
			ch[x][1]=y;
		}
	}
}
vector<pii> e[N];
multiset<ll> S;
void dfs(int x){
	LCT::access(x,-1);
	for (auto i:e[x])
		dep[i.fi]=dep[x]+i.se,dfs(i.fi);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].PB(pii(y,v));
		LCT::fa[y]=x;
	}
	dfs(1);
	For(i,1,Q){
		int x,T;
		scanf("%d%d",&x,&T);
		LCT::access(x,T);
	}
	sort(opt+1,opt+top+1);
	ll nowT=0;
	int pos=1;
	for (;;){
		++nowT;
		for (;opt[pos].fi<=nowT&&pos<=top;++pos)
			S.insert(opt[pos].se);
		if (!S.size()){
			if (pos>top) break;
			nowT=opt[pos].fi-1;
			continue;
		}
		if (*S.begin()<nowT){
			int sum=0;
			For(i,1,top) sum+=(opt[i].se<nowT-1);
			printf("%lld %d\n",nowT-1,sum);
			return 0;
		}
		S.erase(S.begin());
	}
	printf("-1 %d\n",top);
}