#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

LL P=0, Q, n, m=0;
LL tr[N],a[N],b[N];
bool v[N];

int lowbit(int x){return x&(-x);} 
LL getsum(int x){
   	LL s = 0;
    for(; x > 0; x -= lowbit(x) ) s+=tr[x];
	return s;
}
void update(int x,int num){
	for(; x <= n; x += lowbit(x) ) tr[x]+=num;
} 

LL pw(LL x, int n){
	if(n==0)return 1;
	LL y = pw(x, n>>1);
	y = (y*y)%MOD;
	return n&1 ? (y*x)%MOD : y;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%lld",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);
		if(a[i]!=-1){
			v[a[i]] = true;
			b[++m] = a[i];
		}
	}
	Q = n - m;
	rep(i,1,n)if(!v[i])b[++m]=i;
	
	for(int i=n-Q;i;--i){
		P = (P + max(Q,1ll) * getsum(b[i]) ) % MOD;
		update(b[i],1);
	}
	if(Q==0){
		cout<<P<<endl;
		return 0;
	}
	
	memset(tr,0,sizeof(tr));
	rep(i,n-Q+1,n)update(b[i],1);
	LL cnt0 = 0;
	for(int i=n;i;--i){
		if(a[i]==-1) ++cnt0;
		else{
			P = (P + getsum(a[i]) * cnt0) % MOD;
			P = (P + (Q-getsum(a[i])) * (Q-cnt0)) % MOD;
		}
	}
	
	/*double P1 = P + Q * (Q-1) * 1.0 / 4 * Q;
	cout<<P1<<" "<<Q<<endl;
	cout<<P1/(double)Q<<endl;*/
	P = (P + Q * (Q-1) % MOD * pw(4,MOD-2) % MOD * Q) % MOD;
	cout<<(P*pw(Q,MOD-2))%MOD<<endl;
	return 0;
}