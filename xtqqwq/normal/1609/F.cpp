// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,val;
	bool knd,tp;
	node(bool tp=0,bool knd=0,int l=0,int r=0,int val=0):tp(tp),knd(knd),l(l),r(r),val(val){}
};

int n,top1,top2,cnt;
int stk1[1000005],stk2[1000005],b[1000005];
ll a[1000005];

struct bit{
	struct BIT{
		int timer;
		int val[1000005];
		void add(int x,ll c){
			for(;x<=n;x+=(x&(-x))){
				// if(mark[x]!=timer) mark[x]=timer,val[x]=0;
				val[x]+=c;
			}
		}
		ll ask(int x){
			ll ret=0;
			for(;x;x-=(x&(-x))){
				// if(mark[x]!=timer) mark[x]=timer,val[x]=0;
				ret+=val[x];
			}
			return ret;
		}
	}bit[2];
	void change(int l,int r,ll x){
		bit[0].add(l,x),bit[0].add(r+1,-x);
		bit[1].add(l,l*x),bit[1].add(r+1,-(r+1)*x);
	}
	ll sum(int x){
		return (x+1)*bit[0].ask(x)-bit[1].ask(x);
	}
}T[2];

vector<node> vec[65];

int main(){
 	n=readint();
	for(int i=1;i<=n;i++){
 		a[i]=readint();
		b[i]=__builtin_popcountll(a[i]);
	}
	for(int i=1;i<=n;i++){
		while(top1&&a[i]>=a[stk1[top1]]){
			int j=stk1[top1];
			vec[b[j]].pb(node(1,1,stk1[top1-1]+1,j,-(n-i+1)));
			vec[b[j]].pb(node(0,0,stk1[top1-1]+1,j,-1));
			top1--;
		}
		vec[b[i]].pb(node(1,1,stk1[top1]+1,i,n-i+1));
		vec[b[i]].pb(node(0,0,stk1[top1]+1,i,1));
		stk1[++top1]=i;
		while(top2&&a[i]<=a[stk2[top2]]){
			int j=stk2[top2];
			vec[b[j]].pb(node(1,0,stk2[top2-1]+1,j,-(n-i+1)));
			vec[b[j]].pb(node(0,1,stk2[top2-1]+1,j,-1));
			top2--;
		}
		vec[b[i]].pb(node(1,0,stk2[top2]+1,i,n-i+1));
		vec[b[i]].pb(node(0,1,stk2[top2]+1,i,1));
		stk2[++top2]=i;
	}
	ll ans=0;
	for(int i=0;i<=60;i++){
	    for(int j=0;j<2;j++)
	        for(int k=0;k<2;k++)
	            for(int l=0;l<=n;l++)
	                T[j].bit[k].val[l]=0;
		for(auto r:vec[i]){
			if(r.tp==1) ans+=r.val*(T[r.knd].sum(r.r)-T[r.knd].sum(r.l-1));
			else T[r.knd].change(r.l,r.r,r.val);
		}
	}
	printf("%lld\n",ans);
	return 0;
}