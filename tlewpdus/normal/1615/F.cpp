#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

const int bias = 2010;

int N;
char A[2][2010];
ll D[2010][4020], E[2010][4020];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d", &N);
		scanf(" %s",A[0]+1);
		scanf(" %s",A[1]+1);
		E[0][bias] = 1;
		for (int i=1;i<=N;i++) for (int j=-N;j<=N;j++) D[i][j+bias] = E[i][j+bias] = 0;
		for (int i=1;i<=N;i++) {
			for (int j=-N;j<=N;j++) {
				for (int k=0;k<4;k++) {
					bool mang = false;
					for (int l=0;l<2;l++) {
						if (A[l][i]==(1-(k>>l&1))+'0') mang = true;
					}
					if (mang) continue;
					if (k==0||k==3) {
						E[i][j+bias] = (E[i][j+bias]+E[i-1][j+bias])%MOD;
						D[i][j+bias] = (D[i][j+bias]+D[i-1][j+bias])%MOD;
					}
					else {
						int sgn = ((i%2)^(k%2))*2-1;
						if (abs(j)<abs(j+sgn)) {
							E[i][j+bias+sgn] = (E[i][j+bias+sgn]+E[i-1][j+bias])%MOD;
							D[i][j+bias+sgn] = (D[i][j+bias+sgn]+D[i-1][j+bias]+E[i-1][j+bias]*(-i))%MOD;
						}
						else {
							E[i][j+bias+sgn] = (E[i][j+bias+sgn]+E[i-1][j+bias])%MOD;
							D[i][j+bias+sgn] = (D[i][j+bias+sgn]+D[i-1][j+bias]+E[i-1][j+bias]*i)%MOD;
						}
					}
				}
			}
		}
		printf("%lld\n",(D[N][bias]%MOD+MOD)%MOD);
	}

	return 0;
}