#include<bits/stdc++.h>

using namespace std;

long long n, a,b ,c,d,e,f;

long long work(long long m){
	if (m < 0)
		return -1;
	m -= b;
	if (m < 0)
		return 0;
	long long tmp = m / (b - c);
	m %= (b-c);
	m += b;
	while(m >= b){
		tmp++;
		m = m - b + c;
	}
	tmp += m / a;
	return tmp;
}

int main(){
	cin>>n>>a>>b>>c;
	if (b - c >= a){
		cout<<n / a <<endl;
	}
	else{
		long long ans = n / a;
		cout<<max(ans, max(work(n), work(n - a) + 1));
	}
	return 0;
}