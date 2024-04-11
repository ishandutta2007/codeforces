#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

const int maxn=500007;
int cnt=1,q[maxn];
LL sum=0;

int main(){
	int Q,n=0;
	scanf("%d",&Q);
	while(Q--){
		int chr;
		scanf("%d",&chr);
		if (chr==1){
			n++;
			scanf("%d",&q[n]);
		}
		else{
			while((sum+q[n])>=(LL)cnt*q[cnt]&&cnt<n){
				sum+=q[cnt];
				cnt++;
			}
			printf("%.8lf\n",1.0*q[n]-1.0*(sum+q[n])/cnt);
		}
	}
	return 0;
}