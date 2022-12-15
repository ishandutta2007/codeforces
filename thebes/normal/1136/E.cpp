#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 1e5+5;
ll N, Q, arr[MN], k[MN], i, j, x, y;
set<int> heh; char ch;

struct segtree{
	ll st[3*MN], n;
	void build(int _n){n=_n;}
	void upd(int i,int s,int e,int ind,ll val){
		if(s!=e){
			if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind,val);
			else upd(2*i,s,(s+e)/2,ind,val);
			st[i]=st[2*i]+st[2*i+1];
		}
		else st[i]=val;
	}
	inline void upd(int i,ll val){
		upd(1,1,n,i,val);
	}
	ll qu(int i,int s,int e,int ss,int se){
		if(s>=ss&&e<=se) return st[i];
		else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
		else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
		else return qu(2*i,s,(s+e)/2,ss,se)+qu(2*i+1,(s+e)/2+1,e,ss,se);
	}
	inline ll qu(int s,int e){
		if(s>e) return 0;
		return qu(1,1,n,s,e);
	}
}st, st2;

inline void upd(int x){
	st.upd(x, arr[x]+k[x]);
	st2.upd(x, -1LL*x*(arr[x]+k[x]));
}

inline ll query(ll x){
	if(!x) return 0;
	ll sm = st.qu(1,x);
	return sm*(x+1)+st2.qu(1,x);
}

int main(){
	scanf("%lld",&N);
	st.build(N); st2.build(N);
	for(i=1;i<=N;i++){
		scanf("%lld",&arr[i]);
	}
	for(i=2;i<=N;i++){
		scanf("%lld",&k[i]);
	}
	for(i=N;i>=1;i--){
		arr[i]-=k[i]+arr[i-1]; upd(i);
		if(arr[i]>0) heh.insert(i);
	}
	for(scanf("%lld",&Q);Q;Q--){
		scanf(" %c%lld%lld",&ch,&x,&y);
		if(ch=='s') printf("%lld\n",query(y)-query(x-1));
		else{
			arr[x]+=y; heh.insert(x);
			upd(x);
			auto it=heh.upper_bound(x);
			while(it!=heh.end()&&y){
				ll r = min(arr[*it],y);
				y-=r; arr[*it]-=r;
				upd(*it);
				auto it2=it; it++;
				if(!arr[*it2]) heh.erase(it2);
			}
		}
	}
	return 0;
}