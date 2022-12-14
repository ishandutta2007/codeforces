#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MK = 500000 + 1;

int N, M, K;
int x[MK], y[MK];
ll ans[MK];

int gcd(int a, int b){
	if(!b) return a;
	return gcd(b, a%b);
}

pair<ll, ll> extended_gcd(ll a, ll b) {
	if (b == 0) return make_pair(1, 0);
	pair<ll, ll> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	N *= 2, M *= 2;
	int g = gcd(N, M);
	for(int i=0;i<K;i++){
		ans[i] = 1e15;
		II(xx)II(yy);
		x[4*i] = xx, y[4*i] = yy;
		x[4*i+1] = N-xx, y[4*i+1] = yy;
		x[4*i+2] = N-xx, y[4*i+2] = M-yy;
		x[4*i+3] = xx, y[4*i+3] = M-yy;
	}
	for(int i=0;i<4*K;i++){
		ll _N = N, _M = M;
		if(x[i] > y[i]){
			swap(x[i], y[i]);
			swap(_N, _M);
		}
		if((y[i]-x[i])%g) continue;

		pair<ll,ll> base = extended_gcd(_N, _M);
		ll mok = (y[i]-x[i])/g;
		ll v1 = mok * base.first;
		ll v2 = mok * base.second;
		ll v = _M / g;
		if(v1 < 0){
			v1 += (-v1/v + 100) * (_M / g);
			v2 -= (-v1/v + 100) * (_N / g);
		}
		ll m = v1 / v;
		v1 -= m * (_M / g);
		v2 += m * (_N / g);
		if(v1 >= _M / g && -v2 >= _N / g){
		}
		else{
			ans[i/4] = min(ans[i/4], v1*_N + x[i]);
		}
	}
	for(int i=0;i<K;i++){
		if(ans[i] == 1e15) ans[i]=-1;
		printf("%lld\n",ans[i]);
	}
	return 0;
}