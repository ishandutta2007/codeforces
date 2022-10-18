#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;
    cin >> s;
    int t = 0;
    for (int i = 0; i < s.length(); i++){
    	if (s[i] != '4' && s[i] != '1'){
    		cout << "NO";
    		return 0;
		}
    	if (s[i] == '4'){
    		if (i == 0){
    			cout << "NO";
    			return 0;
			}
			else if (s[i - 1] != '1' && s[i - 2] != '1'){
				cout << "NO";
				return 0;
			}
			t++;
		}
		else{
			if (t != 0 && t != 1 && t != 2){
				cout << "NO";
				return 0;
			}
			t = 0;
		}
	}
	cout << "YES";
}