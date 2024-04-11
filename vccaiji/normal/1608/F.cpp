#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int C[2100][2100]={};
int b[2100];
int ans[102][2100]={};
int ans2[102][2100];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%p; 
	}
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=b[1]-k;i<=b[1]+k;i++){
		if(i==0) ans[i+k-b[1]][1]=1;
		if(i==1) ans[i+k-b[1]][0]=1;
	} 
	for(int i=2;i<=n;i++){
		for(int j=0;j<=2*k;j++){
			for(int jj=0;jj<=i-1;jj++){
				ans2[j][jj]=ans[j][jj]; 
				ans[j][jj]=0;
			} 
		}
		for(int j=0;j<=2*k;j++){
			int t=j-(b[i]-b[i-1]);
			if((t<0)||(t>2*k)) continue;
			for(int jj=0;jj<=i-1;jj++){
				ans[t][jj]=(ans[t][jj]+(long long)ans2[j][jj]*(jj+t+b[i]-k))%p;
				ans[t][jj+1]=(ans[t][jj+1]+(long long)ans2[j][jj]*(jj+1))%p;
			}
		}
		for(int j=0;j<=2*k-1;j++)
			for(int jj=0;jj<=i-2;jj++) ans2[j+1][jj]=(ans2[j+1][jj]+ans2[j][jj+1])%p;
		for(int j=0;j<=2*k;j++){
			int o=b[i]+j-k;
			if(o<0) continue;
			for(int jj=0;jj<=i-1;jj++){
				int y=o-1-b[i-1]+k;
				if(y<0) continue;
				if(y<=2*k){
					ans[j][jj]=(ans[j][jj]+ans2[y][jj])%p;
					continue;
				}
				int jjj=jj+y-2*k;
				if(jjj>i-1) continue;
				ans[j][jj]=(ans[j][jj]+ans2[2*k][jjj])%p;
			} 
		}
	}
	int anss=0;
	for(int i=0;i<=2*k;i++){
		int t=b[n]+i-k;
		if((t<0)||(t>n)) continue;
		for(int j=0;j<=n-t;j++) anss=(anss+(long long)ans[i][j]*C[n-t][j])%p;
	}
	printf("%d",anss);
	return 0;
}