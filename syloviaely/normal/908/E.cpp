#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
long long A[1100];
int B[1100],father[1100];
int C[1100][1100];
const int mo=1e9+7;
int n,m;
char ch[1100];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int findfather(int k1){
	if (father[k1]==k1) return k1;
	return father[k1]=findfather(father[k1]);
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for (int j=1;j<=m;j++) if (ch[j]=='1') A[j]|=(1ll<<i-1);
	}
	for (int i=0;i<=m;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	B[0]=1;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=i;j++)
			B[i]=(B[i]+1ll*B[i-j]*C[i-1][j-1])%mo;
	for (int i=1;i<=m;i++) father[i]=i;
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (A[j]==A[i])
				father[i]=findfather(father[j]);
	int ans=1;
	for (int i=1;i<=m;i++)
		if (father[i]==i){
			int num=0;
			for (int j=1;j<=m;j++)
				if (findfather(father[j])==i) num++;
			//cout<<num<<endl;
			ans=1ll*ans*B[num]%mo;
		}
	cout<<ans<<endl;
}