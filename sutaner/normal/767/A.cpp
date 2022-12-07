#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
bool vis[maxn];
int line[maxn];
int cnt,n;
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d",&n);
	cnt=n;
	for(int i=0;i<n;i++){
		scanf("%d",&line[i]);
		vis[line[i]]=true;
		while(vis[cnt]==true){
			printf("%d ",cnt);
			cnt--;
		}
		printf("\n");
	}
	return 0;
}