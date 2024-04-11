//CF 985F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 200022;
const int M = 26;
const int mod = 1e9+21;
int pw[N],h[N][M];
int n,q,a[M],b[M];
char ch[N];
int geth(int l,int r,int j){
	return (LL)(h[r][j]-h[l-1][j]+mod)*pw[n-r]%mod;
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d%s",&n,&q,ch+1);
	pw[0]=1;
	for(i=1;i<=n;i=i+1){
		pw[i]=pw[i-1]*2%mod;
		h[i][ch[i]-'a']=pw[i];
	}
	for(i=1;i<=n;i=i+1)
		for(j=0;j<M;j=j+1)
			h[i][j]=(h[i][j]+h[i-1][j])%mod;
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		for(j=0;j<M;j=j+1)
			a[j]=geth(x,x+z-1,j),b[j]=geth(y,y+z-1,j);
		sort(a,a+M),sort(b,b+M);
		for(j=M;j--;)
			if(a[j]!=b[j])
				break;
		if(j<0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}