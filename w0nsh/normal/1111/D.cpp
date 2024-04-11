#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 1000000007;

int mod_pow(int b, int e){
	int r = 1;
	while(e > 0){
		if(e&1) r = (1ll*r*b)%MOD;
		b = (1ll*b*b)%MOD;
		e >>= 1;
	}
	return r;
}
int fact[200005], invfact[200005];
inline int falling(int n, int k){
	return (1ll*fact[n]*invfact[n-k])%MOD;
}
inline int binco(int n, int k){
	if(k == 0) return 1;
	if(n < k) return 0;
	return (1ll*falling(n, k)*invfact[k])%MOD;
}

int n;
std::string str;
int cnt[52];
int dp[52][100005], dpr[52][100005];
int K[52][52];

int id(char ch){
	if(ch <= 'Z') return ch - 'A';
	return ch - 'a' + 26;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = 1;
	invfact[0] = 1;
	REP(i, 1, 100005) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = mod_pow(fact[i], MOD-2);
	std::cin >> str;
	n = SZ(str);
	TRAV(ch, str) cnt[id(ch)]++;
	ll xd = (1ll*fact[n/2]*fact[n/2])%MOD;
	FOR(i, 52) xd = (1ll*xd*invfact[cnt[i]])%MOD;
	FOR(i, 52){
		FOR(j, 52) FOR(k, n/2+1) dp[j][k] = dpr[j][k] = 0;
		dp[0][0] = 1;
		FOR(j, 52){
			if(j > 0) FOR(k, n/2+1) dp[j][k] = dp[j-1][k];
			if(i != j && cnt[j] > 0){
				dp[j][cnt[j]] = (dp[j][cnt[j]]+1)%MOD;
				if(j > 0) REP(k, cnt[j]+1, n/2+1) dp[j][k] = (dp[j][k]+dp[j-1][k-cnt[j]])%MOD;
			}
		}
		dpr[51][0] = 1;
		for(int j = 51; j >= 0; --j){
			if(j < 51) FOR(k, n/2+1) dpr[j][k] = dpr[j+1][k];
			if(i != j && cnt[j] > 0){
				dpr[j][cnt[j]] = (dpr[j][cnt[j]]+1)%MOD;
				if(j < 51) REP(k, cnt[j]+1, n/2+1) dpr[j][k] = (dpr[j][k]+dpr[j+1][k-cnt[j]])%MOD;
			}
		}
		K[i][i] = dp[51][n/2];
		REP(j, i+1, 52){
			if(j == 51) K[i][j] = (1ll*K[i][j] + dp[j-1][n/2])%MOD;
			else{
				FOR(k, n/2+1){
					K[i][j] = (1ll*K[i][j]+1ll*dp[j-1][k]*dpr[j+1][n/2-k])%MOD;
				}
			}
			K[j][i] = K[i][j];
		}
	}
	int q;
	std::cin >> q;
	while(q--){
		int a, b;
		std::cin >> a >> b;
		a = id(str[a-1]);
		b = id(str[b-1]);
		std::cout << (2ll*xd*K[a][b])%MOD << "\n";
	}
	return 0;
}