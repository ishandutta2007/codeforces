#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define one first
#define two second

const int INF = 0x3f2f1f0f;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<string, string> pss;

const int MAX_N = 5e2 + 10;

int N, A, B, K, F;
map<pss, int> Mp;
string S[MAX_N][2]; int Val[MAX_N];
int main() {
	cin >> N >> A >> B >> K >> F;
	for(int i=0; i<N; i++) {
		char s[2][25]; scanf("%s%s", s[0], s[1]);
		string str[2] ={string(s[0]), string(s[1])};
		S[i][0] = str[0], S[i][1] = str[1];
		Val[i] = A;
		if(i >= 1 && S[i-1][1] == S[i][0]) Val[i] = B;
	}
	for(int i=0; i<N; i++) {
		string str[2] ={S[i][0], S[i][1]};
		if(str[0] > str[1]) swap(str[0], str[1]);
		Mp[pss(str[0], str[1])] += Val[i];
	}
	vector<int> List;
	int ans = 0;
	for(auto mp : Mp) {
		int val = mp.second;
		//		ans += min(val, F);
		ans += val;
		List.push_back(F - val);
	}
	sort(ALL(List));
	for(int i=0; i<min(K, SZ(List)); i++) {
		if(List[i] > 0) break;
		ans += List[i];
	}
	printf("%d\n", ans);
	return 0;
}