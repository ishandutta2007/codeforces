#include<bits/stdc++.h>
using namespace std;

int n, k, ans;
double sum;

int main(){
    int x;
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> x;
		sum += x;
	}
	while (round(sum / n) < k){
	    sum += k;
	    n++;
	    ans++;
	}
	cout << ans;
}