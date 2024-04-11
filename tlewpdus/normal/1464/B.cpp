#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

char S[100100];
char T[100100];
int N;
ll X, Y;

ll calc(char S[]) {
	ll sum = 0, c[2] = {0,0};
	for (int i=0;i<N;i++) {
		if (S[i]==0) sum += Y*c[1];
		else sum += X*c[0];
		c[S[i]]++;
	}
	return sum;
}

int main() {
	scanf("%s",S); N = strlen(S);
	scanf("%d%d",&X,&Y);
	for (int i=0;i<N;i++) {
		T[i] = (S[i]=='?'?(X<Y?'1':'0'):S[i]);
		T[i] -= '0';
	}
	ll ans = calc(T);
	ll mini = ans;
	ll c0[2] = {0,0};
	for (int i=1;i<N;i++) c0[1] += (T[i]==0);
	for (int i=0;i<N;i++) {
		if (S[i]=='?') {
			if (X < Y) {
				ans -= X*c0[0];
				ans -= Y*c0[1];
				ans += Y*(i-c0[0]);
				ans += X*(N-i-1-c0[1]);
				T[i] = 0;
			} else {
				ans -= Y*(i-c0[0]);
				ans -= X*(N-i-1-c0[1]);
				ans += X*c0[0];
				ans += Y*c0[1];
				T[i] = 1;
			}
			mini = min(mini,ans);
		}
		c0[0] += (T[i]==0);
		if (i+1<N) c0[1] -= (T[i+1]==0);
	}
	printf("%lld\n",mini);

	return 0;
}