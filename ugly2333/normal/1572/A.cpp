//CF1572A
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
int n,s[N],f[N];
vector<int> v[N];
queue<int> q;
int main()
{
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			for(j=1;j<=x;j++){
				scanf("%d",&y);
				v[y].push_back(i);
				s[i]++;
			}
		}
		for(i=1;i<=n;i++)
			if(!s[i])
				q.push(i),f[i]=1;
		while(!q.empty()){
			x=q.front();
			q.pop();
			for(i=0;i<v[x].size();i++){
				y=v[x][i];
				s[y]--;
				f[y]=max(f[y],f[x]+(x>y));
				if(!s[y])
					q.push(y);
			}
		}
		x=0;
		for(i=1;i<=n;i++)
			if(s[i])
				x=1;
		if(x){
			printf("-1\n");
		}
		else{
			x=0;
			for(i=1;i<=n;i++)
				x=max(x,f[i]);
			printf("%d\n",x);
		}
		for(i=1;i<=n;i++){
			v[i].clear();
			f[i]=0;
			s[i]=0;
		}
	}
	return 0;
}