//CF1684F
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
int n,m,w,a[N],b[N],c[N];
map<int,int> mp;
map<int,int>::iterator it;
vector<int> v[N];
int main()
{
	int T,i,j,k,x,y,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		mp.clear();
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			mp[a[i]]=1;
		}
		w=0;
		for(it=mp.begin();it!=mp.end();it++)
			(*it).second=++w;
		for(i=1;i<=w;i++)
			v[i].clear();
		for(i=1;i<=n;i++)
			a[i]=mp[a[i]],v[a[i]].push_back(i);
		for(i=1;i<=n;i++)
			b[i]=i;
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			b[x]=max(b[x],y);
		}
		for(i=2;i<=n;i++)
			b[i]=max(b[i],b[i-1]);
		for(i=1;i<=n;i++)
			c[i]=i;
		f=0;
		for(i=1;i<=w;i++){
			for(j=0,k=0;j<v[i].size();j++){
				x=v[i][j];
				if(j+1<v[i].size()&&v[i][j+1]<=b[x]){
					y=v[i][j+1];
					c[1]=max(c[1],x);
					c[y+1]=max(c[y+1],n+1);
					f=1;
				}
				while(k+1<v[i].size()&&v[i][k+1]<=b[x]){
					k++;
				}
				if(j<k){
					y=v[i][k];
					c[x+1]=max(c[x+1],y);
					f=1;
				}
			}
		}
		for(i=2;i<=n;i++)
			c[i]=max(c[i],c[i-1]);
		if(!f)
			x=0;
		else
			x=n+1;
		for(i=1;i<=n;i++)
			if(c[i]<=n)
				x=min(x,c[i]-i+1);
		printf("%d\n",x);
	}
	return 0;
}