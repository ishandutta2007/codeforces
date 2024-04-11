//CF 932A
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
typedef double DB;
char c[111111];
int main()
{
	cin>>c;
	int n=strlen(c),i;
	for(i=0;i<n;i=i+1)
		cout<<c[i];
	for(i=n-1;i>=0;i=i-1)
		cout<<c[i];
	return 0;
}