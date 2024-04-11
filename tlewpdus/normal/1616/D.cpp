#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll X;
ll A[50100], S[50100];
int D[50100][4];

int main() {
	int ttt;
	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		for (int i=1;i<=N;i++) {
			scanf("%lld",&A[i]);
			S[i] = S[i-1]+A[i];
		}
		scanf("%lld",&X);
		if (N==1) {
			puts("1");
			continue;
		}
		D[1][0] = 0;
		D[1][1] = 1;
		D[1][2] = 0;
		D[1][3] = 1;
		for (int i=2;i<=N;i++) {
			D[i][0] = max(D[i-1][0],D[i-1][2]);
			D[i][1] = max(D[i-1][0],D[i-1][2])+1;
			D[i][2] = max(D[i-1][1],D[i-1][3]);
			D[i][3] = max(
					((S[i-2]-X*(i-2)<=S[i]-X*i)?D[i-1][1]+1:0),
					(((S[i-2]-X*(i-2)<=S[i]-X*i)&&(i==2 || (S[i-3]-X*(i-3)<=S[i]-X*i)))?D[i-1][3]+1:0)
					);
		}
		printf("%lld\n",max({D[N][0],D[N][1],D[N][2],D[N][3]}));
	}

	return 0;
}