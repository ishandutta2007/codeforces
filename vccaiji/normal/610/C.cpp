#include<bits/stdc++.h>//luogu
using namespace std;
int a[1<<9][1<<9];
int main(){
	int k;
	scanf("%d",&k);
	a[0][0]=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<(1<<(i-1));j++){
			for(int jj=0;jj<(1<<(i-1));jj++){
				a[j^(1<<(i-1))][jj^(1<<(i-1))]=1^a[j][jj];
				a[j][jj^(1<<(i-1))]=a[j][jj];
				a[j^(1<<(i-1))][jj]=a[j][jj];
			}
		}
	}
	for(int j=0;j<(1<<k);j++){
		for(int jj=0;jj<(1<<k);jj++){
			if(a[j][jj]) printf("*");
			else printf("+");
		}
		printf("\n");
	}
	return 0;
}