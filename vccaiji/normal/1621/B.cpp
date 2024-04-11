#include<bits/stdc++.h> 
using namespace std;
int main(){
	int t,n;
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++){
		scanf("%d",&n);
		int minn=1000001000,maxx=-1;
		int minncost,maxxcost,lcost;
		for(int i=1;i<=n;i++){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			if(minn>l) minncost=c;
			if(maxx<r) maxxcost=c;
			if(minn==l) minncost=min(minncost,c);
			if(maxx==r) maxxcost=min(maxxcost,c);
			if((minn>l)||(maxx<r)) lcost=2010000000;
			if((minn>=l)&&(maxx<=r)) lcost=min(lcost,c);
			printf("%d\n",min(minncost+maxxcost,lcost));
			maxx=max(maxx,r);
			minn=min(minn,l);
		}
	}
	return 0;
}