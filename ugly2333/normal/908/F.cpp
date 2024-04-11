//CF 908F
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
const int N = 333333;
int n,a[N],e[N];
int h1[N],h2[N];
vector<int> v0,v1,v2;
int cnt(vector<int>& v){
	if(!v.size())
		return 0;
	return a[*v.rbegin()]-a[*v.begin()];
}
int lb(vector<int>& v,int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int main()
{
	int i,j,x,y,m,s0,s1,s2,ans=0;
	char ch[5];
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%s",a+i,ch);
		if(ch[0]=='G')
			e[i]=0,v0.push_back(i);
		if(ch[0]=='R')
			e[i]=1,v1.push_back(i);
		if(ch[0]=='B')
			e[i]=2,v2.push_back(i);
	}
	s0=v0.size(),s1=v1.size(),s2=v2.size();
	if(!s0){
		ans=(LL)cnt(v1)+(LL)cnt(v2);
		cout<<ans<<endl;
		return 0;
	}
	ans=cnt(v0);
	x=v0[0];
	y=v0[s0-1];
	if(s1){
		if(v1[0]<x)
			ans+=a[x]-a[v1[0]];
		if(v1[s1-1]>y)
			ans+=a[v1[s1-1]]-a[y];
	}
	if(s2){
		if(v2[0]<x)
			ans+=a[x]-a[v2[0]];
		if(v2[s2-1]>y)
			ans+=a[v2[s2-1]]-a[y];
	}
	for(i=0;i+1<s0;i=i+1){
		x=lb(v1,v0[i]),y=lb(v1,v0[i+1])-1;
		if(x>y)
			continue;
		h1[i]=a[v0[i+1]]-a[v0[i]];
		m=max(a[v1[x]]-a[v0[i]],a[v0[i+1]]-a[v1[y]]);
		for(j=x;j<y;j=j+1)
			m=max(m,a[v1[j+1]]-a[v1[j]]);
		h1[i]-=m;
	}
	for(i=0;i+1<s0;i=i+1){
		x=lb(v2,v0[i]),y=lb(v2,v0[i+1])-1;
		if(x>y)
			continue;
		h2[i]=a[v0[i+1]]-a[v0[i]];
		m=max(a[v2[x]]-a[v0[i]],a[v0[i+1]]-a[v2[y]]);
		for(j=x;j<y;j=j+1)
			m=max(m,a[v2[j+1]]-a[v2[j]]);
		h2[i]-=m;
	}
	for(i=0;i+1<s0;i=i+1){
		m=a[v0[i+1]]-a[v0[i]];
		ans+=min(h1[i]+h2[i],m);
	}
	cout<<ans<<endl;
	return 0;
}