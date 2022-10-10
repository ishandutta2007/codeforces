#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using cat = long long;

constexpr int MX = 60;
constexpr cat mod = 1000000007;

int gcd(int a, int b) {
	if(a > b) swap(a, b);
	return a ? gcd(b%a, a) : b;
}

int lcm(int a, int b) {
	return a*b/gcd(a,b);
}

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	return e&1 ? x * a % mod : x;
}

int main() {
	int N;
	cin >> N;
	static char A[MX+1];
	for(int i = 0; i < N; i++) {
		int a;
		a = i+2;
		cin >> a;
		A[a] = 1;
	}
	if(A[1]) {
		cat ans = 1;
		for(int i = 1; i < N; i++) ans = ans * i % mod;
		cout << ans << "\n";
		return 0;
	}

	vector<int> divs;
	for(int i = 2; i <= MX/3; i++) if(A[i]) divs.push_back(i);
	while(true) {
		bool stop = true;
		for(int i = 0; i < (int)divs.size(); i++) {
			bool has_div = false;
			for(auto d : divs) has_div |= (divs[i]%d == 0 && divs[i] != d);
			if(has_div) {
				divs.erase(begin(divs)+i);
				stop = false;
				break;
			}
		}
		if(stop) break;
	}
	vector<int> L(MX+1, 0);
	for(int i = 2; i <= MX; i++) {
		int p = 1;
		for(auto d : divs) if(i%d == 0 && d != i) p = lcm(p, d);
		if(p != 1) L[i] = p;
	}
	vector<cat> G0(MX+1, 0);
	for(int i = 2; i <= MX; i++) if(A[i])
		for(int j = 2; j <= MX; j++) if(A[j] && i != j)
			for(auto d : divs) if(i%d == 0 && j%d == 0 && d < i && d < j)
				G0[i] |= 1LL<<j;
	vector<int> cnt_compr(MX+1, 0);
	for(int i = 2; i <= MX; i++) if(G0[i]) cnt_compr[L[i]]++;
	vector<int> id(MX+1, 0);
	int V = 0;
	vector<int> cnt_v;
	for(int i = 2; i <= MX; i++) if(cnt_compr[i]) {
		id[i] = ++V;
		cnt_v.push_back(cnt_compr[i]);
	}
	vector<cat> G(V, 0);
	for(int i = 2; i <= MX; i++)
		for(int j = 2; j <= MX; j++) if((G0[i]>>j)&1)
			G[id[L[i]]-1] |= 1LL<<(id[L[j]]-1);

	vector<cat> comp;
	vector<int> vis(V, 0);
	for(int i = 0; i < V; i++) if(!vis[i]) {
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		cat c_nw = 0;
		while(!q.empty()) {
			c_nw |= 1LL<<q.front();
			for(int j = 0; j < V; j++) if((G[q.front()]>>j)&1 && !vis[j]) {
				vis[j] = 1;
				q.push(j);
			}
			q.pop();
		}
		comp.push_back(c_nw);
	}

	vector<cat> fac(MX+1, 1), fac_inv(MX+1, 1);
	for(int i = 2; i <= MX; i++) fac[i] = i * fac[i-1] % mod;
	for(int i = 2; i <= MX; i++) fac_inv[i] = pw(fac[i], mod-2);

	cat ans = 1;
	int max_sz = 0;
	for(auto c : comp) {
		int V_c = 0;
		vector<int> id_c(V, 0);
		vector<int> cnt_c;
		for(int i = 0; i < V; i++) if((c>>i)&1) {
			id_c[i] = ++V_c;
			cnt_c.push_back(cnt_v[i]);
		}
		vector<cat> G_c(V_c, 0);
		for(int i = 0; i < V; i++) if(id_c[i])
			for(int j = 0; j < V; j++) if(id_c[j])
				if((G[i]>>j)&1) G_c[id_c[i]-1] |= 1LL<<(id_c[j]-1);
		// max covers
		vector<cat> cnt_cur(1<<V_c, 0);
		int sum_tot = 0;
		for(int j = 0; j < V_c; j++) sum_tot += cnt_c[j];
		for(int i = 0; i < V_c; i++)
			cnt_cur[1<<i] = fac[sum_tot-1] * fac_inv[sum_tot-cnt_c[i]] % mod * cnt_c[i] % mod;
		for(int i = 1; i < (1<<V_c); i++) if(cnt_cur[i]) {
			int sum = 0;
			for(int j = 0; j < V_c; j++) if(!((i>>j)&1)) sum += cnt_c[j];
			for(int j = 0; j < V_c; j++) if(!((i>>j)&1) && G_c[j]&i) {
				cat C = fac[sum-1] * fac_inv[sum-cnt_c[j]] % mod * cnt_c[j] % mod;
				cnt_cur[i|(1<<j)] = (cnt_cur[i|(1<<j)] + cnt_cur[i] * C) % mod;
			}
		}
		max_sz += sum_tot-1;
		ans = ans * cnt_cur.back() % mod * fac_inv[sum_tot-1] % mod;
	}
	ans = ans * fac[max_sz] % mod;
	cout << ans << "\n";
}