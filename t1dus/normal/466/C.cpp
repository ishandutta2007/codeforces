#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 100000000
#define mp make_pair

int main() {
	
	ios::sync_with_stdio(false);
	int n;
    cin >> n;
    ll a[n];
    ll s;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(i) a[i] += a[i-1];
    }
    s = a[n-1];
    if (s%3) cout << 0 << endl;
    else{
        s /= 3;
        ll x = 0,y = 0;
        ll ans = 0;
        for (int i = 0; i < n-1; i++){
            if ((i > 0) && a[i] == s*2) ans += x;
            if (a[i] == s) x++;
        }
        cout << ans << endl;
    }
}