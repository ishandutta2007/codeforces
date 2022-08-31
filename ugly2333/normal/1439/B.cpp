//CF1439B
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
int n,m,k,a[N],b[N],fl;
vector<int> v[N],ans;
LL p[N];
bool chk(int x,int y){
	if(x>y)
		swap(x,y);
	LL z=(LL)x<<32|y;
	return (*lower_bound(p,p+m,z))==z;
}
void del(int x){
	if(!b[x]||fl)
		return;
	b[x]=0;
	int i,j,y,f;
	vector<int> t;
	for(i=0;i<v[x].size();i=i+1){
		y=v[x][i];
		if(b[y]){
			t.push_back(y);
			a[y]--;
		}
	}
	if(t.size()==k-1&&k<=500&&k*(k-1)/2<=m){
		f=1;
		for(i=0;f&&i<k-1;i=i+1)
			for(j=i+1;f&&j<k-1;j=j+1)
				if(!chk(t[i],t[j]))
					f=0;
		if(f&&!fl){
			fl=1;
			ans=t;
			ans.push_back(x);
		}
	}
	for(i=0;i<t.size();i=i+1){
		y=t[i];
		if(a[y]<k)
			del(y);
	}
}
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i=i+1){
			a[i]=0,b[i]=1;
			v[i].clear();
		}
		fl=0,ans.clear();
		for(i=0;i<m;i=i+1){
			scanf("%d%d",&x,&y);
			if(x>y)
				swap(x,y);
			p[i]=(LL)x<<32|y;
			a[x]++,a[y]++;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		sort(p,p+m),p[m]=(LL)N<<32;
		for(i=1;i<=n;i=i+1)
			if(a[i]<k)
				del(i);
		if(fl){
			printf("2\n");
			for(i=0;i<ans.size();i=i+1)
				printf("%d ",ans[i]);
			printf("\n");
			continue;
		}
		x=0;
		for(i=1;i<=n;i=i+1)
			if(b[i])
				x++,ans.push_back(i);
		if(x){
			printf("1 %d\n",ans.size());
			for(i=0;i<ans.size();i=i+1)
				printf("%d ",ans[i]);
			printf("\n");
			continue;
		}
		printf("-1\n");
	}
	return 0;
}