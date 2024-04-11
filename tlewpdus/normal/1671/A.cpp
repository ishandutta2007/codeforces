#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

char S[60];

int main() {
    int T;
    
    scanf("%d",&T);
    while(T--) {
        scanf("%s",S);
		int p = -1;
		bool good = true;
		for (int i=0;S[i];i++) {
			if (!S[i+1] || S[i]!=S[i+1]) {
				if (p+1==i) good = false;
				p = i;
			}
		}
		puts(good?"YES":"NO");
    }
    
	return 0;
}