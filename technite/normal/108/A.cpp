#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	int m;
	char c;
	cin>>n>>c>>m;
	while(true){
		m++;
		n += m / 60;
		m %= 60;
		n %= 24;
		if(n/10==m%10 && n % 10 == m / 10) {
		break;}
}
	cout << n / 10 << n % 10 << ":" << m / 10 << m % 10;
}