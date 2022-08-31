//CF1687C
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
int n,m,a[N],b[N],l[N],r[N],f[N];
LL c[N];
set<int> S;
vector<int> v[N];
queue<int> q;
void ins(int i){
	int x;
	set<int>::iterator it;
	while(1){
		it=S.lower_bound(l[i]);
		if(it!=S.end()&&(*it)<=r[i]){
			q.push(*it);
			S.erase(it);
		}
		else
			return;
	}
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		for(i=1;i<=n;i++)
			c[i]=c[i-1]+b[i]-a[i];
		for(i=1;i<=m;i++){
			scanf("%d%d",l+i,r+i);
			l[i]--;
		}
		if(c[n]){
			printf("NO\n");
			continue;
		}
		S.clear();
		for(i=0;i<=n;i++){
			f[i]=0;
			if(!c[i])
				q.push(i);
			else
				S.insert(i);
		}
		for(i=1;i<=m;i++){
			v[l[i]].push_back(i);
			v[r[i]].push_back(i);
		}
		while(!q.empty()){
			i=q.front();
			q.pop();
			f[i]=1;
			for(j=0;j<v[i].size();j++)
				if(f[l[v[i][j]]]&&f[r[v[i][j]]])
					ins(v[i][j]);
		}
		if(S.empty())
			printf("YES\n");
		else
			printf("NO\n");
		for(i=0;i<=n;i++)
			v[i].clear();
	}
	return 0;
}