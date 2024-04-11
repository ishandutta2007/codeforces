#include<bits/stdc++.h>
using namespace std;
int ch[11000000][2];
int tot=0;
bool vis[11000000];
int c[2100000];
int node(){
	ch[++tot][0]=0;
	ch[tot][1]=0;
	vis[tot]=0;
	return tot;
}
int dfs(int p,int i){
	if(vis[p]) return -1;
	if(!ch[p][0]) return 0;
	if(!ch[p][1]) return (1<<i);
	int u=dfs(ch[p][0],i-1);
	if(u>=0) return u;
	u=dfs(ch[p][1],i-1);
	if(u>=0) return (1<<i)^u;
	return -1;
} 
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int i=1;i<=r-l+1;i++) scanf("%d",&c[i]);
		tot=1;
		ch[1][0]=ch[1][1]=0;
		vis[1]=false;
		for(int i=1;i<=r-l+1;i++){
			int p=1;
			for(int j=16;j>=0;j--){
				int u=((c[i]>>j)&1);
				if((l>>j)&1){
					if(ch[p][u]) vis[ch[p][u]]=1;
					else{
						ch[p][u]=node();
						vis[ch[p][u]]=1;
					}
				}
				int uu=((l>>j)&1);
				if(!ch[p][u^uu]) ch[p][u^uu]=node();
				p=ch[p][u^uu];
			}
		}
		for(int i=1;i<=r-l+1;i++){
			int p=1;
			for(int j=16;j>=0;j--){
				int u=((c[i]>>j)&1);
				if(((r>>j)&1)==0){
					if(ch[p][u^1]) vis[ch[p][u^1]]=1;
					else{
						ch[p][u^1]=node();
						vis[ch[p][u^1]]=1;
					}
				}
				int uu=((r>>j)&1);
				if(!ch[p][u^uu]) ch[p][u^uu]=node();
				p=ch[p][u^uu];
			}
		}
		cout<<dfs(1,16)<<endl;
	}
	return 0;
}