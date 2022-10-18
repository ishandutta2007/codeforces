#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int a, b, c;
    cin >> a >> b >> c;
    int dif = b - a;
    if (dif == 0){
    	cout << "YES";
    	return 0;
	}
	else if (dif != 0 && c == 0){
		cout << "NO";
		return 0;
	}
    if (dif % c == 0 && dif / c > 0){
    	cout << "YES";
	}
	else{
		cout << "NO";
	}
}