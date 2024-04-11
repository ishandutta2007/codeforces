#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

char S[510], T[1010];

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf(" %s",S);
		scanf(" %s",T);
		int N = strlen(S);
		int M = strlen(T);
		bool good = false;
		for (int i=0;i<N;i++) {
			for (int j=i;j<N;j++) {
				if (M<j-i+1 || j-i+1+j<M) continue;
				int p = 0;
				bool mang = false;
				for (int k=i;k<=j;k++) {
					if (S[k]!=T[p]) {
						mang = true;
						break;
					}
					p++;
				}
				for (int k=j-1;k>=j-(M-(j-i+1));k--) {
					if (S[k]!=T[p]) {
						mang = true;
						break;
					}
					p++;
				}
				if (!mang) {
					good = true;
					break;
				}
			}
			if (good) break;
		}
		puts(good?"YES":"NO");
	}

	return 0;
}