#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <pair <int, int> > vii;

const int N = 1e5 + 5, mod = 1e9 + 7;
int a[N], n, k, temp;

int gcd(int u,int v){
	if (!u){
	    return v;
	}
	if (!v){
	    return u;
	}
	return __gcd(u,v);
}

signed main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= k;
    }
    sort(a, a + n);
    temp = k;
	for (int i = 0; i < n; i++){
	    temp = gcd(temp, a[i]);
	}
	vector <int> v;
	if (!temp){
	    temp = k;
	}
	for (int i = 0; i < k; i += temp){
	    v.pb(i);
	}
	cout << v.size() << endl;
	for (auto i: v){
	    cout << i << ' ';
	}
}