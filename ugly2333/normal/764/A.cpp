//CF 764A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	int n,m,z,x;
	cin>>n>>m>>z;
	x=n*m/gcd(n,m);
	cout<<z/x<<endl;
	return 0;
}