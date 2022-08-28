//CF 1037A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int main()
{
	int x,i,s=0;
	cin>>x;
	for(i=1;i<=x;i=i+i)
		s++,x-=i;
	if(x)
		s++;
	cout<<s;
	return 0;
}