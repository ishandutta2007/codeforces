//CF1090M
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
	int n,k,x,y,z,o;
	scanf("%d%d",&n,&k);
	x=0,y=0;
	o=-1;
	while(n--){
		scanf("%d",&z);
		if(z==o)
			x=max(x,y),y=1;
		else
			y++;
		o=z;
	}
	cout<<max(x,y);
	return 0;
}