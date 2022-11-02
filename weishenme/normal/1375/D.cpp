#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int T,n,x,a[N],b[N],vis[N];
vector<int> ans;
int mex(){
	memset(b,0,sizeof b);
	for (int i=0;i<n;i++)b[a[i]]=1;
	int ans=0;
	while (b[ans])ans++;
	return ans;
}
int check(){
	for (int i=0;i<n-1;i++)
		if (a[i]>a[i+1])return 0;
	return 1;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)scanf("%d",&a[i]);
		ans.clear();
		while (!check()){
			int t=mex();
			if (t<n){
				ans.push_back(t);
				a[t]=t;
			}
			else for (int i=0;i<n;i++)
				if (a[i]!=i){
					a[i]=n;
					ans.push_back(i);
					break;
				}
		}
		printf("%d\n",ans.size());
		for (int i:ans)printf("%d ",i+1);
		puts("");
	}
}