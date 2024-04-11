#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll T;
char S[100100];

int main() {
	scanf("%d%lld",&N,&T);
	scanf("%s",S);
	for (int i=0;i<N;i++) S[i] -= 'a';
	T -= (1<<S[N-1]);
	T += (1<<S[N-2]);
	N -=2;
	vector<int> V;
	for (int i=0;i<N;i++) {
		T += (1<<S[i]);
		V.push_back(S[i]+1);
	}
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	for (int &s : V) {
		if (T>=(1<<s)) T -= (1<<s);
	}
	if (T==0) puts("Yes");
	else puts("No");

	return 0;
}