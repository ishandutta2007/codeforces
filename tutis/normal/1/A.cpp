#include <bits/stdc++.h>
using namespace std;
int main()
{
	int64_t n, m, a;
	cin>>n>>m>>a;
	int64_t N=n/a;
	if(N*a!=n)
		N++;
	int64_t M=m/a;
	if(M*a!=m )
		M++;
	cout<<N*M;
}