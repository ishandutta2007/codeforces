
#include "bits/stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;

void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}
ll pow(ll x, ll y) {
	if(y == 0)
		return 1;

	ll mid = pow(x, y / 2);
	if(y&1)
		return mid * mid * x;
	
	return mid * mid;
}
const int mxN = 2e5;

const long long mod = 1e9+7;
template<int n> struct matrix {
	long long arr[n][n];
	matrix() {
		memset(arr, 0, sizeof(arr));
	}
	
	matrix<n> multiply(matrix& mat) {
		matrix<n> result;
		
		for(int i=0; i < n; ++i) {
			for(int k=0; k < n; ++k) {
				for(int j=0; j < n; ++j) {
					result.arr[i][j] = (result.arr[i][j] + arr[i][k] * mat.arr[k][j]) % mod;
				}
			}
		}
		
		// multiplication is fine
		return result;
	}
	
	matrix<n> pow(matrix<n> &a, long long pwr) {
		matrix<n> res;
		for(int i=0; i < n; i++) res.arr[i][i]=1;
		
		while(pwr) {
			if(pwr&1) {
				res = res.multiply(a);
			}
			pwr /= 2;
			a = a.multiply(a);
		}
		return res;
	}
};

void solve() {
	ll n, m;
	cin >> n >> m;

	matrix<2> mat1;
	mat1.arr[0][0]=1;
	mat1.arr[0][1]=1;
	mat1.arr[1][0]=1;
	mat1.arr[1][1]=0;
	matrix<2> mat2;
	mat2.arr[0][0]=1;
	mat2.arr[0][1]=1;
	mat2.arr[1][0]=1;
	mat2.arr[1][1]=0;

	cout << (2 * (mat1.pow(mat1, n + 1).arr[0][1] + mat2.pow(mat2, m + 1).arr[0][1] - 1)) % mod << "\n";
}

int main() {
	
	
	io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}