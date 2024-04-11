// CF 821B
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
LL cal(int x,int y)
{
	return (LL)(x+1)*(y+1)*(x+y)/2;
}
int main()
{
	int a,b,i,x,y;
	LL ans;
	cin>>a>>b;
	x=0;
	y=b;
	ans=0;
	while(y>=0){
		ans=max(ans,cal(x,y));
		y--;
		x+=a;
	}
	cout<<ans<<endl;
	return 0;
}