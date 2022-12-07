#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=105;
int n,nxt[N],vis[N],ans[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		printf("? ");
		for (int j=1;j<=n;j++)
			printf("%d ",i==j?2:1);
		puts("");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if (x!=0&&x!=i) nxt[i]=x;
	}
	for (int i=1;i<=n;i++){
		printf("? ");
		for (int j=1;j<=n;j++)
			printf("%d ",i==j?1:2);
		puts("");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if (x!=0&&x!=i) nxt[x]=i; 
	}
	for (int i=1;i<=n;i++)
		vis[nxt[i]]=1;
	int p=1;
	for (;vis[p];++p);
	for (int i=1;i<=n;i++)
		ans[p]=i,p=nxt[p];
	puts("! ");
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}