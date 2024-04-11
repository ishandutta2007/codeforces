// author: xay5421
// created: Sun Oct 17 20:00:50 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int n,K,num[N],col[N][N];
int main(){
	scanf("%d%d",&n,&K);
	int ans=0,pw=1;
	while(pw<n)++ans,pw*=K;
	per(i,n,1){
		num[i]=n-i;
	}
	per(i,n,1){
		rep(j,i+1,n){
			int k1=num[i],k2=num[j];
			rep(_,1,ans){
				if(k1%K>k2%K){
					col[i][j]=_;
					break;
				}
				k1/=K,k2/=K;
			}
		}
	}
	printf("%d\n",ans);
	rep(i,1,n)rep(j,i+1,n)printf("%d ",col[i][j]);
	return 0;
}