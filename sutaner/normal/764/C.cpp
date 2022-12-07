#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<vector>
#define maxn 200005
using namespace std;
vector<int> geo[maxn];
int col[maxn];
int cnt[maxn];
bool vis[maxn];
void DFS(int x){
	vis[x]=true;
	for(int i=0;i<geo[x].size();i++){
		if(vis[geo[x][i]])continue;
		if(col[geo[x][i]]!=col[x]){
			cnt[x]++;
			cnt[geo[x][i]]++;
		}
		DFS(geo[x][i]);
	}
	return;
}
bool DFS2(int x,int c){
	vis[x]=false;
	if(col[x]!=c)return false;
	for(int i=0;i<geo[x].size();i++){
		if(!vis[geo[x][i]])continue;
		if(!DFS2(geo[x][i],c))return false;
	}	
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		geo[x].push_back(y);
		geo[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&col[i]);
	DFS(1);
	int maxnum=0,max2=1;
	for(int i=1;i<=n;i++)
		if(maxnum<cnt[i]){
			maxnum=cnt[i];
			max2=i;
		}
	bool flag=true;
	vis[max2]=false;
	for(int i=0;i<geo[max2].size();i++)
		if(!DFS2(geo[max2][i],col[geo[max2][i]])){
			flag=false;
			break;
		}
	if(flag)
		printf("YES\n%d",max2);
	else printf("NO");
	return 0;
}