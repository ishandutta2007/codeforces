#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
ll sum[N],sqs[N];
int x[N][N];
int main(){
	int m,k;
	scanf("%i %i",&m,&k);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			scanf("%i",&x[i][j]);
			sum[i]+=x[i][j];
			sqs[i]+=(ll)x[i][j]*x[i][j];
		}
	}
	ll step=(sum[k]-sum[1])/(k-1);
	for(int i=2;i<k;i++){
		if(sum[i]!=sum[1]+step*(i-1)){
			int add=(sum[i-1]+sum[i+1]-2*sum[i])/2;
			sum[i]=(sum[i-1]+sum[i+1])/2;

			ll sumv2=0;
			int p=1;
			if(i<=3)p=i+1;
			sumv2=(sqs[p+2]+sqs[p]-2*sqs[p+1])/2;

			ll now=sqs[i];
			sqs[i]=(sqs[i+1]+sqs[i-1]-2*sumv2)/2;
			for(int j=1;j<=m;j++){
				ll tmp=now-(ll)x[i][j]*x[i][j]+(ll)(x[i][j]+add)*(x[i][j]+add);
				if(tmp==sqs[i]){
					printf("%i %i\n",i-1,x[i][j]+add);
					break;
				}
			}
			break;
		}
	}
	fflush(stdout);
	return 0;
}