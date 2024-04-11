#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int n,x[N],y[N],ans;
struct Ask{
	int x,y;
	Ask(int _x=0,int _y=0){
		x=_x;y=_y;
	}
}A[N];
int C(int x,int y){
	int ans=1;
	for (int i=1;i<=y;i++)ans=ans*(x-i+1)/i;
	return ans;
}
int check(Ask x){
	if (x.y>=0&&x.x>=0)return 1;
	if (x.y>=0&&x.x<0)return 2;
	if (x.y<0&&x.x<0)return 3;
	return 4;
}
int cmp(Ask x,Ask y){
	if (check(x)!=check(y))return check(x)<check(y);
	return x.y*y.x<x.x*y.y; 
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	for (int i=1;i<=n;i++){
		int tot=0;
		for (int j=1;j<=n;j++)
			if (i!=j)A[++tot].x=x[i]-x[j],A[tot].y=y[i]-y[j];
		sort(A+1,A+tot+1,cmp);
		for (int j=1;j<=tot;j++)A[j+tot]=A[j];
		for (int j=1,k=1;j<=tot;j++){
			while (k<j+tot&&A[k].x*A[j].y-A[k].y*A[j].x<=0)k++;
			ans+=C(tot-k+j,3);
		}
	}
	printf("%lld\n",C(n,5)*5-ans);
}