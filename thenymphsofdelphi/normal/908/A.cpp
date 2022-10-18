#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++){
    	if (s[i] >= '0' && s[i] <= '9'){
    		int val = s[i] - '0';
    		if (val % 2 == 1){
    			ans++;
			}
		}
		else if (s[i] == 'a' ||
				 s[i] == 'e' ||
				 s[i] == 'i' ||
				 s[i] == 'o' ||
				 s[i] == 'u'){
			ans++;
		}
	}
	cout << ans;
}