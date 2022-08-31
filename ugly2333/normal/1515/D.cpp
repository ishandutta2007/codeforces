//CF1515D
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
int n,l,r,a[N],b[N];
int main()
{
	int T,i,x,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&l,&r);
		for(i=1;i<=n;i=i+1){
			scanf("%d",&x);
			if(i<=l)
				a[x]++;
			else
				b[x]++;
		}
		s=0;
		for(i=1;i<=n;i=i+1){
			x=min(a[i],b[i]);
			a[i]-=x,b[i]-=x;
			l-=x,r-=x;
		}
		if(l>r){
			for(i=1;i<=n;i=i+1){
				x=min((l-r)/2,a[i]/2);
				s+=x;
				a[i]-=x*2;
				l-=x*2;
			}
		}
		else{
			for(i=1;i<=n;i=i+1){
				x=min((r-l)/2,b[i]/2);
				s+=x;
				b[i]-=x*2;
				r-=x*2;
			}
		}
		x=min(l,r);
		s+=x;
		l-=x,r-=x;
		s+=l+r;
		printf("%d\n",s);
		for(i=1;i<=n;i=i+1)
			a[i]=0,b[i]=0;
	}
	return 0;
}