#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	int n, m, a, b, sum;
	cin >> n >> m >> a >> b;
	if (a > (b / m)){
		sum = (n / m) * b;
		sum += min(a * (n % m), b);
	}
	else{
		sum = a * n;
	}
	cout << sum;
}