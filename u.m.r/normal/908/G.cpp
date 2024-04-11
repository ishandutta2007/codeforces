#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2222 + 10;

int n, m;

void prework(){

}

void read(){

}

ll ww[MAXN];
ll cnt[MAXN];

char s[MAXN];

ll pw(ll p, ll q){
	if (q == 0) return 1;
	ll ret = 1;
	p %= MM;
	for (; q; q >>= 1){
		if (q & 1) ret = ret * p % MM;
		p = p * p % MM;
	}
	return ret;
}

ll C[2222][2222];

ll gao(ll x, ll c, ll d, ll m){
	ll u = pw((9 - x) * 10 + x + 10, m);
	ll v = pw((9 - x) * 10 + x + 1, m);
	ll ans = ((pw(10, c) * u - v) % MM + MM) % MM;
	ans = (ans * x % MM * pw(9, MM - 2) % MM);
	return ans;
	/*
	ll ret = 0;
	for (int a = 0; a <= m; a++)
		for (int b = 0; b <= m - a; b++)
			ret = (ret + C[m][a] * C[m - a][b] % MM * pw(9 - x, m - a - b) % MM * pw(x, a + 1) % MM * (pw(10, b + c) - 1) % MM * pw(9, MM - 2) % MM * pw(10, m - a - b)) % MM;
	ret = (ret % MM + MM) % MM;
	//cout << x << ' ' << c << ' ' << d << ' ' << m << ' ' << ret << endl;
	return ret;
	if (m == 0){
		return (pw(x, d + 1) * (pw(10, c) - 1) % MM * pw(9, MM - 2) % MM + MM) % MM;
	}
	ll q = pw(10, MM - 2);
	ll p = q * x % MM;
	ll tmp = (MM + (1 - pw(p, m)) % MM * pw(1 - p, MM - 2) % MM) % MM;
	ll ans = pw(10, m + c) * 
		((m + 1) * tmp - 
		p * pw(pw(1 - p, MM - 2), 2) % MM * (1 - pw(p, m) - m * pw(p, m - 1) % MM + m * pw(p, m) % MM) % MM)
		- pw(10, m) * pw(1 - q, MM - 2) % MM * (tmp - pw(q, m) * (1 - pw(x, m)) % MM * pw(1 - x, MM - 2) % MM) % MM;
	ans = (ans % MM + MM) % MM;
	ans = ans * pw(x, d + 1) % MM * pw(9, MM - 2) % MM;
	return (ans % MM + MM) % MM ;*/
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%s", s + 1);
	n = strlen(s + 1);
	/*C[0][0] = 1;
	C[1][1] = C[1][0] = 1;
	for (int i = 2; i <= n; i++){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MM;
	}
	ww[0] = 1;
	for (int i = 1; i <= n + 2; i++)
		ww[i] = ww[i-1] * 10 % MM;*/
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 10; j++)
			cnt[j] = 0;
		for (int j = 1; j < i; j++)
			cnt[s[j] - '0']++;
		for (int k = 0; k < s[i] - '0' + (i == n); k++){
			cnt[k]++;
			int nn = n - i;
			int les = 0;
			for (int j = 0; j < 10; j++){
				//cout << "!! " << i << k << j << endl;
				ans = (ans + gao(j, cnt[j], les, nn) * pw(10, i - les - cnt[j])) % MM;
				les += cnt[j];
			}
			cnt[k]--;
		}
	}
	printf("%lld\n", (ans % MM + MM) % MM);
}

void printans(){

}

int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}