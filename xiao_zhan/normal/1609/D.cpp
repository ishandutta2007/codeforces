#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,fa[100500],a[100500],res=1,x,y,sb,b[2500],vis[2050],it;

int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		a[i]=1;
		fa[i]=i;
	}
	
	while(m--){
		cin>>i>>j;
		if(find(i)!=find(j)){
			k=a[find(i)]+a[find(j)];
			res=max(res,k);
			fa[find(j)]=find(i);
			a[find(i)]=k;
		}
		else{
			sb++;
		}
		
		it=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(!vis[find(i)]){
				b[++it]=a[find(i)];
				vis[find(i)]=1;
			}
		}
		
		sort(b+1,b+it+1);
		int ans=0;
		
		for(int i=1;i<=min(it,sb+1);i++){
			ans+=b[it+1-i];
		}
		
		cout<<ans-1<<'\n';
	}
}