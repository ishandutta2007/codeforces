#include <iostream>
using namespace std;

int main() {
	unsigned long long int n,m;
	cin>>m>>n;
	unsigned long long int kmax,kmin;
	kmax = (m-n+1)*(m-n)/2;
	kmin = (n - m%n)*(m/n)*(m/n - 1)/2 + (m%n)*(m/n + 1)*(m/n)/2;
	cout<<kmin<<" "<<kmax;
	return 0;
}