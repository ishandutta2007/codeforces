#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>ans;
int pd[1100],n;
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		if (pd[i]==0){
			for (int j=i;j<=n;j*=i)
				ans.push_back(j);
			for (int j=i;j<=n;j+=i) pd[j]=1;
		}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}