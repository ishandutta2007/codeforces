//CF1558C
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
const int N = 2222;
int n,a[N],b[N];
vector<int> v;
void go(int x){
	v.push_back(x);
	int i;
	reverse(a+1,a+x+1);
	for(i=1;i<=n;i++)
		b[a[i]]=i;
}
int main()
{
	int T,i,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i),b[a[i]]=i;
		o=0;
		for(i=1;i<=n;i++)
			if((a[i]&1)!=(i&1))
				o=1;
		if(o){
			printf("-1\n");
			continue;
		}
		for(i=n;i>=3;i-=2){
			go(b[i]);
			go(b[i-1]-1);
			go(b[i-1]+1);
			go(3);
			go(i);
		}
		printf("%d\n",v.size());
		for(i=0;i<v.size();i++)
			printf("%d ",v[i]);
		printf("\n");
		v.clear();
	}
	return 0;
}