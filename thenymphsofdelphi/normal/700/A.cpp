#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

signed main(){
	ld l, v1, v2;
	int n, k;
    cin >> n >> l >> v1 >> v2 >> k;
    ld z = n / k;
    if (n % k != 0){
		z++;
	}
    ld b = l / ((z - ((v2 - v1) * (z - 1)) / (v1 + v2)) * v2);
    ld a = (l - b * v2) / v1;
    cout << fixed << setprecision(6) << a + b;
	//cout << (int)((a + b) * 1000000);
}