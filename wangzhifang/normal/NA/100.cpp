#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 1000
#define max_num 8
using namespace std;
typedef const int& ci;
int a[max_n+1];
int pos[max_num+1][max_n+1],cnt[max_num+1];
int pnt[max_n+1];
bool dp[max_n+1][1<<max_num][max_num];
bool check(ci n,ci p){
//	printf("check %d\n",p);
	const int num1=p>>3,num2=p&7,tmp=num1-1;
	if(!num1){
		int cntt=0;
		for(int i=0; ++i<=8; cntt+=bool(cnt[i]));
//		printf("%d %d\n",cntt,p<=cntt);
		return p<=cntt;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0,nnum,nbit,npos,pr1; ++i<=n; ){
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		if((npos=pnt[i])<num1)
			continue;
		nnum=a[i];
		nbit=1<<(nnum-1),pr1=pos[nnum][npos-tmp]-1;
//		printf("*%d %d\n",npos,num1);
//		printf("%d %d %d\n",tmp,npos,pr1);
		if(npos==num1)
			for(int j=-1; ++j<=255; ){
				(j&nbit)||(j|=nbit);
				for(int k=-1; ++k<=num2; ){
					if(dp[i][j][k])
						continue;
					dp[i][j][k]=dp[pr1][j^nbit][k];
//					i==2&&printf("dp[%d][%d][%d]\n",i,j,k);
				}
			}
		else{
			int pr2=pos[nnum][npos-num1]-1;
			for(int j=-1; ++j<=255; ){
				(j&nbit)||(j|=nbit);
				for(int k=-1; ++k<=num2; ){
					if(dp[i][j][k]||(dp[i][j][k]=dp[pr1][j^nbit][k]))
						continue;
					dp[i][j][k]=dp[pr2][j^nbit][k-1];
				}
			}
		}
//		for(int j=-1; ++j<=255; )
//			for(int k=-1; ++k<=num2; dp[i][j][k]&&printf("dp[%d][%d][%d]:%d\n",i,j,k,dp[i][j][k]));
	}
	return dp[n][255][num2];
}
int main(){
	int n;
	scanf("%d",&n),memset(cnt,0,sizeof(cnt));
	for(int i=0; ++i<=n; pos[a[i]][pnt[i]=++cnt[a[i]]]=i)
		scanf("%d",a+i);
//	for(int i=0; ++i<=n; printf("pnt[%d]:%d\n",i,pnt[i]));
//	for(;;);
	int l=1,r=(1+*min_element(cnt+1,cnt+9))*8;
	for(int mid; (mid=(l+r)>>1)>l; (check(n,mid)?l:r)=mid);
	printf("%d\n",l);
	return 0;
}