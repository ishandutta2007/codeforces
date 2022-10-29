#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 1e6+10;

int n,q,l[N],r[N],a[N];
LL ans[N];
vector<int> ls[N];

struct BIT{
	LL t[N];
	void clear(){memset(t,0,sizeof t);}
	void add(int x,int val){
		for(;x<=n+1;x+=x&-x)t[x]+=val;
	}
	LL sum(int x){
		LL res=0;
		for(;x;x-=x&-x)res+=t[x];
		return res;
	}
}tr[2];

void solve(){
	stack<int> s;
	s.push(n+1);
	tr[0].clear();tr[1].clear();
	rep(i,1,n)ls[i].clear();
	rep(i,1,q)ls[l[i]].push_back(i);
	for(int i=n;i;--i){
		while(a[s.top()]<a[i])s.pop();
		int j=s.top();
		s.push(i);
		tr[0].add(i,-i);
		tr[0].add(j,j-1);
		tr[1].add(i,1);
		tr[1].add(j,-1);
		for(auto id:ls[i]) ans[id] = ans[id] + tr[0].sum(r[id]) + r[id]*tr[1].sum(r[id]);
	}
}

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n)scanf("%d",a+i);a[0]=a[n+1]=N;
	rep(i,1,q)scanf("%d",l+i);
	rep(i,1,q)scanf("%d",r+i);
	rep(i,1,q)ans[i]=r[i]-l[i]+1;
	solve();
	rep(i,1,q)l[i]=n+1-l[i],r[i]=n+1-r[i],swap(l[i],r[i]);
	reverse(a,a+n+2);
	solve();
	rep(i,1,q)printf("%lld ",ans[i]);
}