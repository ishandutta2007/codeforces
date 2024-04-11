#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define unisort(x) sort(x.begin(),x.end()),x.erase(unique(x.begin(),x.end()),x.end())
using namespace std;
using i64=long long;
using pii=pair<int,int>;
using pll=pair<i64,i64>;
template<class iter> void writeln(iter s,iter e){ for(;s!=e;cout<<" \n"[++s==e]) cout<<*s; }
template<class iter> void readline(iter s,iter e){ for(;s!=e;++s) cin>>*s; }
const int mod=1e9+7;
int add(int x,int y){ x+=y; return x>=mod?x-mod:0; }
int sub(int x,int y){ x+=mod-y; return x>=mod?x-mod:0; }
int mul(int x,int y){ return i64(x)*y%mod; }
int fpow(int a,int t){
	int r=1;
	for(;t;t>>=1,a=mul(a,a)) if(t&1) r=mul(r,a);
	return r;
}
const int N=3e5+5;
int n,m,a[N],l,r,k;
bool check(int mid){
	int c=0;
	for(int i=1;i<=n;++i){
		while((c+m-a[i])%m>mid) ++c;
		if(c>=m) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	readline(a+1,a+n+1);
	for(l=0,r=m;l<r;) if(check(k=(l+r)>>1)) r=k; else l=k+1;
	cout<<l<<endl;
}