#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a,b;
	cin>>a>>b;
	cout<<(b/a+((b%a==0)?0:1))<<endl;
	return 0;
}