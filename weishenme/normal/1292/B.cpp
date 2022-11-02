#include<bits/stdc++.h>
using namespace std;
#define int long long
int x0,y0,ax,ans,tot,ay,bx,by,s,t,T,x[105],y[105];
void insert(int a,int b){
	x[++tot]=a;y[tot]=b;
}
signed main(){
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&s,&t,&T);
	while (x0<=2e16&&y0<=2e16){
		insert(x0,y0);
		x0=ax*x0+bx;
		y0=ay*y0+by;
	}
	for (int i=1;i<=tot;i++)
		for (int j=i;j<=tot;j++)
			if (min(abs(s-x[j])+abs(t-y[j]),abs(s-x[i])+abs(t-y[i]))+abs(x[i]-x[j])+abs(y[i]-y[j])<=T)ans=max(ans,j-i+1);
	printf("%lld\n",ans);
}