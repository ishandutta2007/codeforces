#include<bits/stdc++.h>
using namespace std;
#define int		long long
#define double	long double
#define pb		push_back
#define pob		pop_back
#define mp		make_pair
#define fi		first
#define se		second
#define pque	priority_queue
#define endl	'\n'
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, m, k, x, a;

vector <int> divn, divm, divi, fin;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	a = 2 * n * m;
	if (a % k != 0){
		cout << "NO";
		return 0;
	}
	x = a / k;
	int val = 2 * n;
	if (val % k == 0){
	    val /= k;
	}
	else{
	    val = val / k + 1;
	}
    for (int i = 1; i < sqrt(n) + 1; i++){
        if (n % i == 0){
            int val = n / i;
            divn.pb(i);
            if (val != i){
                divn.pb(val);
            }
        }
    }
    for (int i = 1; i < sqrt(m) + 1; i++){
        if (m % i == 0){
            int val = m / i;
            divm.pb(i);
            if (val != i){
                divm.pb(val);
            }
        }
    }
	for (auto i: divn){
	    for (auto j: divm){
	        divi.pb(i * j);
	        divi.pb(2 * i * j);
	    }
	}
	divi.resize(unique(divi.begin(), divi.end()) - divi.begin());
	for (auto i: divi){
		if (i % k == 0){
		    fin.pb(i / k);
		}
	}
	for (auto i: fin){
		if (val <= i && i <= n){
			cout << "YES" << endl;
			cout << "0 0" << endl;
			cout << i << " 0" << endl;
			cout << "0 " << x / i << endl;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}