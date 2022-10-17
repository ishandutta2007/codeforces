#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,res,x,y,f[200500];
vector<int> v[200500];

void dfs(int x,int fa){
	if(x!=1&&v[x].size()==1){
		//printf("b%d\n",x);
		res++;f[x]=1;return;
	}
	int sb=0;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		if(f[i])sb=1;
	}
	if(sb){
		res--;
	}
	else{
		//printf("b%d\n",x);
		f[x]=1;res++;
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		for(i=1;i<=n;i++){
			v[i].clear();
			f[i]=0;
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		if(!f[1]){
			res++;
		}
		printf("%d\n",res);
	}
}