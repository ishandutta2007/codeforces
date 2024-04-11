//CF 850B
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
int n,a[555555],x,y,h[1111111],c[1111111];
LL s,p,minp,sx,sy,ans;
int main()
{
	int i,j,o;
	for(i=2;i<=1e6;i=i+1)
		if(!h[i])
			for(j=i*2;j<=1e6;j=j+i)
				h[j]=1;
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		c[a[i]]++;
	}
	ans=(LL)n*x;
	o=0;
	for(j=2;j<=1e6;j=j+1){
		if(h[j]||(j>=1e3&&n>=1e4&&c[j]<100&&o>333)||(j>=1e3&&n>=1e4&&c[j]<2))
			continue;
		o++;
		s=0;
		sx=0;
		sy=0;
		minp=j;
		for(i=1;i<=n&&s<ans;i=i+1){
			if(a[i]%j==0){
				sy++;
				minp=0;
				continue;
			}
			p=j-a[i]%j;
			if(p<minp)
				minp=p;
			if((LL)p*y<=x){
				sy++;
				s+=p*y;
			}
			else{
				sx++;
				s+=x;
			}
		}
		if(!sy&&s<ans){
			s-=x;
			s+=minp*y;
		}
		if(s<ans){
			//cout<<j<<s<<endl;
			ans=s;
		}
	}
	cout<<ans<<endl;
	return 0;
}