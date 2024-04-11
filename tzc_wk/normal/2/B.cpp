#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+9;
int r[1010][1010][2],f[1010][1010],pr[1010][1010],p[2020],ci,cj;
int main(){
	int n,num,x,i,j;
	int ans,kp;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			scanf("%d",&num);
			if(num==0) {
				r[i][j][0] = 1000000;
				r[i][j][1] = 1000000;
				ci = i;
				cj = j;
			} else {
				x = num;
				while(x%2==0) {
					r[i][j][0]++;
					x >>= 1;
				}
				x = num;
				while(x%5==0) {
					r[i][j][1]++;
					x /= 5;
				}
			}
		}
	}
	ans = INF;
	kp=0;
	for(int q=0; q<2; q++) {
		memset(f,0,sizeof(f));
		memset(pr,0,sizeof(pr));
		f[1][1] = r[1][1][q];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i+j==2) continue;
				else if(i==1) {
					f[i][j] = f[i][j-1] + r[i][j][q];
					pr[i][j] = 2;
				} else if(j==1) {
					f[i][j] = f[i-1][j] + r[i][j][q];
					pr[i][j] = 1;
				} else if(f[i-1][j] < f[i][j-1]) {
					f[i][j] = f[i-1][j] + r[i][j][q];
					pr[i][j] = 1;
				} else {
					f[i][j] = f[i][j-1]  + r[i][j][q];
					pr[i][j] = 2;
				}
			}
		}
		if(f[n][n] < ans) {
			ans = f[n][n];
			kp = 0;
			i=n;
			j=n;
			while((i+j)>2) {
				kp++;
				p[kp] = pr[i][j];
				if(p[kp]==1) i--;
				else j--;
			}
		}
	}
	if((ans>1) && (ci>0)) {
		printf("1\n");
		for(i=1; i<=ci-1; i++) printf("D");
		for(i=1; i<=cj-1; i++) printf("R");
		for(i=ci; i<=n-1; i++) printf("D");
		for(i=cj; i<=n-1; i++) printf("R");
		printf("\n");
	} else {
		printf("%d\n",ans);
		for(i=kp; i>=1; i--) {
			printf("%c",p[i]==1?'D':'R');
		}
		printf("\n");
	}
	return 0;
}