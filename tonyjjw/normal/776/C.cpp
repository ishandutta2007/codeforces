#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<map>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 10;
const ll INF = 1e15;

int N, k;
ll A[MN];

int main(){
	scanf("%d%d",&N,&k);
	ll minv = 0, maxv = 0;
	for(int i=1;i<=N;i++){
		scanf("%lld", &A[i]);
		A[i] += A[i-1];
		minv = min(minv, A[i]);
		maxv = max(maxv, A[i]);
	}
	ll maxdiff = maxv - minv;

	vector<ll> vals;
	if(k == -1){
		vals.push_back(-1), vals.push_back(1);
	}
	else if(k == 1){
		vals.push_back(1);
	}
	else{
		ll a = 1;
		while(a <= maxdiff){
			vals.push_back(a);
			a *= k;
		}
	}

	map<ll, int> M;
	ll ans = 0;
	for(int i=0;i<=N;i++){
		for(ll &val: vals){
			ans += M[A[i]-val];
		}
		M[A[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}