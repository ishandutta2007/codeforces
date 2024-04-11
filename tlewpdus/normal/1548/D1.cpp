#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

ll ccw(pll A, pll B, pll C) {
	return (B.first-A.first)*(C.second-A.second)-(C.first-A.first)*(B.second-A.second);
}
int _gcd(int a, int b) {
	if (!a) return b;
	return _gcd(b%a,a);
}
int gcd(int a, int b) {
	return _gcd(abs(a),abs(b));
}

int N;
pll P[6010];
int C[2][2][2][2];

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		ll x, y;
		scanf("%lld%lld",&x,&y);
		P[i] = {x,y};
	}
	for (int a=0;a<2;a++) {
		for (int b=0;b<2;b++) {
			for (int c=0;c<2;c++){
				for (int d=0;d<2;d++) {
					int g = gcd(a,b)*2+gcd(c,d)*2+gcd(c-a,d-b)*2;
					if (g%4==0) {
						C[a][b][c][d] = 1;
					}
				}
			}
		}
	}
	ll ans = 0;
	int D[2][2];
	for (int i=0;i<N;i++) {
		memset(D,0,sizeof(D));
		for (int j=i+1;j<N;j++){
			D[abs((P[j].first-P[i].first)/2)%2][abs((P[j].second-P[i].second)/2)%2]++;
		}
		for (int a=0;a<2;a++) {
			for (int b=0;b<2;b++) {
				for (int c=0;c<2;c++){
					for (int d=0;d<2;d++) {
						if (C[a][b][c][d]) {
							if (a==c&&b==d) ans += (D[a][b]*(D[a][b]-1));
							else ans += D[a][b]*D[c][d];
						}
					}
				}
			}
		}
	}
	printf("%lld\n",ans/2);

	return 0;
}