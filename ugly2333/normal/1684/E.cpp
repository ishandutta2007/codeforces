//CF1684E
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
int n,k;
map<int,int> mp;
map<int,int>::iterator it;
vector<int> v;
int main()
{
	int T,i,x,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		k=min(k,n);
		mp.clear();
		for(i=1;i<=n;i++)
			scanf("%d",&x),mp[x]++;
		o=0;
		for(i=0;i<=n+k;i++){
			if(mp.find(i)==mp.end()){
				o++;
				if(o>k)
					break;
			}
		}
		v.clear();
		for(it=mp.begin();it!=mp.end();it++)
			if((*it).first>i)
				v.push_back((*it).second);
		sort(v.begin(),v.end());
		o=v.size();
		for(i=0;i<v.size();i++)
			if(k>=v[i])
				k-=v[i],o--;
		printf("%d\n",o);
	}
	return 0;
}