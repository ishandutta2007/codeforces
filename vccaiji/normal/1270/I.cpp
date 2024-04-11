#include<bits/stdc++.h>
using namespace std;
long long a[1<<9][1<<9];
long long b[1<<9][1<<9];
int x[110],y[110];
int main(){
	int k;
	scanf("%d",&k);
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++) scanf("%lld",&a[i][j]);
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]--;
		y[i]--;
	}
	for(int i=0;i<k;i++){
		for(int p=0;p<(1<<k);p++){
			for(int q=0;q<(1<<k);q++) b[p][q]=0;
		}
		for(int j=1;j<=t;j++){
			for(int p=0;p<(1<<k);p++){
				for(int q=0;q<(1<<k);q++){
					b[(p+(x[j]<<i))&((1<<k)-1)][(q+(y[j]<<i))&((1<<k)-1)]^=a[p][q];
				} 
			}
		}
		for(int p=0;p<(1<<k);p++){
			for(int q=0;q<(1<<k);q++) a[p][q]=b[p][q];
		}
	}
	int num=0;
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++){
			if(a[i][j]) num++;
		}
	} 
	printf("%d",num);
	return 0;
}