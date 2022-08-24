#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,A[60][60],pd[60][60],w[60];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%d",&A[i][j]);
	for (int now=1;now<=n;now++)
		for (int i=1;i<=n;i++){
			if (w[i]) continue;
			int flag=0;
			for (int j=1;j<=n;j++){
				if (A[i][j]!=0&&A[i][j]!=now) flag=1;
				if (A[j][i]!=0&&A[j][i]!=now) flag=1;
			}
			if (flag) continue;
			w[i]=now;
			for (int j=1;j<=n;j++){
				A[i][j]=0; A[j][i]=0;
			}
			break;
		}
	for (int i=1;i<=n;i++) printf("%d ",w[i]);
	printf("\n");
	return 0;
}