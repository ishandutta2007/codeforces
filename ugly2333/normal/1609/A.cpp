//
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
int n;
int main()
{
	int T,i,x,s,m,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		m=1;
		o=0;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			while(x%2==0){
				s++;
				x/=2;
			}
			m=max(m,x);
			o+=x;
		}
		o-=m;
		printf("%lld\n",((LL)m<<s)+o);
	}
	return 0;
}