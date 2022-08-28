//CF1621B
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
const int inf = 2e9+N;
int n;
int main()
{
	int T,i,l,r,x,y,z,a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%d%d%d",&l,&r,&z);
		x=z,y=z;
		printf("%d\n",z);
		for(i=2;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a<l){
				l=a;
				x=c;
				z=inf;
			}
			else{
				if(a==l){
					x=min(x,c);
				}
			}
			if(r<b){
				r=b;
				y=c;
				z=inf;
			}
			else{
				if(r==b){
					y=min(y,c);
				}
			}
			if(a==l&&b==r)
				z=min(z,c);
			printf("%d\n",min(z,x+y));
		}
	}
	return 0;
}