#include<bits/stdc++.h>
using namespace std;
const int maxn=55,maxV=100005;
int n,m,lst,k;
int val[maxn][maxn],rw[maxV],ln[maxV];
inline int trans(int v){
	int r=0,c=0;
	while(v)
		r|=((v&1)<<c),c+=2,v>>=1;
	return r;
}
int main(){
	scanf("%d%d",&n,&k);
	m=1;
	while(m<n)
		m<<=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			val[i][j]=trans((i-1)^((i-1)/2))^(trans((j-1)^((j-1)/2))<<1),rw[val[i][j]]=i,ln[val[i][j]]=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
			printf("%d%c",val[i][j+1]^val[i][j],j==n-1? '\n':' ');
	for(int i=1;i<n;i++)
		for(int j=1;j<=n;j++)
			printf("%d%c",val[i+1][j]^val[i][j],j==n? '\n':' ');
	fflush(stdout);
	int lst=0,x;
	while(k--){
		scanf("%d",&x),x^=lst;
		printf("%d %d\n",rw[x],ln[x]),fflush(stdout),lst=x;
	}
	return 0;
}