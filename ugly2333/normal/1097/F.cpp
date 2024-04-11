//CF1097F
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
const int N = 100055;
const int M = 7007;
int n,q,m=7000;
bitset<7007> f[N],a[M],b[M];
string s;
int main()
{
	int i,j,k,t;
	scanf("%d%d",&n,&q);
	for(i=1;i<=m;i=i+1)
		for(j=1;i*j<=m;j=j+1)
			a[i*j][i]=1;
	for(i=1;i<=m;i=i+1)
		b[i][i]=1;
	for(i=m;i;i=i-1)
		for(j=2;i*j<=m;j=j+1)
			b[i]^=b[i*j];
	while(q--){
		scanf("%d%d%d",&t,&i,&j);
		if(t==2||t==3)
			scanf("%d",&k);
		if(t==1)
			f[i]=a[j];
		if(t==2)
			f[i]=f[j]^f[k];
		if(t==3)
			f[i]=f[j]&f[k];
		if(t==4){
			k=(f[i]&b[j]).count();
			if(k&1)
				s+='1';
			else
				s+='0';
		}
	}
	cout<<s;
	return 0;
}