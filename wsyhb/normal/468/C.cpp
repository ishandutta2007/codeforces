#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	long long p=(long long)9e18%a*9%a;
	long long l=a-p,r=(long long)1e18+a-p-1;
	cout<<l<<" "<<r<<endl;
	return 0;
}