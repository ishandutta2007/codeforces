#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int col[maxn];
bool vis[maxn];
long long int n;
void init(){
	vis[1]=0;
	for(long long int i=1;i<=n;i++){
		if(vis[i+1])continue;
		col[i]=1;
		vis[i+1]=1;
		for(long long int j=i+1;j*(i+1)<=n+1;j++){
			col[j*(i+1)-1]=2;
			vis[j*(i+1)]=1;
		}
	}
	return;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%I64d",&n);
	init();
	if(n>=3)printf("2\n");
	else printf("1\n");
	for(int i=1;i<=n;i++)
		printf("%d ",col[i]);
	return 0;
}