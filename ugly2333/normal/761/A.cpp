//CF 761A
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
int main()
{
	int n,m;
	cin>>n>>m;
	if(n-m>1||m-n>1||n==0&&m==0)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}