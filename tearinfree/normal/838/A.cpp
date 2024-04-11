#include <bits/stdc++.h>

int n,m,sum[2510][2510];
char str[2510];
bool chk[2501];

int Sum(int y1,int x1,int y2,int x2) {
	if(x1>m) x1=m+1;
	if(x2>m) x2=m;
	if(y1>n) y1=n+1;
	if(y2>n) y2=n;
	return sum[y2][x2]-sum[y1-1][x2]-sum[y2][x1-1]+sum[y1-1][x1-1];
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(str[j]-'0');
	}

	int MIN=987654321;
	for(int k=2;k<=2500;k++) {
		if(!chk[k]) {
			for(int j=k*k;j<=2500;j+=k) chk[j]=true;
			
			int cnt=0,tmp=k*k;
			for(int i=1;i<(n+k);i+=k) {
				for(int j=1;j<(m+k);j+=k) {
					int val=Sum(i,j,i+k-1,j+k-1);
					if(val<tmp-val) cnt+=val;
					else cnt+=tmp-val;
				}
			}
			if(MIN>cnt) MIN=cnt;
		}
	}
	printf("%d\n",MIN);

	return 0;
}