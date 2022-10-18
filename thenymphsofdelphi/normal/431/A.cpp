#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int a, b, c, d;
    string s;
    int sum = 0;
    cin >> a >> b >> c >> d;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
    	switch (s[i]){
    		case '1': sum += a; break;
    		case '2': sum += b; break;
    		case '3': sum += c; break;
    		case '4': sum += d; break;
    		default: cout << "System khung the :D"; return 0;
		}
	}
	cout << sum;
}