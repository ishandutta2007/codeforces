#include <bits/stdc++.h>
using namespace std;
int x[7],xa[7],xb[7],xpt;
int y[7],ya[7],yb[7],ypt;
int a[13][13];
int main(){
	for(int i=1;i<=6;i++){
		cin>>x[i]>>y[i];
		xa[i]=x[i];
		ya[i]=y[i];
	}
	sort(xa+1,xa+7);
	sort(ya+1,ya+7);
	xa[0]=ya[0]=-1;
	for(int i=1;i<=6;i++)	if(xa[i]!=xa[i-1])	xb[++xpt]=xa[i];
	for(int i=1;i<=6;i++)	if(ya[i]!=ya[i-1])	yb[++ypt]=ya[i];
	for(int i=1;i<=6;i++){
		x[i]=lower_bound(xb+1,xb+xpt+1,x[i])-xb;
		y[i]=lower_bound(yb+1,yb+ypt+1,y[i])-yb;
//		cout<<x[i]<<" "<<y[i]<<endl;
	}
	for(int i=x[1]*2;i<=x[2]*2;i++)	for(int j=y[1]*2;j<=y[2]*2;j++)	a[i][j]=1;
	for(int i=x[3]*2;i<=x[4]*2;i++)	for(int j=y[3]*2;j<=y[4]*2;j++)	a[i][j]=2;
	for(int i=x[5]*2;i<=x[6]*2;i++)	for(int j=y[5]*2;j<=y[6]*2;j++)	a[i][j]=2;
	for(int i=1;i<=12;i++)
		for(int j=1;j<=12;j++)
			if(a[i][j]==1)
				return puts("YES"),0;
	puts("NO");
	return 0;
}