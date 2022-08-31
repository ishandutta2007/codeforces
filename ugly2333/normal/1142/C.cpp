//CF1142C
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
int n,sz,a[N];
LL x[N],y[N];
map<int,LL> M;
map<int,LL>::iterator it;
bool chk(int i,int j,int k){
	return (y[j]-y[i])*(x[k]-x[j])<=(y[k]-y[j])*(x[j]-x[i]);
}
int main()
{
	int i,o,u;
	LL e;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&o,&u);
		e=(LL)u-(LL)o*o;
		if(M.find(o)!=M.end())
			M[o]=max(M[o],e);
		else
			M[o]=e;
	}
	i=0;
	for(it=M.begin();it!=M.end();it++){
		i++;
		x[i]=(*it).first;
		y[i]=(*it).second;
	}
	n=i;
	a[++sz]=1;
	for(i=2;i<=n;i=i+1){
		while(sz>1&&chk(a[sz-1],a[sz],i)){
			a[sz--]=0;
		}
		a[++sz]=i;
	}
	cout<<sz-1;
	return 0;
}