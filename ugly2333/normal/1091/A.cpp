//CF1091A
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
	int a,b,c;
	cin>>a>>b>>c;
	cout<<min(min(a+1,b),c-1)*3;
	return 0;
}