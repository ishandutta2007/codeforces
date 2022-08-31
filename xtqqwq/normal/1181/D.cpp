#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int ch[2],siz,val,rnd;
}t[500005];

int n,m,q,rt;
int cnt[500005],ans[500005];
pll k[500005];
vector<int> v[500005];

unsigned int rnd(){
	static int seed=19260817;
	return (unsigned int)(seed*=48271ll);
}

void update(int x){t[x].siz=1+t[t[x].ch[0]].siz+t[t[x].ch[1]].siz;}

void rotate(int &x,int d){
	int son=t[x].ch[d];
	t[x].ch[d]=t[son].ch[d^1];
	t[son].ch[d^1]=x; update(x); update(x=son);
}

void insert(int &x,int val){
	if(!x){
		x=val;
		return;
	}
	t[x].siz++;
	int d=t[x].val<val;
	insert(t[x].ch[d],val);
	if(t[x].rnd>t[t[x].ch[d]].rnd) rotate(x,d);
}

int kth(int rt,int k){
	int x=rt;
	while(1){
		if(k<=t[t[x].ch[0]].siz) x=t[x].ch[0];
		else if(k>t[t[x].ch[0]].siz+1) k-=t[t[x].ch[0]].siz+1,x=t[x].ch[1];
		else return t[x].val;
	}
}

int main(){
	m=readint(); n=readint(); q=readint();
	for(int i=1;i<=m;i++) cnt[readint()]++;
	for(int i=1;i<=n;i++) v[cnt[i]].push_back(i);
	for(int i=1;i<=n;i++) t[i].siz=1,t[i].val=i,t[i].rnd=rnd();
	for(int i=1;i<=q;i++) k[i]=mp(readint()-m,i);
	sort(k+1,k+q+1);
	int pl=1,a,b; ll sum=0;
	for(int i=0;i<=m;i++){
		for(auto x:v[i]) insert(rt,x);
		while(pl<=q&&k[pl].fi-sum<=t[rt].siz){
			ans[k[pl].se]=kth(rt,k[pl].fi-sum);
			pl++;
		}
		sum+=t[rt].siz;
	}
	while(pl<=q){
		ans[k[pl].se]=(k[pl].fi-sum-1)%n+1;
		pl++;
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}