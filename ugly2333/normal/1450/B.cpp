//CF1450B
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
const int N = 111;
int n,k,x[N],y[N];
bool ok(int i,int j){
	return max(x[i]-x[j],x[j]-x[i])+max(y[i]-y[j],y[j]-y[i])<=k;
}
int main()
{
	int T,i,j,o,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i=i+1)
			scanf("%d%d",x+i,y+i);
		f=0;
		for(i=1;i<=n;i=i+1){
			o=1;
			for(j=1;j<=n;j=j+1)
				o&=ok(i,j);
			f|=o;
		}
		if(f)
			cout<<1<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}