#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main(){
    string s, s2, ans;
	cin >> s;
	int n = s.length(), m, idx = n + 1;
	for (int i = 0; i < n; i++){
	    if (s[i] == '0' || s[i] == '2'){
	        s2.pb(s[i]);
	    }
	}
	m = s2.length();
	for (int i = 0; i < m; i++){
		if (s2[i] == '0'){
		    ans.pb('0');
		}
		else{
			idx = i;
			break;
		}
	}
	for (int i = 0; i < n; i++){
	    if (s[i] == '1'){
	        ans.pb('1');
	    }
	}
	for (int i = idx; i < m; i++){
	    ans.pb(s2[i]);
	}
	cout << ans;
}