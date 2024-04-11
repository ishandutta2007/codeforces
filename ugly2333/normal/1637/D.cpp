//CF1637D
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
const int N = 11111;
int n,a[N],b[N];
bitset<N> f;
int main()
{
	int T,i,x,s,ss;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		ss=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s+=a[i],ss+=a[i]*a[i];
		for(i=1;i<=n;i++)
			scanf("%d",b+i),s+=b[i],ss+=b[i]*b[i];
		f.reset();
		f[0]=1;
		for(i=1;i<=n;i++)
			f=(f<<b[i])|(f<<a[i]);
		x=0;
		for(i=0;i<N;i++)
			if(f[i]&&abs(s-x*2)>abs(s-i*2))
				x=i;
		printf("%d\n",x*x+(s-x)*(s-x)+(n-2)*ss);
	}
	return 0;
}