#include <bits/stdc++.h>
using namespace std;

int N, K, i, j, k, ans=-1<<30, tmp, a[202], b[202], arr[202];

int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=N;i++){
		for(j=i;j<=N;j++){
			int aa = 0, bb = 0;
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			for(k=1;k<=N;k++){
				if(k>=i&&k<=j) b[bb++]=arr[k];
				else a[aa++]=arr[k];
			}
			sort(a,a+aa,greater<int>());
			sort(b,b+bb);
			for(k=0;k<min(min(aa,bb),K);k++){
				if(a[k]>b[k]) swap(a[k],b[k]);
			}
			tmp = 0;
			for(k=0;k<bb;k++) tmp+=b[k];
			ans = max(ans, tmp);
		}
	}
	printf("%d\n",ans);
	getchar(); getchar();
}