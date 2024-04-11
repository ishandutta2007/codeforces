//CF1515C
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
int n,m;
priority_queue<pair<int,int> > Q;
int main()
{
	int T,i,x;
	pair<int,int> p;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&x);
		for(i=1;i<=m;i=i+1)
			Q.push(make_pair(0,i));
		printf("YES\n");
		for(i=1;i<=n;i=i+1){
			scanf("%d",&x);
			p=Q.top();
			Q.pop();
			printf("%d ",p.second);
			p.first-=x;
			Q.push(p);
		}
		printf("\n");
		while(!Q.empty()){
			Q.pop();
		}
	}
	return 0;
}