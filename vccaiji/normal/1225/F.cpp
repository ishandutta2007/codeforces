#include<bits/stdc++.h>
using namespace std;
int n;
int fa[110000];
int nextt[110000];
int dep[110000]={};
bool vis[110000]={};
vector<int> ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d",&fa[i]);
	int ii=0,maxx=0;
	for(int i=1;i<n;i++){
		dep[i]=dep[fa[i]]+1;
		if(maxx<dep[i]){
			maxx=dep[i];
			ii=i;
		}
	}
	nextt[ii]=0;
	for(int i=ii;i;i=fa[i]){
		vis[i]=true;
		nextt[fa[i]]=i;
	}
	vis[0]=true;
	for(int i=1;i<n;i++){
		if(!vis[i]){
			int num=0;
			int j=i;
			for(;vis[j]==false;j=fa[j]){
				num++;
				vis[j]=true;
			}
			for(int jj=1;jj<=num;jj++) ans.push_back(nextt[j]);
			fa[nextt[j]]=i;
			for(int jj=nextt[j];jj!=j;jj=fa[jj]) nextt[fa[jj]]=jj;
		}
	}
    printf("0 ");
    for(int j=nextt[0];j;j=nextt[j]) printf("%d ",j);
	printf("\n%d\n",n-1-maxx);
	for(int j=ans.size()-1;j>=0;j--) printf("%d ",ans[j]);
	return 0;
}