#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int b[510][510],n,d[510],m,ans[510];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		b[k1][k2]=1; b[k2][k1]=1;
		d[k1]++; d[k2]++;
	}
	for (int i=1;i<=n;i++) if (d[i]==n-1) ans[i]=2;
	int num=1;
	for (int i=1;i<=n;i++)
		if (ans[i]==0){
			ans[i]=num;
			for (int j=1;j<=n;j++)
				if (b[i][j]&&ans[j]==0) ans[j]=num;
			num+=2;
		}
	if (num>5){
		printf("No\n"); return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (abs(ans[i]-ans[j])<=1&&b[i][j]==0) {printf("No\n"); return 0;}
			else if (abs(ans[i]-ans[j])>1&&b[i][j]) {printf("No\n"); return 0;}
		}
	printf("Yes\n");
	for (int i=1;i<=n;i++) putchar('a'+ans[i]-1);
	printf("\n"); return 0;
}