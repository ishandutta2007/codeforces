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

const int N = 1000 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, m;
bool a[N][N], b[N][N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++){
		cin >> s;
		for (int j = 0; j < m; j++){
		    a[i][j] = (s[j] == '.') ? 0 : 1;
		}
	}
	for (int i = 0; i < n - 2; i++){
	    for (int j = 0; j < m - 2; j++){
	        if (a[i][j] && a[i + 1][j] && a[i + 2][j] && a[i][j + 1] && a[i + 2][j + 1] && a[i][j + 2] && a[i + 1][j + 2] && a[i + 2][j + 2]){
	            b[i][j] = 1;
	            b[i + 1][j] = 1;
	            b[i + 2][j] = 1;
	            b[i][j + 1] = 1;
	            b[i + 2][j + 1] = 1;
	            b[i][j + 2] = 1;
	            b[i + 1][j + 2] = 1;
	            b[i + 2][j + 2] = 1;
	        }
	    }
	}
	bool ck = 1;
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < m; j++){
	        if (a[i][j] != b[i][j]){
	            ck = 0;
	            break;
	        }
	    }
	    if (!ck) break;
	}
	if (ck) cout << "YES";
	else cout << "NO";
}

/*

*/