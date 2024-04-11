//CF 1017A
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
	int n,i,a,b,c,d,s,x;
	cin>>n>>a>>b>>c>>d;
	s=a+b+c+d,x=1;
	for(i=2;i<=n;i=i+1){
		cin>>a>>b>>c>>d;
		if(a+b+c+d>s)
			x++;
	}
	cout<<x;
	return 0;
}