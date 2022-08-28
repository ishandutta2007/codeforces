//CF1558B
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
const int N = 4000060;
int n,p,f[N],g[N];
void ad(int&x,int y){
	x+=y;
	if(x>=p)
		x-=p;
}
int main()
{
	int i,j,x;
	cin>>n>>p;
	f[1]=1;
	x=0;
	for(i=1;i<=n;i++){
		if(i>1){
			ad(g[i],g[i-1]);
			f[i]=g[i];
		}
		ad(f[i],x);
		ad(x,f[i]);
		for(j=2;i*j<=n;j++){
			ad(g[i*j],f[i]);
			if(i*j+j<=n)
				ad(g[i*j+j],p-f[i]);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}