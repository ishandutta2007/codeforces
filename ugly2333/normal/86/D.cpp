//CF 86D_2
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
const int N = 200022;
const int Q = 111;
int n,t,a[N],s[N*5];
int l[N],r[N],p[N];
LL ans[N];
pair<int,int> h[N];
vector<pair<int,LL> > v[N],q[N];
LL T[N];
void ad(int x,LL v){
	while(x<=n){
		T[x]+=v;
		x+=x&-x;
	}
}
LL qu(int x){
	LL res;
	res=0;
	while(x){
		res+=T[x];
		x-=x&-x;
	}
	return res;
}
int main()
{
	int i,j,k,x,y,hh;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		s[a[i]]++;
		h[i]=make_pair(a[i],i);
	}
	sort(h+1,h+n+1);
	for(i=1;i<=t;i=i+1){
		scanf("%d%d",l+i,r+i);
		q[l[i]].push_back(make_pair(r[i],i));
	}
	hh=1;
	for(i=1;i<=1e6;i=i+1){
		if(s[i]>=Q){
			for(j=1;j<=n;j=j+1){
				p[j]=p[j-1];
				if(a[j]==i)
					p[j]++;
			}
			for(j=1;j<=t;j=j+1){
				x=p[r[j]]-p[l[j]-1];
				ans[j]+=(LL)x*x*i;
			}
		}
		else{
			for(j=0;j<s[i];j=j+1){
				x=h[hh+j].second;
				v[x].push_back(make_pair(x,(LL)i));
				for(k=j+1;k<s[i];k=k+1)
					v[x].push_back(make_pair(h[hh+k].second,(LL)i+i));
			}
		}
		hh+=s[i];
	}
	for(i=n;i>=1;i=i-1){
		x=v[i].size();
		for(j=0;j<x;j=j+1)
			if(v[i][j].first)
				ad(v[i][j].first,v[i][j].second);
		x=q[i].size();
		for(j=0;j<x;j=j+1)
			ans[q[i][j].second]+=qu(q[i][j].first);
	}
	for(i=1;i<=t;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}