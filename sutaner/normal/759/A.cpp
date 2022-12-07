#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int vis[maxn];
int line[maxn];
int cnt1=0,cnt2=0,x;
void DFS(int x){
	if(vis[x])return;
	vis[x]=cnt1;
	DFS(line[x]);
	return;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&line[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(!x)cnt2++;
	}
	if(!((n-cnt2)&1))ans++;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		cnt1++;DFS(i);
	}
	if(cnt1==1)cnt1=0;
	printf("%d",ans+cnt1);
	return 0;
}