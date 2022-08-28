//CF1552F
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
const int N = 444444;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int n,x[N],y[N],z[N],m,p[N],f[N],t[N];
void modify(int x,int y){
	while(x<=m){
		ad(t[x],y);
		x+=x&-x;
	}
}
int query(int x){
	int y=0;
	while(x){
		ad(y,t[x]);
		x-=x&-x;
	}
	return y;
}
int lb(int x){
	return lower_bound(p+1,p+m+1,x)-p;
}
int main()
{
	int i,px,py,s;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",x+i,y+i,z+i);
		p[++m]=x[i];
		p[++m]=y[i];
	}
	s=x[n]+1;
	s%=MO;
	sort(p+1,p+m+1);
	for(i=1;i<=n;i++){
		px=lb(x[i]);
		py=lb(y[i]);
		f[i]=x[i]-y[i];
		f[i]%=MO;
		ad(f[i],query(px));
		ad(f[i],MO-query(py));
		if(z[i])
			ad(s,f[i]);
		modify(px,f[i]);
	}
	printf("%d\n",s);
	return 0;
}