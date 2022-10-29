#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q, x, tr[N];
LL p[N], pi[N], s[N];

void add(int x,int val){for(;x<=n+1;x+=x&-x) tr[x]+=val;}
int get(int x){int res=0; for(;x;x-=x&-x) res+=tr[x]; return res;}

LL pw(LL x, int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P) if(n&1) res=res*x%P;
	return res;
}
LL mdiv(LL a, LL b){
	return a * pw(b,P-2) % P;
}
LL msub(LL a, LL b){
	return a-b>=0 ? a-b: a-b+P;
}

int lbi(int l, int r,int num){
	int ans = l;
	while(l<=r){
		int m = l+r>>1;
		if(get(m)==num) ans=m,r=m-1;
		else l=m+1;
	}
	return ans;
}

int rbi(int l, int r,int num){
	int ans = r;
	while(l<=r){
		int m = l+r>>1;
		if(get(m)==num) l=m+1;
		else ans=m,r=m-1;
	}
	return ans;
}

int calc(int l, int r){
	return mdiv( msub(s[r], s[l-1]), pi[r] );
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	int INV = pw(100, P-2);
	scanf("%d%d",&n,&q);
	s[0] = 0, pi[1] = 1;
	rep(i,1,n){
		scanf("%d",p+i);
		(p[i]*=INV)%=P;
	}
	rep(i,2,n+1) pi[i] = pi[i-1] * p[i-1] % P;
	rep(i,1,n+1) s[i] = (s[i-1] + pi[i]) % P;
	
	//rep(i,1,n+1) cout<<pi[i]<<" ";cout<<endl;
	
	int ncp = 1;
	LL ans = calc(1, n+1);
	add(1,1), add(n+1,1);
	//cout<<ans<<endl;
	rep(i,1,q){
		scanf("%d",&x);
		int l = lbi(1, x-1, get(x-1)), r = rbi(x+1, n+1, get(x));
		//cout<<l<<" "<<r<<endl;
		//rep(i,1,n+1) cout<<get(i)<<" ";cout<<endl;
		if(get(x) == get(x-1)){
			add(x,1), ncp++;
			ans = (ans - calc(l, r) + calc(l, x) + calc(x, r) + P*3) % P;
		}else{
			add(x,-1), ncp--;
			ans = (ans + calc(l, r) - calc(l, x) - calc(x, r) + P*3) % P;
		}
		printf("%I64d\n",msub(ans, ncp));
	}
	return 0;
}