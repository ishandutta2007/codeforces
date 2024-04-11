//CF 97D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 155;
bitset<N*N> A,B,E,L,R,U,D;
int n,m,k,a[N][N];
char ch[111111];
int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i=i+1){
		scanf("%s",ch);
		for(j=0;j<m;j=j+1){
			if(ch[j]!='#')
				A[i*m+j]=1,a[i][j]=1;
			if(ch[j]=='E')
				E[i*m+j]=1;
		}
		for(j=1;j<m;j=j+1)
			if(a[i][j]&&!a[i][j-1])
				L[i*m+j]=1;
		for(j=0;j<m-1;j=j+1)
			if(a[i][j]&&!a[i][j+1])
				R[i*m+j]=1;
	}
	for(j=0;j<m;j=j+1){
		for(i=1;i<n;i=i+1)
			if(a[i][j]&&!a[i-1][j])
				U[i*m+j]=1;
		for(i=0;i<n-1;i=i+1)
			if(a[i][j]&&!a[i+1][j])
				D[i*m+j]=1;
	}
	scanf("%s",ch);
	B=A;
	for(i=0;i<=k;i=i+1){
		if(B==E){
			cout<<i;
			return 0;
		}
		if(i==k){
			cout<<-1;
			return 0;
		}
		if(ch[i]=='L')
			B=(B>>1)|(L&B);
		if(ch[i]=='R')
			B=(B<<1)|(R&B);
		if(ch[i]=='U')
			B=(B>>m)|(U&B);
		if(ch[i]=='D')
			B=(B<<m)|(D&B);
		B&=A;
	}
	return 0;
}