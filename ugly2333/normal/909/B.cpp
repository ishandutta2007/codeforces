//CF 909B
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
typedef long long LL;
int main()
{
	int n,m;
	cin>>n;
	m=(++n)/2;
	cout<<m*(n-m)<<endl;
	return 0;
}