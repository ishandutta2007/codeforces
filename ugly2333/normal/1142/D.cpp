//CF1142D
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
const int N = 111111;
char ch[N];
int n,t[N],a[N],c[22][22],f[N][22][2];
LL s;
int cnt(int x,int y){
	if(x==y)
		return x;
	return x+cnt((x+1)%11,y);
}
int solve(int i,int j,int k){
	if(i>n||a[i]>=j)
		return 0;
	if(f[i][j][k])
		return f[i][j][k];
	return f[i][j][k]=1+solve(i+1,(t[k]+c[t[k^1]+1][j-1]+a[i]+1)%11,k^1);
}
int main()
{
	int i,j,k,o,x;
	for(i=0;i<=11;i=i+1)
		for(j=0;j<=10;j=j+1)
			c[i][j]=cnt(i,j);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i=i+1){
		a[i]=ch[i]-'0';
		if(a[i])
			s++;
	}
	t[0]=10;
	t[1]=9;
	for(i=1;i<=n;i=i+1)
		if(a[i])
			s+=solve(i+1,a[i],1);
	cout<<s;
	return 0;
}