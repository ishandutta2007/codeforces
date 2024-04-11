#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <map>

#define MAXN 100500

std::map<int,int> nom;
int n,x=1,deg[MAXN],revnom[MAXN],k=0,px=-1;
std::vector<int> g[MAXN];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (!nom[x]){k++;revnom[k]=x;nom[x]=k;}
		if (!nom[y]){k++;revnom[k]=y;nom[y]=k;}
		x=nom[x];y=nom[y];deg[x]++;deg[y]++;
		g[x].push_back(y);g[y].push_back(x);
	}
	while (deg[x]!=1)x++;
	printf("%d",revnom[x]);
	px=x;
	x=g[x][0];
	while (deg[x]!=1){
		printf(" %d",revnom[x]);
		if (g[x][0]==px){px=x;x=g[x][1];}
		else{px=x;x=g[x][0];}
	}
	printf(" %d\n",revnom[x]);
}