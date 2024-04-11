#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[200100];

int main() {
    int T;
    
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
		}
		bool good = false;
		for (int t=0;t<2;t++) {
			bool mang = false;
			for (int j=0;j<N;j++) {
				if (abs(A[0]+t+j-A[j])>1) mang = true;
			}
			if (!mang) good = true;
		}
		puts(good?"YES":"NO");
    }
    
	return 0;
}