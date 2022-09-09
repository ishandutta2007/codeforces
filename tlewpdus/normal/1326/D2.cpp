#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 2000100;
const ll MOD = 998244353;

//Manacher source: https://blog.myungwoo.kr/56 [PS ]

int N,A[MAXN];
char S[MAXN];

void Manachers() {
	int r = 0, p = 0;
	for (int i=1;i<=N;i++){
		if (i <= r) A[i] = min(A[2*p-i],r-i);
		else A[i] = 0;
		while (i-A[i]-1 > 0 && i+A[i]+1 <= N && S[i-A[i]-1] == S[i+A[i]+1]) A[i]++;
		if (r < i+A[i]) r = i+A[i], p = i;
	}
}

char str[1000100];
vector<int> lis[1000100], ris[1000100];

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf(" %s",str+1);
		int n = strlen(str+1);
		bool ok = 1;
		for (int i=1;i<=n;i++) if (str[i]!=str[n+1-i]) ok = 0;
		if (ok) {
			puts(str+1);
			continue;
		}
		for (int i=1;i<=n;i++) {
			S[2*i-1] = str[i];
			S[2*i] = '#';
		}
		S[2*n] = 0;
		N = 2*n-1;
		Manachers();
		auto getv = [](int s, int e) {
			s = s/2+1;
			e = (e+1)/2;
			return e-s+1;
		};
		for (int i=1;i<=N;i++) {
			int t = i-A[i];
			lis[t/2+1].push_back(getv(i-A[i],i+A[i]));
			t = i+A[i];
			ris[(t+1)/2].push_back(getv(i-A[i],i+A[i]));
		}
		int dab = 1, ti = 1, tj = 1, tt = 0;
		set<pii> se;
		int add = 0;
		for (int i=1;i<=n+1-i;i++) {
			for (int &j : lis[i]) {
				se.insert({j-add,0});
			}
			for (int &j : ris[n+1-i]) {
				se.insert({j-add,1});
			}
			auto it = se.lower_bound({n-2*i+2-add+1,-1});
			if (it!=se.begin()) {
				it = prev(it);
				int j = it->first+add;
				if (j>0&&dab<2*i-2+j) {
					dab=2*i-2+j;
					ti = i;
					tj = j;
					tt = it->second;
				}
			}
			if (str[i]!=str[n+1-i]) break;
			add -= 2;
		}
		for (int i=1;i<ti;i++) printf("%c",str[i]);
		if (tt==0) {
			for (int i=ti;i<ti+tj;i++) printf("%c",str[i]);
		}
		else {
			for (int i=n+2-ti-tj;i<n+2-ti;i++) printf("%c",str[i]);
		}
		for (int i=n+2-ti;i<=n;i++) printf("%c",str[i]);
		puts("");
		for (int i=1;i<=n;i++) lis[i].clear(), ris[i].clear();
	}

	return 0;
}