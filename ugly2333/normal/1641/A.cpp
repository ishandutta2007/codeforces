//CF1641A
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
int n,x;
multiset<LL> S;
int main()
{
	int T,i,y,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		S.clear();
		for(i=1;i<=n;i++)
			scanf("%d",&y),S.insert(y);
		s=0;
		while(!S.empty()){
			y=*S.begin();
			if(S.find((LL)y*x)!=S.end())
				S.erase(S.begin()),S.erase(S.lower_bound((LL)y*x));
			else
				s++,S.erase(S.begin());
		}
		printf("%d\n",s);
	}
	return 0;
}