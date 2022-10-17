#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,res,a[305][305],it,sb[305][305],x,y,b[100050],c[100050],vis[305][305];
queue<pair<int,int> > v[100500];
map<int,int >mp;
void add(int x,int y){
	int i,j,k;
	for(i=y+1;i<=m;i++){
		res+=1-a[x][i];
	}
	a[x][y]=1;
}

int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		res=0;it=0;
		mp.clear();
		
		for(i=1;i<=m*n;i++){
			scanf("%d",&k);
			b[i]=k;c[i]=k;
		}
		
		sort(c+1,c+n*m+1);
		x=1;y=1;
		for(i=1;i<=n*m;i++){
			sb[x][y]=c[i];
			y++;
			if(y>m){x++;y=1;}
		}
		for(i=1;i<=n;i++){
			for(j=m;j>=1;j--){
				if(sb[i][j]!=sb[i][m])break;
				if(!mp[sb[i][j]]){mp[sb[i][j]]=++it;}
				k=mp[sb[i][j]];
				v[k].push({i,j});
				vis[i][j]=1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=m;j>=1;j--){
				if(vis[i][j])continue;
				if(!mp[sb[i][j]]){mp[sb[i][j]]=++it;}
				k=mp[sb[i][j]];
				v[k].push({i,j});
				vis[i][j]=1;
			}
		}
		for(i=1;i<=n*m;i++){
			k=mp[b[i]];
			auto [x,y]=v[k].front();v[k].pop();
			add(x,y);
		}
		printf("%d\n",res);
	}
}