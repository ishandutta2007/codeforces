//CF1616E
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
const LL inf = 1e18;
int n,m=26,a[N],w[N],l[N];
char s[N],t[N];
vector<int> v[33];
void ad(int x,int y){
	while(x<=n){
		w[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=w[x];
		x-=x&-x;
	}
	return y;
}
int main()
{
	int T,i,j,x,o;
	LL ans,anss;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,s+1,t+1);
		for(i=1;i<=n;i++)
			ad(i,1);
		for(i=1;i<=n;i++)
			v[s[i]-'a'].push_back(i);
		for(i=0;i<m;i++)
			l[i]=0;
		ans=0;
		anss=inf;
		for(i=1;i<=n;i++){
			x=N;
			for(j=0;j<t[i]-'a';j++)
				if(l[j]<v[j].size())
					x=min(x,v[j][l[j]]);
			if(x<=n)
				anss=min(anss,ans+qu(x-1));
			j=t[i]-'a';
			if(l[j]==v[j].size())
				break;
			x=v[j][l[j]];
			ans+=qu(x-1);
			ad(x,-1);
			l[j]++;
		}
		if(anss>=inf)
			anss=-1;
		printf("%lld\n",anss);
		for(i=1;i<=n;i++)
			w[i]=0;
		for(i=0;i<m;i++)
			v[i].clear();
	}
	return 0;
}