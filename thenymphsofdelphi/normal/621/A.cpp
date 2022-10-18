#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, sum = 0, sumodd = 0, fodd = 1000000010;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
    	cin >> a[i];
    	if (a[i] % 2 == 0){
    		sum += a[i];
		}
		else{
			sum += a[i];
			sumodd++;
			fodd = min(fodd, a[i]);
		}
	}
	if (sumodd % 2 == 1){
		sum -= fodd;
	}
	cout << sum;
}