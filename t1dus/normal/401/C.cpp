#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s;
	int last = -1, ltl = -1;
	while (n or m){
	    if (m >= n and not(ltl == last and ltl == 1)){
	        s += "1";
	        ltl = last;
            last = 1;
            m -= 1;
	    }   
	    else{
	        if (last == 0){
	            cout << -1;
	            return 0;
	        }
	        s += "0";
            ltl = last;
            last = 0;
            n -= 1;
	    }
	    if (m < 0 or n < 0){
	        cout << -1;
	        return 0;
	    }
	}
	cout << s;
}