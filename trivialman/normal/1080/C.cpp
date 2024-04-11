#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
//#define N 200010// 
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int t;
LL n,m,x1,x2,y1,y2,x3,x4,y3,y4;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>x1>>y1>>x2>>y2;
		cin>>x3>>y3>>x4>>y4;
		
		LL lx=max(x1,x3),rx=min(x2,x4),ly=max(y1,y3),ry=min(y2,y4);
		LL xlen=max(0ll,rx-lx+1),ylen=max(0ll,ry-ly+1);
		
		LL ans=(n*m+1)/2;//white
		
		LL pourb=(y4-y3+1)*(x4-x3+1);
		ans-=pourb/2;
		if(pourb%2==1){
			if((x3+y3)%2==0)--ans;
		}
		
		LL pourw=(y2-y1+1)*(x2-x1+1);
		ans+=pourw/2;
		if(pourw%2==1)
			if((x1+y1)%2==1)++ans;
		
		LL npourw=xlen*ylen;
		ans-=npourw/2;
		if(xlen*ylen%2==1)
			if((lx+ly)%2==1)--ans;
		
		//cout<<xlen<<" "<<ylen<<endl;
		cout<<ans<<" "<<n*m-ans<<endl;
	}
	return 0;
}