//CF 842B
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
	int r,d,n,x,y,z,ans;
	scanf("%d%d%d",&r,&d,&n);
	d=r-d;
	ans=0;
	while(n--){
		scanf("%d%d%d",&x,&y,&z);
		if((z+d)*(z+d)<=x*x+y*y&&x*x+y*y<=(r-z)*(r-z))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}