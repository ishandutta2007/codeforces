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

const int N = 1e6 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, ans = 0;
int a[N], b[N], ck[N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++){
	    a[i] = s[i - 1] - '0';
	}
	cin >> s;
	for (int i = 1; i <= n; i++){
	    b[i] = s[i - 1] - '0';
	}
	if (n == 1){
	    if (a[1] == b[1]){
	        cout << 0;
	    }
	    else{
	        cout << 1;
	    }
	    return 0;
	}
	for (int i = 1; i <= n; i++){
	    if (a[i] != b[i]){
	        ck[i] = 1;
	    }
	    else{
	        ck[i] = 0;
	    }
	}
	for (int i = 1; i <= n; i++){
	    if (ck[i]){
	        if (ck[i - 1] && a[i] != a[i - 1]){
	            ans++;
	            ck[i] = 0;
	            ck[i - 1] = 0;
	        }
	        else if (ck[i + 1] && a[i] != a[i + 1]){
	            ans++;
	            ck[i] = 0;
	            ck[i + 1] = 0;
	        }
	        else{
	            ans++;
	            ck[i] = 0;
	        }
	    }
	}
	cout << ans;
}