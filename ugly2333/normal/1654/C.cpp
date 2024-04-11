//CF1654C
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
int n;
map<LL,int> a,b;
pair<LL,int> p;
LL s;
int main()
{
	int T,i;
	LL x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a.clear();
		b.clear();
		s=0;
		for(i=1;i<=n;i++)
			scanf("%lld",&x),a[x]++,s+=x;
		b[s]=1;
		z=0;
		for(i=1;i<=n*3;i++){
			p=*b.rbegin();
			x=p.first;
			if(a[x]){
				a[x]--;
				b[x]--;
				z++;
			}
			else{
				b[x]--;
				b[x/2]++;
				b[(x+1)/2]++;
			}
			if(!b[x])
				b.erase(x);
			if(z==n)
				break;
		}
		if(z==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}