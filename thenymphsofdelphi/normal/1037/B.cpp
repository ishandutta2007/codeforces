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

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, k, ans = 0, mid;
int a[N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	mid = a[n / 2];
	if (mid == k){
	    cout << 0;
	    return 0;
	}
	if (mid < k){
	    for (int i = n / 2; i < n; i++){
	        ans += max(0ll, k - a[i]);
	    }
	    cout << ans;
	}
	else{
	    for (int i = 0; i <= n / 2; i++){
	        ans += max(0ll, a[i] - k);
	    }
	    cout << ans;
	}
}

/*

*/