#include<stdio.h>
#include<vector>
#define MN 200

using namespace std;

vector<int> E[MN];
vector<int> V[3];

int N,deg[MN],C[MN],n,ans,cnt=1e9;

int main(){
	int i,j,a,b,p=0,st;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a),--a;
		V[a].push_back(i);
	}
	for(i=0;i<N;i++){
		scanf("%d",&a);
		for(j=0;j<a;j++){
			scanf("%d",&b),--b;
			E[b].push_back(i);
		}
	}
	for(st=0;st<3;st++){
		p=st;
		for(i=0;i<N;i++)C[i]=deg[i]=0;
		for(i=0;i<N;i++)for(j=0;j<E[i].size();j++)deg[E[i][j]]++;
		n=ans=0;
		while(n<N){
			for(i=0;i<V[p].size();i++){
				if(!C[V[p][i]] && deg[V[p][i]]==0)break;
			}
			if(i==V[p].size()){
				ans++;
				p=(p+1)%3;
				continue;
			}
			C[V[p][i]]=1,ans++,n++;
			for(j=0;j<E[V[p][i]].size();j++){
				deg[E[V[p][i]][j]]--;
			}
		}
		if(cnt>ans)cnt=ans;
	}
	printf("%d",cnt);
	return 0;
}