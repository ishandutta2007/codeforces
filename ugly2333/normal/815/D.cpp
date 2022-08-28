// CF 815D
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
int ab[555555],ac[555555];
LL bc[555555],cb[555555];
int main()
{
	int n,p,q,r,i,x,y,z;
	LL ans,s;
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		ab[x]=max(ab[x],y);
		ac[x]=max(ac[x],z);
		bc[y]=max(bc[y],(LL)z);
		cb[z]=max(cb[z],(LL)y);
	}
	for(i=p;i>0;i=i-1){
		ab[i]=max(ab[i],ab[i+1]);
		ac[i]=max(ac[i],ac[i+1]);
	}
	for(i=q;i>0;i=i-1)
		bc[i]=max(bc[i],bc[i+1]);
	for(i=1;i<=q+5;i=i+1)
		bc[i]+=(LL)bc[i-1];
	for(i=r;i>0;i=i-1)
		cb[i]=max(cb[i],cb[i+1]);
	for(i=1;i<=r+5;i=i+1)
		cb[i]+=(LL)cb[i-1];
	ans=0;
	for(i=1;i<=p;i=i+1){
		y=ab[i];
		z=ac[i];
		if(y==q||z==r)
			continue;
		ans+=(LL)(q-y)*(r-z);
		if(bc[y+1]-bc[y]>z){
			s=bc[y]+cb[z]-(LL)y*z;
			s=bc[q+1]-s;
			ans-=s;
		}
	}
	cout<<ans<<endl;
	return 0;
}