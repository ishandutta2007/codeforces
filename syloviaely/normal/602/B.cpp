#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>A[110000];
const int N=100000;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); A[k1].push_back(i); A[k1+1].push_back(i);
	}
	for (int i=1;i<=N;i++) sort(A[i].begin(),A[i].end());
	int ans=0;
	for (int now=1;now<=N;now++){
		int pre=0;
		for (int i=1;i<A[now].size();i++)
			if (A[now][i]!=A[now][i-1]+1){
				ans=max(ans,i-pre); pre=i;
			}
		ans=max(ans,(int)(A[now].size())-pre);
	}
	printf("%d\n",ans);
	return 0;
}