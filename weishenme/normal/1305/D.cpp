#include<bits/stdc++.h>
using namespace std;
int n,x,y,d[1005],flag[1005];
vector<int> G[1005];
void find(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int z;
	scanf("%d",&z);
	if (z==x){
		printf("! %d\n",x);
		fflush(stdout);
		exit(0);
	}
	else if (z==y){
		printf("! %d\n",y);
		fflush(stdout);
		exit(0);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		d[x]++;d[y]++;
	}
	while (1){
		int fi=0,se=0;
		for (int i=1;i<=n;i++)
			if (d[i]==1){
				if (!fi)fi=i;
				else se=i;
			}
		if (!se){
			for (int i=1;i<=n;i++)
				if (!flag[i])printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
		flag[se]=flag[fi]=1;
		find(fi,se);
		d[fi]--;d[se]--;
		for (int i:G[fi])d[i]--;
		for (int i:G[se])d[i]--;
	}
}