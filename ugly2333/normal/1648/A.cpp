//CF1648A
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
int n,m,w;
pair<int,int> p1[N],p2[N];
LL ans;
void go(pair<int,int>*p){
	LL s0=0,s1=0;
	int i;
	for(i=1;i<=w;i++){
		if(p[i].first==p[i-1].first){
			ans+=s0*p[i].second-s1;
			s0++;
			s1+=p[i].second;
		}
		else{
			s0=1;
			s1=p[i].second;
		}
	}
}
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&x);
			p1[++w]=make_pair(x,i);
			p2[w]=make_pair(x,j);
		}
	}
	sort(p1+1,p1+w+1);
	sort(p2+1,p2+w+1);
	go(p1);
	go(p2);
	printf("%lld\n",ans);
	return 0;
}