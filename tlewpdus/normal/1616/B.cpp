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
char S[100100];

int main() {
	int ttt;
	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		scanf(" %s",S);
		int i;
		vector<int> cand;
		cand.push_back(1);
		for (i=1;i<N;i++) {
			if (S[i]>S[i-1]) {
				cand.push_back(i);
				break;
			}
			if (S[i]<S[i-1]) cand.push_back(i);
		}
		cand.push_back(N);
		vector<string> cands;
		for (int &v : cand) {
			string s;
			for (int j=0;j<v;j++) s.push_back(S[j]);
			for (int j=v-1;j>=0;j--) s.push_back(S[j]);
			cands.push_back(s);
		}
		puts(min_element(cands.begin(),cands.end())->c_str());
	}

	return 0;
}