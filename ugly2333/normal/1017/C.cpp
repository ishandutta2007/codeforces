//CF 1017C
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
	int n,i,j,x,y;
	cin>>n;
	for(x=1;x*x<=n;x=x+1);
	x--;
	y=n-x+1;
	for(i=1;i<=n;i=i+1){
		cout<<y<<' ';
		if(i%x==0)
			y-=x+x;
		y++;
		if(y<=0)
			y=1;
	}
	return 0;
}