#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair

signed main(){
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	int ta, fa, tb, fb;
	while (k--){
	    cin >> ta >> fa >> tb >> fb;
	    int ans = abs(ta - tb) + abs(fa - fb);
	    if ((fa >= a && fa <= b) || (fb >= a && fb <= b)){
	        cout << ans << endl;
	        continue;
	    }
	    if (ta == tb){
	        cout << ans << endl;
	        continue;
	    }
	    if (fa < a && fb < a){
	        ans += 2 * a - 2 * max(fa, fb);
	    }
	    else if (fa > b && fb > b){
	        ans += 2 * min(fa, fb) - 2 * b;
	    }
	    cout << ans << endl;
	}
}