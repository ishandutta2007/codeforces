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

const int INF=(1<<30)-1;
const int N=8000005;
int ls[N],rs[N],nd,n,Ban;
ll tg[N],mn[N];

void add(int k,ll v){
	assert(k!=0);
	tg[k]+=v;
	mn[k]+=v;
}
void pushdown(int k){
	if (!tg[k]) return;
	if (ls[k]) add(ls[k],tg[k]);
	if (rs[k]) add(rs[k],tg[k]);
	tg[k]=0;
}
void pushup(int k){
	mn[k]=min(mn[ls[k]],mn[rs[k]]);
}
void insert(int &k,int l,int r,int p,ll v){
	if (!k) k=++nd;
	if (l==r){
		mn[k]=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	if (p<=mid) insert(ls[k],l,mid,p,v);
	else insert(rs[k],mid+1,r,p,v);
	pushup(k);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	pushdown(x);
	pushdown(y);
	mn[x]=min(mn[x],mn[y]);
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return x;	
}
ll ask(int k,int l,int r,int p){
	if (l==r||!k) return mn[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) return ask(ls[k],l,mid,p);
	return ask(rs[k],mid+1,r,p);
}
int solve(int idx,ll val){
	int rt=0;
	insert(rt,0,INF,idx,val);
	char s[5];
	while (n--){
		scanf("%s",s+1);
		if (s[1]=='s'){
			int y,v;
			scanf("%d%d",&y,&v);
			ll val=mn[rt];
			add(rt,v);
			if (y!=Ban)
				insert(rt,0,INF,y,val);
		}
		else if (s[1]=='e')
			return rt;
		else{
			int y;
			scanf("%d",&y);
			int rt2=solve(y,ask(rt,0,INF,y));
			insert(rt,0,INF,y,1ll*INF*INF);
			rt=merge(rt,rt2);
		}
		//cout<<"N "<<' '<<n<<' '<<mn[rt]<<endl; 
	}
	return rt;
}
int main(){
	memset(mn,60,sizeof(mn));
	scanf("%d%d",&n,&Ban);
	int idx=solve(0,0);
	printf("%lld\n",mn[idx]);
}