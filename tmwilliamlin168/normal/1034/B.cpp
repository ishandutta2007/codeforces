#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	if(n>m)
		swap(n, m);
	if(n>=3)
		cout << n*m/2*2;
	else if(n==1)
		cout << m/6*6+max((m%6-3)*2, 0ll);
	else
		cout << (m>=4&&(m%2==0||m==5||m>7)?2*m:(m==2?0:(m==3?4:12)));
}