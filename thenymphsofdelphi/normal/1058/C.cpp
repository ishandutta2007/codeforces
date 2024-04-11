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

int n, sum;
string s;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	vi a(n + 1);
	a[0] = 0;
	for (int i = 1; i <= n; i++){
	    a[i] = a[i - 1] + s[i - 1] - '0';
	}
	sum = a[n];
	if (sum == 0){
	    cout << "YES";
	    return 0;
	}
	for (int i = 1; i < sum; i++){
	    if (sum % i != 0){
	        continue;
	    }
	    bool ck = true;
	    for (int j = 0; j <= sum; j += i){
	        if (find(a.begin(), a.end(), j) == a.end()){
	            ck = false;
	            break;
	        }
	    }
	    if (ck){
	        cout << "YES";
	        return 0;
	    }
	}
	cout << "NO";
}

/*

*/