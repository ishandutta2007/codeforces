//CF1383D
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
const int N = 1e6+16;
const int MO = 1e9+7;
int n,f[N],g[N],t[N],r;
char s[N];
void go(int x,int y){
	r-=t[x];
	if(r<0)
		r+=MO;
	r+=y;
	if(r>=MO)
		r-=MO;
	t[x]=y;
}
int main()
{
	int i,o,x,y,z;
	scanf("%s",s+1);
	n=strlen(s+1);
	z=1;
	while(s[z]=='0'){
		z++;
	}
	if(z>n){
		printf("%d",n);
		return 0;
	}
	o=0;
	for(i=z;i<=n;i=i+1){
		if(s[i]=='0'){
			o++;
			f[i]=(f[i-1]+x)%MO;
			g[i]=g[i-1];
			go(o,x);
		}
		else{
			o=0;
			g[i]=(g[i-1]+r+1)%MO;
			f[i]=g[i];
			x=f[i];
		}
		//cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
	}
	printf("%d",(LL)f[n]*z%MO);
	return 0;
}