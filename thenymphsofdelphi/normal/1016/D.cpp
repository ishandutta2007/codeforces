#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define ld   long double
#define ull  unsigned long long
#define fi   first
#define se   second
#define pb   push_back
#define pob  pop_back
#define mp   make_pair
#define pque priority_queue
#define endl '\n'
typedef vector <int> 	vi;
typedef vector <ll>		vll;
typedef pair <int, int> ii;
typedef pair <int, int> llll;
typedef vector <vi > 	vvi;
typedef vector <vll > 	vvll;
typedef vector <ii > 	vii;
typedef vector <llll > 	vllll;

const ll N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n], b[m], c[n][m];
	int x = 0, y = 0;
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	    x ^= a[i];
	}
	for (int i = 0; i < m; i++){
	    cin >> b[i];
	    y ^= b[i];
	}
	if (x != y){
	    cout << "NO";
	    return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n - 1; i++){
	    for (int j = 0; j < m - 1; j++){
	        c[i][j] = 1;
	    }
	}
	for (int i = 0; i < n - 1; i++){
	    c[i][m - 1] = a[i];
	    for (int j = 0; j < m - 1; j++){
	        c[i][m - 1] ^= c[i][j];
	    }
	}
	for (int i = 0; i < m; i++){
	    c[n - 1][i] = b[i];
	    for (int j = 0; j < n - 1; j++){
	        c[n - 1][i] ^= c[j][i];
	    }
	}
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < m; j++){
	        cout << c[i][j] << ' ';
	    }
	    cout << endl;
	}
}