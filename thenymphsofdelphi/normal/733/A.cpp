#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int mx = 0, t = 0;
    s += "A";
    for (int i = 0; i < s.length(); i++){
    	t++;
    	if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
    		mx = max(mx, t);
    		t = 0;
		}
	}
	cout << mx;
}