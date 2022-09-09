#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, Q;
char S[200100];

struct BIT {
	int bit[200100];
	void upd(int idx, int val) {
		idx++;
		while(idx<=N) {
			bit[idx]+=val;
			idx+=idx&-idx;
		}
	}
	int getv(int idx) {
		idx++;
		int ans = 0;
		while(idx) {
			ans += bit[idx];
			idx &= idx-1;
		}
		return ans;
	}
	int getv(int s, int e) {
		return getv(e)-getv(s-1);
	}
} bit[2];

int main() {
	scanf("%d%d",&N,&Q);
	scanf(" %s",S);
	for (int i=0;i+1<N;i++) {
		if (S[i]==S[i+1]) {
			if (S[i]=='0') bit[0].upd(i,1);
			else bit[1].upd(i,1);
		}
	}
	for (int i=0;i<Q;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		printf("%d\n",max(bit[0].getv(a,b-1),bit[1].getv(a,b-1))+1);
	}
    
	return 0;
}