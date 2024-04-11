#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans = 0;

void cal(int a, int b){
	if (a > b){
		swap(a, b);
	}
	if (a == 0){
		return;
	}
	ans += b / a;
	cal(a, b - a * (b / a));
	return;
}

signed main(){
    int a, b;
    cin >> a >> b;
    cal(a, b);
    cout << ans;
}