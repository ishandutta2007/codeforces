#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
#define pll pair<long long,long long>
long long n,k,a[N],ans,sum[N],p[N],fsum[N];
struct node {
	long long v,num;
	bool operator<(const node &b)const{
		return v<b.v;
	}
}b[N];
pll operator+(const pll a,const pll b){
	return {a.first+b.first,a.second+b.second};
}
pll first[N],g[N];
struct BIT{
	long long ts[N];
	void init(){
		for(long long i=1;i<=n;i++)ts[i]=0;
	}
	long long ask(long long x){
		long long res=0;
		for(;x;x-=x&-x)res+=ts[x];
		return res;
	}
	void add(long long x,long long d){
		for(;x<=n;x+=x&-x)ts[x]+=d;
	}
}tr1,tr2;
struct BITI{
	long long ts[N];
	void init(){
		for(long long i=1;i<=n;i++)ts[i]=1e18;
	}
	long long ask(long long x){
		long long res=1e18;
		for(;x>=1;x-=x&-x)res=min(res,ts[x]);
		return res;
	}
	void add(long long x,long long d){
		for(;x<=n;x+=x&-x)ts[x]=min(ts[x],d);
	}
}tr3;
struct BITX{
	pll ts[N];
	void init(){
		for(long long i=1;i<=n;i++)ts[i]={-1e18,-1e18};
	}
	pll ask(long long x){
		pll res={-1e18,-1e18};
		for(;x>=1;x-=x&-x)res=max(res,ts[x]);
		return res;
	}
	void add(long long x,pll d){
		for(;x<=n;x+=x&-x)ts[x]=max(ts[x],d);
	}
}tr4,tr5;
pll check(long long mid) {
	tr1.init(),tr2.init(),tr3.init();
	pll tot={0,0};
	for(long long i=1,it=1;i<=n;i++){
		while(it<=n&&b[it].v<=b[i].v-mid) {
			// cout<<b[it].num<<" "<<b[it].v<<endl;
			tr1.add(b[it].num,b[it].v);
			tr2.add(b[it].num,1);
			tr3.add(b[it].num,b[it].num);
			it++;
		}
		long long x=b[i].num;
		g[x].second=tr2.ask(x-1);
		g[x].first=(b[i].v-mid)*g[x].second-tr1.ask(x-1);
		fsum[x]=tr3.ask(x-1)+1;
		if(b[i].v-mid>=0){
			g[x].first+=b[i].v-mid;
			fsum[x]=1;
			g[x].second++;
		}
		fsum[x]=min(fsum[x],x+1);
		tot=tot+g[x];
	}
	tr4.init(),tr5.init();
	long long cl=0;
	for(long long i=1;i<=n;i++) {
		pll t1=tr4.ask(max(fsum[i]-2,0ll)),t2=tr5.ask(min(n,n-(fsum[i]-1)+1));
		if(fsum[i]==1)t2=max(t2,{0,0});
		else t2=max(t2,{sum[i]-mid,1});
		t1.first+=sum[i]-mid;
		t1.second++;
		first[i]=max(t1,t2);
		cl=min(cl,sum[i]);
		tr4.add(i,{first[i].first-cl,first[i].second});
		tr5.add(n-i+1,first[i]);
	}
	return first[n]+tot;
}
signed main() {
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)b[i]=node{sum[i],i};
	stable_sort(b+1,b+n+1);
	long long l=-1e12,r=1e12,res=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		pll nw=check(mid);
		if(nw.second>=k)res=mid,l=mid+1;
		else r=mid-1;
	}
	pll nw=check(res);
	printf("%lld\n",nw.first+res*k);
	return 0;
}