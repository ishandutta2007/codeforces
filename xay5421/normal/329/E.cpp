// created: Mon Mar  8 15:45:04 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=100005;
int n,x[N],y[N],z[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	int d=1e9;
	rep(i,1,n)z[i]=x[i];
	sort(z+1,z+1+n),d=min(d,z[(n+1)/2+1]-z[(n+1)/2]);
	if(n&1)d=min(d,z[(n+1)/2]-z[(n+1)/2-1]);
	int midx=z[(n+1)/2];
	rep(i,1,n)z[i]=y[i];
	sort(z+1,z+1+n),d=min(d,z[(n+1)/2+1]-z[(n+1)/2]);
	if(n&1)d=min(d,z[(n+1)/2]-z[(n+1)/2-1]);
	int midy=z[(n+1)/2];
	LL res=0;
	int flg=0,cnt[2][2]={{0,0},{0,0}};
	rep(i,1,n){
		res=res+abs(x[i]-midx)+abs(y[i]-midy);
		++cnt[x[i]<=midx][y[i]<=midy];
		if(x[i]==midx&&y[i]==midy)flg=1;
	}
	if((n%2==0||flg)&&cnt[0][0]&&cnt[0][1]&&cnt[1][0]&&cnt[1][1])res-=d;
	printf("%lld\n",res*2);
	return 0;
}