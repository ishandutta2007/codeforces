#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int A[110000],n,a[110000],len,pd[110000];
vector<int>x[110000];
void dfs(int k){
	pd[k]=1; x[len].push_back(k); if (pd[A[k]]==0)dfs(A[k]);
}
int compare(int k1,int k2){
	return x[k1].size()<x[k2].size();
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++) if (pd[i]==0){
		len++; a[len]=len; dfs(i);
	}
	sort(a+1,a+len+1,compare);
	if (x[a[1]].size()==1){
		printf("YES\n");
		for (int i=2;i<=len;i++)
			for (int j=0;j<x[a[i]].size();j++) printf("%d %d\n",x[a[1]][0],x[a[i]][j]);
	} else if (x[a[1]].size()==2){
		for (int i=2;i<=len;i++) if (x[a[i]].size()%2==1){
			printf("NO\n"); return 0;
		}
		printf("YES\n");
		printf("%d %d\n",x[a[1]][0],x[a[1]][1]);
		for (int i=2;i<=len;i++)
			for (int j=0;j<x[a[i]].size();j++) printf("%d %d\n",x[a[1]][j%2],x[a[i]][j]);
	} else printf("NO\n");
	return 0;
}