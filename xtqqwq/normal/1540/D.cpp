#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,blo;
int bl[100005],lf[705],rg[705],pl[100005],a[100005],num[100005],pre[100005];

struct bit{
	int tp,timer;
	int mark[100005],val[100005];
	void add(int x){
		for(;x<=n;x+=(x&(-x))){
			if(mark[x]!=timer) mark[x]=timer,val[x]=0;
			val[x]++;
		}
	}
	int ask(int x){
		int now=0;
		for(int i=16;i>=0;i--){
			if(now+(1<<i)>n) continue;
			int t=min(1<<i,tp-now+1)-(mark[now|(1<<i)]==timer?val[now|(1<<i)]:0);
			if(x>t) x-=t,now+=1<<i;
		}
		return now+1;
	}
}bit[605];

void rebuild(int b){
	bit[b].timer++;
	for(int i=rg[b];i>=lf[b];i--){
		pl[i]=bit[b].ask(i-a[i]);
		bit[b].add(pl[i]);
		num[i]=pl[i];
	}
	sort(num+lf[b],num+rg[b]+1);
	pre[lf[b]]=num[lf[b]]-1;
	for(int i=lf[b]+1;i<=rg[b];i++) pre[i]=pre[i-1]+num[i]-num[i-1]-1;
}

void init(){
	blo=170;
	for(int i=1;i<=n;i+=blo) lf[++m]=i,rg[m]=min(i+blo-1,n);
	for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
	for(int i=1;i<=m;i++) bit[i].tp=rg[i];
	for(int i=1;i<=m;i++) rebuild(i);
}

void change(int x,int y){
	a[x]=y;
	rebuild(bl[x]);
}

int query(int x){
	int now=pl[x];
	for(int i=bl[x]+1;i<=m;i++) now+=lower_bound(pre+lf[i],pre+rg[i]+1,now)-pre-lf[i];
	return now;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	init();
	int opt,x;
	q=readint();
	while(q--){
		opt=readint(); x=readint();
		if(opt==1) change(x,readint());
		else printf("%d\n",query(x));
	}
	return 0;
}