#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
	ull n;
	cin>>n;
	cout<<n*(n-1)*(n-2)*(n-3)*(n-4)/120*n*(n-1)*(n-2)*(n-3)*(n-4)<<endl;
	return 0;
}