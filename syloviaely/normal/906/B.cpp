#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
int n,m;
int A[110000],len;
map<int,int>M[110000];
int gox[4]={1,0,-1,0},goy[4]={0,1,0,-1};
int check(int k1,int k2){
	return k1>=1&&k1<=n&&k2>=1&&k2<=m;
}
int getw(int k1,int k2){
	//cout<<k1<<" "<<k2<<endl;
	return (k1-1)*m+k2;
}
int connect(int k1,int k2){
	return M[k1][k2];
}
int qua(int k1,int k2){
	//cout<<"qua "<<k1<<" "<<k2<<endl;
	for (int i=0;i<4;i++)
		if (check(k1+gox[i],k2+goy[i])&&connect(A[getw(k1,k2)],A[getw(k1+gox[i],k2+goy[i])])) return 0;
	return 1;
}
int main(){
	while (	scanf("%d%d",&n,&m)!=EOF){
	len=0;
	for (int i=1;i<=n*m;i++) M[i].clear();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=0;k<4;k++)
				if (check(i+gox[k],j+goy[k])) M[getw(i,j)][getw(i+gox[k],j+goy[k])]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) A[getw(i,j)]=(i-1)*m+j;
	}
	for (int i=1;i<=n;i++) if (i&1){
		int num=A[getw(i,1)];
		for (int j=1;j<m;j++) A[getw(i,j)]=A[getw(i,j+1)];
		A[getw(i,m)]=num;
	}
	if (n<m)
	for (int i=1;i<=n;i++) if (i&1){
		int num=A[getw(i,1)];
		for (int j=1;j<m;j++) A[getw(i,j)]=A[getw(i,j+1)];
		A[getw(i,m)]=num;
	}
	for (int i=1;i<=m;i++) if (i&1){
		int num=A[getw(n,i)];
		for (int j=n-1;j;j--) A[getw(j+1,i)]=A[getw(j,i)];
		A[getw(1,i)]=num;
	}
	if (n>=m)
	for (int i=1;i<=m;i++) if (i&1){
		int num=A[getw(n,i)];
		for (int j=n-1;j;j--) A[getw(j+1,i)]=A[getw(j,i)];
		A[getw(1,i)]=num;
	}
	if (n==3&&m==3){
		A[1]=8; A[2]=3; A[3]=4; A[4]=1; A[5]=5; A[6]=9; A[7]=6; 
		A[8]=7; A[9]=2;
	}
	if (n==1||m==1){
		int tot=n*m; len=0;
		for (int i=1;i<=tot;i++) if (i&1) A[++len]=i;
		for (int i=1;i<=tot;i++) if (i%2==0) A[++len]=i;
	}
	if (n*m==4){
		A[1]=3; A[2]=1; A[3]=4; A[4]=2;
	}
	int flag=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (qua(i,j)==0) flag=1;
	if (flag) printf("NO\n"); else {
		printf("YES\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) printf("%d ",A[(i-1)*m+j]);
			printf("\n");
		}
	}
	}
}