// CF 269D
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
const int inf = 1000*1000*1000;
pair<int,pair<int,int> > p[111111];
pair<int,int> a[222222];
set<pair<int,int> > S,m1,m2;
set<pair<int,int> >::iterator it;
vector<int> v[111111];
int f[111111];
int main()
{
	int n,t,i,j,o,x,y,z,h,l,r;
	scanf("%d%d",&n,&t);
	for(i=2;i<=n+1;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		p[i]=make_pair(x,make_pair(y,z));
	}
	p[1]=make_pair(0,make_pair(-inf,inf));
	p[n+2]=make_pair(t,make_pair(-inf,inf));
	n+=2;
	sort(p+1,p+n+1);
	o=0;
	for(i=2;i<=n-1;i=i+1){
		o++;;
		a[o]=make_pair(p[i].second.first,i);
		o++;
		a[o]=make_pair(p[i].second.second,-i);
	}
	sort(a+1,a+o+1);
	S.insert(make_pair(0,1));
	S.insert(make_pair(t,n));
	for(i=1;i<=o;i=i+1){
		x=a[i].first;
		y=a[i].second;
		z=p[max(y,-y)].first;
		if(y<0)
			S.erase(make_pair(z,-y));
		else{
			it=S.lower_bound(make_pair(z,y));
			r=(*it).second;
			it--;
			l=(*it).second;
			S.insert(make_pair(z,y));
			m1.insert(make_pair(l,y));
			m1.insert(make_pair(y,r));
			m2.insert(make_pair(l,r));
		}
	}
	it=m1.begin();
	while(it!=m1.end()){
		if(m2.find(*it)==m2.end()){
			x=(*it).first;
			y=(*it).second;
			v[x].push_back(y);
		}
		it++;
	}
	f[1]=2*inf;
	for(i=1;i<=n;i=i+1){
		for(j=0;j<v[i].size();j=j+1){
			x=v[i][j];
			f[x]=max(f[x],min(f[i],min(p[x].second.second,p[i].second.second)-max(p[x].second.first,p[i].second.first)));
		}
	}/**/
	cout<<f[n]<<endl;
	return 0;
}