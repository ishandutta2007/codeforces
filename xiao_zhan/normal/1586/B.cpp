#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[2005000],fa[2005000];
vector<int> v[2005000];
map<int,map<int,int > >nmsl;

int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			a[i]=0;
		}
		for(i=1;i<=m;i++){
			scanf("%*d%d%*d",&j);
			a[j]=1;
		}
		for(i=1;i<=n;i++){
			if(!a[i]){
				for(j=1;j<=n;j++){
					if(i!=j)printf("%d %d\n",i,j);
				}
				goto aaa;
			}
		}
		aaa:;
	}
}