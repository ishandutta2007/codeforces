#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int now[110],x[110],n,pd[110];
char ch[110][110];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	vector<int>ans;
	while (1){
		int flag=0;
		for (int i=1;i<=n;i++) if (now[i]==x[i]){
			ans.push_back(i); flag=1;
			for (int j=1;j<=n;j++) if (ch[i][j]=='1') now[j]++;
			break;
		}
		if (flag==0) break;
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}