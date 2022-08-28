//CF1190D
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
int n;
pair<int,int> p[N];
map<int,int> M;
map<int,int>::iterator it;
LL ans;
LL c2(int x){
	return (LL)x*(x+1)/2;
}
int a[N],t[N];
void ad(int x){
	if(a[x])
		return;
	a[x]=1;
	while(x<=n){
		t[x]++;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		p[i]=make_pair(-y,x);
		M[x]=1;
	}
	x=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++x;
	sort(p,p+n);
	for(i=0;i<n;i=i+1)
		p[i].second=M[p[i].second];
	for(i=0;i<n;){
		y=p[i].first;
		x=0;
		while(i<n&&y==p[i].first){
			ans-=c2(qu(p[i].second-1)-qu(x));
			x=p[i].second;
			ad(x);
			i++;
		}
		ans-=c2(qu(n)-qu(x));
		ans+=c2(qu(n));
	}
	cout<<ans;
	return 0;
}