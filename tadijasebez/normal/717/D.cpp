#include <bits/stdc++.h>
using namespace std;
#define ldb double
const int N=205;
ldb p[N],ans[N][N],tmp[N][N];
void cl(int x){for(int i=0;i<=x;i++)for(int j=0;j<=x;j++)tmp[i][j]=0;}
void upd(int x){for(int i=0;i<=x;i++)for(int j=0;j<=x;j++)ans[i][j]=tmp[i][j];}
int main(){
	int n,x;
	scanf("%i %i",&n,&x);
	for(int i=0;i<=x;i++)cin>>p[i];
	int o=1;while(o<=x)o*=2;
	x=o-1;
	for(int i=0;i<=x;i++)ans[i][i]=1;
	for(int z=30;~z;z--){
		cl(x);
		for(int i=0;i<=x;i++){
			for(int j=0;j<=x;j++){
				for(int k=0;k<=x;k++){
					tmp[i][k]+=ans[i][j]*ans[j][k];
				}
			}
		}
		upd(x);
		if(n>>z&1){
			cl(x);
			for(int i=0;i<=x;i++){
				for(int j=0;j<=x;j++){
					for(int k=0;k<=x;k++){
						tmp[i][j^k]+=ans[i][j]*p[k];
					}
				}
			}
			upd(x);
		}
	}
	ldb sol=0;
	for(int i=1;i<=x;i++)sol+=ans[0][i];
	cout<<fixed<<setprecision(12)<<sol<<"\n";
	return 0;
}