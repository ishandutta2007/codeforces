#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second

//Author: V Hong Kin (@Stakinvario)

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	cin >> a >> b;
	vector <pair <int, int> > vec;
	for (int v : {a, b, a + b}){
		for (int i = 1; i * i <= v; i++){
            if (v % i == 0){
                vec.pb({i, v == a + b});
                if (i * i < v){
                    vec.pb({v / i, v == a + b});
                }
		    }
		}
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	int res = 2 * a + 2 * b + 2, mn = min(a, b);
	for (auto v : vec){
		if (v.se == 0){
			if (a % v.fi == 0){
			    mn = min(mn, a / v.fi);
			}
			if (b % v.fi == 0){
			    mn = min(mn, b / v.fi);
			}
		}
		else{
			if ((a + b) / v.fi >= mn){
				res = min(res, 2 * (v.fi + (a + b) / v.fi));
			}
		}
	}
	cout << res;
}