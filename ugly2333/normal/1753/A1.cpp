//CF1753A
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
int n,a[N];
vector<int> v,p;
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		v.clear();
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			if(a[i])
				v.push_back(i);
		}
		if(v.size()%2==1){
			printf("-1\n");
			continue;
		}
		if(v.size()==0){
			printf("1\n1 %d\n",n);
			continue;
		}
		p.clear();
		for(i=0;i<v.size();i+=2){
			x=v[i],y=v[i+1];
			p.push_back(x);
			if((y-x)%2!=(a[x]==a[y]))
				p.push_back(x+1);
		}
		p.push_back(n+1);
		printf("%d\n",p.size()-1);
		for(i=0;i+1<p.size();i++)
			printf("%d %d\n",p[i],p[i+1]-1);
	}
	return 0;
}