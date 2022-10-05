#include<bits/stdc++.h>
using namespace std;
int x[3];
int n,k;
int a[3][110000];
const int p=998244353;
int u[8][110000];
int ans[1<<17];
int b[8][1<<17]={};
int main(){
	scanf("%d%d%d%d%d",&n,&k,&x[0],&x[1],&x[2]);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
	for(int i=0;i<3;i++) x[i]%=p;
	for(int i=0;i<8;i++){
		int o=0;
		for(int j=0;j<3;j++){
			if((i>>j)&1) o=(o+p-x[j])%p;
			else o=(o+x[j])%p;
		}
		u[i][0]=1;
		for(int j=1;j<=n;j++) u[i][j]=((long long)o*u[i][j-1])%p;
	}
	for(int i=0;i<8;i++){
		for(int j=1;j<=n;j++){
			int aa=0;
			for(int o=0;o<3;o++){
				if((i>>o)&1) aa^=a[o][j];
			}
			b[i][aa]++;
		}
		for(int j=0;j<k;j++){
			for(int uu=0;uu<(1<<k);uu++){
				if((uu>>j)&1){
					int xx=(b[i][uu]+b[i][uu^(1<<j)])%p,y=(b[i][uu^(1<<j)]+p-b[i][uu])%p;
					b[i][uu^(1<<j)]=xx;
					b[i][uu]=y;
				}
			}
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<3;j++){
			for(int o=0;o<8;o++){
				if((o>>j)&1){
					int xx=((long long)(b[o^(1<<j)][i]+b[o][i])*((p+1)>>1))%p,y=((long long)(b[o^(1<<j)][i]+p-b[o][i])*((p+1)>>1))%p;
				    b[o^(1<<j)][i]=xx;
				    b[o][i]=y;
				}
			}
		}
		ans[i]=1;
		for(int j=0;j<8;j++) ans[i]=((long long)ans[i]*u[j][b[j][i]])%p;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<(1<<k);j++){
			if((j>>i)&1){
				int xx=((long long)(ans[j^(1<<i)]+ans[j])*((p+1)>>1))%p,y=((long long)(ans[j^(1<<i)]+p-ans[j])*((p+1)>>1))%p;
				ans[j^(1<<i)]=xx;
				ans[j]=y;
			}
		}
	}
	for(int i=0;i<(1<<k);i++) printf("%d ",ans[i]);
	return 0;
}