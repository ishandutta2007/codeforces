//CF83E
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
const int N = 222222;
const int M = 1<<21;
const int inf = 1e9;
void cmax(int&x,int y){
	if(x<y)
		x=y;
}
char ch[22];
int n,m,p,a[N],c[M+22],f[M+22];
int pre(int i,int j){
	return a[i]>>(m-j);
}
int suf(int i,int j){
	return (a[i]&((1<<j)-1))|(1<<j);
}
int main()
{
	int i,j,o,e;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		m=strlen(ch+1);
		a[i]=1;
		for(j=1;j<=m;j=j+1)
			a[i]=a[i]*2+ch[j]-'0';
	}
	for(i=1;i<M;i=i+1){
		c[i]=c[i>>1]+1;
		f[i]=-inf;
	}
	f[1]=0;
	for(i=2;i<=n;i=i+1){
		o=0;
		for(j=1;j<=m;j=j+1)
			if(suf(i-1,j)==pre(i,j))
				o=j;
		p+=o;
		e=0;
		for(j=0;j<=m;j=j+1)
			cmax(e,f[pre(i,j)]+j);
		for(j=0;j<=m;j=j+1)
			cmax(f[suf(i-1,j)],e-o);
	}
	o=0;
	for(i=1;i<M;i=i+1)
		o=max(o,f[i]);
	cout<<n*m-(o+p);
	return 0;
}