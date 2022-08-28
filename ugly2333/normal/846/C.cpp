// CF 846C
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
const int N = 5555;
int a[N];
LL s[N];
LL gs(int l,int r){//[l,r)
	return (LL)s[r-1]-s[l-1];
}
int main()
{
	int n,i,j,x,y,ansx,ansp,ansy;
	LL ans,b,c;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+1)
		s[i]=(LL)s[i-1]+a[i];
	ans=0;
	ansx=0;
	ansy=0;
	for(i=1;i<=n+1;i=i+1){
		b=0;
		c=0;
		x=i;
		y=i;
		for(j=1;j<=i;j=j+1){
			if(b<gs(1,j)-gs(j,i)){
				x=j;
				b=gs(1,j)-gs(j,i);
			}
		}
		for(j=i;j<=n+1;j=j+1){
			if(c<gs(i,j)-gs(j,n+1)){
				y=j;
				c=gs(i,j)-gs(j,n+1);
			}
		}
		//cout<<ans<<b<<c<<x<<y<<endl;
		if(ans<=(LL)b+c){
			ans=b+c;
			ansx=x;
			ansp=i;
			ansy=y;
		}
	}
	ansx--;
	ansp--;
	ansy--;
	printf("%d %d %d\n",ansx,ansp,ansy);
	return 0;
}