#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[100100];

int main() {
    int T;
    
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
		bool good = false;
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			if (i) {
				if (A[i-1]>A[i]) good = true;
			}
		}
		puts(good?"YES":"NO");
    }
    
	return 0;
}