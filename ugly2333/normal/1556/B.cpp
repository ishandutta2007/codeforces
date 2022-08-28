//CF1556B
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
int n,a[N];
vector<int> v[2];
int main()
{
	int T,i;
	LL s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		v[0].clear(),v[1].clear();
		for(i=1;i<=n;i++)
			scanf("%d",a+i),a[i]&=1,v[a[i]].push_back(i);
		i=v[0].size()-v[1].size();
		if(abs(i)>=2){
			printf("-1\n");
			continue;
		}
		if(v[0].size()<v[1].size())
			swap(v[0],v[1]);
		if(v[0].size()>v[1].size()){
			s=0;
			for(i=0;i<v[0].size();i++)
				s+=abs(i*2+1-v[0][i]);
			printf("%lld\n",s);
			continue;
		}
		s=0,t=0;
		for(i=0;i<v[0].size();i++){
			s+=abs(i*2+1-v[0][i]);
			t+=abs(i*2+2-v[0][i]);
		}
		printf("%lld\n",min(s,t));
	}
	return 0;
}