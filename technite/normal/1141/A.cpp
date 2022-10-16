#include <bits/stdc++.h>
using namespace std;
int n,m,r,g;
int main(){
	cin>>n>>m;
	g=__gcd(n,m);
	n/=g;m/=g;
	for(;m%2==0&&m>n;m/=2,r++);
	for(;m%3==0&&m>n;m/=3,r++);
	cout<<(m-n?-1:r);
}