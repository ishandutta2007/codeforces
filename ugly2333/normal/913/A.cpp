//CF 913A
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
	int m,n;
	cin>>m>>n;
	if(m<=30)
		cout<<n%(1<<m);
	else
		cout<<n;
	return 0;
}