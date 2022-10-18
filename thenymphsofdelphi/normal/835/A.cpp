#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int a1 = b * a + d + d, a2 = c * a + e + e;
    if (a1 < a2){
    	cout << "First";
    	return 0;
	}
	else if (a2 < a1){
		cout << "Second";
		return 0;
	}
	cout << "Friendship";
}