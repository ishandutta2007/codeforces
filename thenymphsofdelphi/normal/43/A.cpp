#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, a = 0, b = 0;
    string as = "a", bs = "b", inp;
    cin >> n;
    while (n--){
    	cin >> inp;
    	if ((inp == as) || (inp != as && as == "a")){
    		as = inp;
    		a++;
		}
		else{
    		bs = inp;
    		b++;
		}
	}
	if (a > b){
		cout << as;
	}
	else{
		cout << bs;
	}
}