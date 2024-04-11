#include<bits/stdc++.h>
using namespace std;

#define For(i,a,b) for (int i = a; i <= b; ++ i)
#define pb push_back

const int N = 50;
int n, q, res, sum, x;
int demo[N], cnt[N];
vector <int> bit; 

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> x;
		int bit2 = 0;
		while (x > 1){
			bit2++;
			x /= 2;
		}
		demo[bit2]++;
		cnt[bit2] = demo[bit2];
	}
	for (int i = 0; i <= N; i++){
	    res += cnt[i];
	}
	while (q--){
		cin >> x;
		bit.clear(); 
		while (x > 0){
			bit.push_back(x % 2);
			x /= 2;	
		}
		sum = 0;
		for (int i = bit.size() - 1; i >= 0; i--){
			sum *= 2;
			if (bit[i]){
			    sum++;
			}
			if (sum){
				if (demo[i] >= sum){
					demo[i] -= sum;
					sum = 0;
				}
				else{
					sum -= demo[i];
					demo[i] = 0;
				}
			}
		}
		int res1 = 0;
		for (int i = 0; i <= N; i++){
			res1 += demo[i];
			demo[i] = cnt[i];
		}
		if (sum > 0){
		    cout << "-1\n";
		}
		else{
		    cout << res - res1 << "\n";
		}
	}
}