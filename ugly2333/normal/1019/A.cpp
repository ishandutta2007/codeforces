//CF 1019A
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
const int N = 3333;
int n,m,p[N],c[N],r[N];
vector<int> v[N];
multiset<int> S;
int main()
{
	int i,j,k,x;
	LL ans=1e18,s;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		cin>>p[i]>>c[i],r[p[i]]++,v[p[i]].push_back(c[i]);
	for(i=1;i<=m;i=i+1)
		sort(v[i].begin(),v[i].end());
	for(i=1;i<=n;i=i+1){
		S.clear();
		for(j=1;j<=n;j=j+1)
			if(p[j]!=1)
				S.insert(c[j]);
		x=r[1];
		s=0;
		for(j=2;j<=m;j=j+1)
			if(r[j]>=i)
				for(k=0;k<=r[j]-i;k=k+1)
					s+=v[j][k],x++,S.erase(S.lower_bound(v[j][k]));
		while(x<i){
			s+=*S.begin();
			S.erase(S.begin());
			x++;
		}
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}