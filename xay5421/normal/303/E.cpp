#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,L[85],R[85],len,num[165];
double ans[85][85];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&L[i],&R[i]);
		num[++len]=L[i];
		num[++len]=R[i];
	}
	sort(num+1,num+1+len);
	len=unique(num+1,num+1+len)-num-1;
	rep(i,1,n){
		L[i]=lower_bound(num+1,num+1+len,L[i])-num;
		R[i]=lower_bound(num+1,num+1+len,R[i])-num;
	}
	rep(j,1,len-1){ // (j,j+1)
		static double dp[85][85];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		auto push=[&](int k){
			if(j+1<=L[k])return;
			double small=1.*(min(num[R[k]],num[j])-num[L[k]])/(num[R[k]]-num[L[k]]);
			double equal=1.*max(0,min(num[R[k]],num[j+1])-num[j])/(num[R[k]]-num[L[k]]);
			double big=1.-small-equal;
			per(x,n,0)per(y,n,0){
				dp[x+1][y]+=dp[x][y]*small;
				dp[x][y+1]+=dp[x][y]*equal;
				dp[x][y]=dp[x][y]*big;
			}
		};
		static double dp_bkup[20][85][85];
		function<void(int,int,int)>sol=[&](int l,int r,int dep){
			if(l==r){
				int i=l;
				if(L[i]<=j&&j<R[i]){
					double now_p=1.*(num[j+1]-num[j])/(num[R[i]]-num[L[i]]);
					rep(x,0,n)rep(y,0,n-x)if(dp[x][y]>0){
						rep(z,0,y){
							ans[i][x+z]+=dp[x][y]/(y+1)*now_p;
						}
					}
				}
				return;
			}
			int mid=(l+r)>>1;
			memcpy(dp_bkup[dep],dp,sizeof(dp));
			rep(i,mid+1,r)push(i);
			sol(l,mid,dep+1);
			memcpy(dp,dp_bkup[dep],sizeof(dp));
			rep(i,l,mid)push(i);
			sol(mid+1,r,dep+1);
		};
		sol(1,n,0);
	}
	rep(i,1,n){
		rep(j,0,n-1){
			printf("%.10f ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}