#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define one first
#define two second

const int INF = 0x3f2f1f0f;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<string, string> pss;

const int MAX_N = 1e5 + 10;

int N; char S[MAX_N];
vector<int> Ps;

bool isPossible(int m) {
	bool isCan = true;
	for(int i=1, j, ix=0; i<=N; i++) {
		if(S[i] == '*') {
			if(ix == SZ(Ps)) { isCan = false; break; }
			int x = Ps[ix]; ix++;
			if(i < x) {
				int used = abs(x - i);
				if(used > m) { isCan = false; break; }
				int firstJ = x;
				if(m - used * 2 > 0) firstJ += m - used * 2;
				int secondJ = x;
				secondJ += (m - used) / 2;
//				printf("%d %d\n", firstJ, secondJ);

				j = max(firstJ, secondJ);
			} else {
				j = max(x+m, i-1);
			}
			i = j;
		}
	}
	return isCan;
}
int main() {
	cin >> N; scanf("%s", S+1);

	for(int i=1; i<=N; i++) if(S[i] == 'P') Ps.push_back(i);

//	printf("%d\n", isPossible(16));	return 0;
	int ans = -1;
	for(int l=0, r=2*N+100; l<=r;) {
		int m = (l+r) >> 1;
		if(isPossible(m)) ans = m, r = m-1; else l = m+1;
	}
	printf("%d\n", ans);
	return 0;
}