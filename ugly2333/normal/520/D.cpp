// CF 520D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int mod = 1000*1000*1000+9;
map<pair<int,int>,int> M;
set<pair<int,int> > S;
set<int> L;
int x[111111],y[111111];
bool ok(int xx,int yy)
{
	int i,j,s;
	if(S.find(make_pair(xx,yy))==S.end())
		return false;
	for(i=-1;i<=1;i=i+1){
		if(S.find(make_pair(xx+i,yy+1))==S.end())
			continue;
		s=0;
		for(j=-1;j<=1;j=j+1)
			if(S.find(make_pair(xx+i+j,yy))!=S.end())
				s++;
		if(s<=1)
			return false;
	}
	return true;
}
int main()
{
	int n,i,k,t,o;
	LL ans;
	pair<int,int> p;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1){
		scanf("%d%d",x+i,y+i);
		p.first=x[i];
		p.second=y[i];
		M[p]=i;
		S.insert(p);
	}
	for(i=0;i<n;i=i+1){
		if(ok(x[i],y[i]))
			L.insert(i);
	}
	ans=0;
	k=0;
	while(!S.empty()){
		if(k)
			t=*(L.begin());
		else
			t=*(--L.end());
		if(ok(x[t],y[t])){
			ans=((LL)ans*n+t)%mod;
			S.erase(make_pair(x[t],y[t]));
			L.erase(t);
			for(i=-1;i<=1;i=i+1){
				if(ok(x[t]+i,y[t]-1)){
					o=M[make_pair(x[t]+i,y[t]-1)];
					L.insert(o);
				}
			}
			k^=1;
		}
		else
			L.erase(t);
	}
	cout<<ans<<endl;
	return 0;
}