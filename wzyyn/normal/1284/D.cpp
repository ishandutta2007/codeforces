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
const int N=1000005;
int n,a[N],b[N],c[N],d[N],q[N];
ll t[N],val[N],ans[N];
vector<pll> vec[N];
vector<pii> Q[N];
void change(int x,ll v){
	for (;x;x-=x&(-x)) t[x]^=v;
}
ll ask(int x){
	ll ans=0;
	for (;x<=*q;x+=x&(-x)) ans^=t[x];
	return ans;
}
ll RND(){
	ll x=0;
	For(i,1,10)
		x=x*64+(rand()&63);
	return x;
}
int main(){
	srand(time(NULL));
	for (;clock()<=30;rand());
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	For(i,1,n) q[++*q]=a[i],q[++*q]=c[i],q[++*q]=b[i]+1,q[++*q]=d[i]+1;
	sort(q+1,q+*q+1);
	For(i,1,n){
		a[i]=lower_bound(q+1,q+*q+1,a[i])-q;
		b[i]=lower_bound(q+1,q+*q+1,b[i]+1)-q;
		c[i]=lower_bound(q+1,q+*q+1,c[i])-q;
		d[i]=lower_bound(q+1,q+*q+1,d[i]+1)-q;
		//printf("%d %d %d %d\n",a[i],b[i],c[i],d[i]);
	}
	For(i,1,n){
		val[i]=RND();
		vec[a[i]].PB(pll(a[i],val[i]));
		vec[b[i]].PB(pll(b[i],val[i]));
		vec[b[i]].PB(pll(b[i]-1,val[i]));
		Q[b[i]-1].PB(pii(a[i],i));
	}
	For(i,1,*q) t[i]=0;
	ll cur=0;
	For(i,1,*q){
		for (auto j:vec[i])
			if (j.fi==i) cur^=j.se;
			else change(j.fi,j.se);
		for (auto j:Q[i])
			ans[j.se]^=ask(j.fi)^cur;
	}
	//printf("%lld %lld\n",ans[1],ans[2]);
	For(i,1,*q) vec[i].resize(0);
	For(i,1,*q) Q[i].resize(0);
	For(i,1,n){
		vec[c[i]].PB(pll(c[i],val[i]));
		vec[d[i]].PB(pll(d[i],val[i]));
		vec[d[i]].PB(pll(d[i]-1,val[i]));
		Q[d[i]-1].PB(pii(c[i],i));
	}
	For(i,1,*q) t[i]=0;
	cur=0;
	For(i,1,*q){
		for (auto j:vec[i])
			if (j.fi==i) cur^=j.se;
			else change(j.fi,j.se);
		for (auto j:Q[i])
			ans[j.se]^=ask(j.fi)^cur;
	}
	For(i,1,n){
		//printf("%lld %lld\n",ans[i],val[i]);
		if (ans[i])
			return puts("NO"),0;
	}
	puts("YES");
}