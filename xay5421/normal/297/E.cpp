#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005;
int n,a[N],b[N],L[N],R[N];
struct BIT{
	int t[N*2];
	void clear(){
		fill(t+1,t+1+n*2,0);
	}
	void upd(int k1,int k2){
		for(int i=k1;i<=n*2;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>b[i])swap(a[i],b[i]);
	}
	vector<int>id(n);
	iota(id.begin(),id.end(),1);
	
	sort(id.begin(),id.end(),[&](int lhs,int rhs){return a[lhs]>a[rhs];});
	t.clear();
	for(auto&i:id){
		L[i]+=t.qry(n*2)-t.qry(b[i]);
		t.upd(a[i],1);
	}
	
	t.clear();
	for(auto&i:id){
		R[i]+=t.qry(b[i]);
		t.upd(b[i],1);
	}
	
	reverse(id.begin(),id.end());
	t.clear();
	for(auto&i:id){
		L[i]+=t.qry(a[i]);
		t.upd(b[i],1);
	}
	
	t.clear();
	for(auto&i:id){
		L[i]+=t.qry(n*2)-t.qry(b[i]);
		t.upd(b[i],1);
	}
	
	LL ans=1LL*n*(n-1)/2*(n-2)/3;
	rep(i,1,n){
		ans-=1LL*L[i]*R[i];
	}
	LL bad=0;
	rep(i,1,n){
		bad+=1LL*(L[i]+R[i])*(n-1-L[i]-R[i]);
	}
	ans-=bad/2;
	printf("%lld\n",ans);
	return 0;
}