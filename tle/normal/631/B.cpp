#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,a[5001][5001],t1[100001],t2[100001],t3[100001];
bool rr[5001],cc[5001],chk[100001];
inline void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&t1[i],&t2[i],&t3[i]);
	for(int i=k;i>=1;i--){
		if(t1[i]==1){
			if(rr[t2[i]]) chk[i]=true;
			rr[t2[i]]=true;
		}
		if(t1[i]==2){
			if(cc[t2[i]]) chk[i]=true;
			cc[t2[i]]=true;
		}
	}
	for(int i=1;i<=k;i++){
		if(chk[i]) continue;
		if(t1[i]==1){
			for(int j=1;j<=m;j++)
				a[t2[i]][j]=t3[i];
		}
		if(t1[i]==2){
			for(int j=1;j<=n;j++)
				a[j][t2[i]]=t3[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
		putchar('\n');
	}
}
int main(){
	init();
	return 0;
}