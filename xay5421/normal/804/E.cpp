// author: xay5421
// created: Mon Apr 26 16:13:39 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1005;
int n,a[4],b[4];
const int A[6][2]={{0,1},{2,3},{0,3},{1,2},{0,2},{1,3}};
void deal1(int flg){
	rep(i,0,5){
		if(flg&&i<2)printf("%d %d\n%d %d\n%d %d\n",a[A[i][0]],n,a[A[i][0]],a[A[i][1]],a[A[i][1]],n);
		else printf("%d %d\n",a[A[i][0]],a[A[i][1]]);
	}
}
const int B[16][2]={{0,0},{1,1},{0,1},{1,0},{0,2},{1,3},{0,3},{1,2},{2,0},{3,1},{2,1},{3,0},{2,2},{3,3},{2,3},{3,2}};
void deal2(int flg){
	rep(i,0,15){
		if(0)printf("%d %d\n%d %d\n",a[B[i][0]],n,b[B[i][1]],n);
		else printf("%d %d\n",a[B[i][0]],b[B[i][1]]);
	}
}
int main(){
	scanf("%d",&n);
	if((n&3)>1)puts("NO"),exit(0);else puts("YES");
	for(int i=1;i<n;i+=4){
		rep(k,0,3)a[k]=i+k;
		deal1((n&3)==1);
	}
	for(int i=1;i<n;i+=4){
		for(int j=i+4;j<n;j+=4){
			rep(k,0,3)a[k]=i+k,b[k]=j+k;
			deal2((n&3)==1);
		}
	}
	return 0;
}