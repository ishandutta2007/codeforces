#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
pair<int,int> ans[maxn];
int n,m;
pair<int,int> s[maxn];
int ret[maxn],cnt=0;
int main(){
	memset(ret,0,sizeof(ret));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&ans[i].first);
		ans[i].second=0;
	}
	s[cnt]=make_pair(0,0);
	scanf("%d",&m);
	for (int i=1;i<=m;++i){
		int u;
		scanf("%d",&u);
		if (u==1){
			int v,w;
			scanf("%d%d",&v,&w);
			ans[v].first=w;
			ans[v].second=i;
		}
		else{
			int w;
			scanf("%d",&w);
			s[++cnt]=make_pair(w,i);
		}
	}
	int tmp=0;
	for (int i=cnt;i>0;--i){
		tmp=max(tmp,s[i].first);
		for (int j=s[i-1].second;j<s[i].second;++j){
			ret[j]=tmp;
		}
	}
	for (int i=1;i<=n;++i){
		printf("%d ",max(ans[i].first,ret[ans[i].second]));
	}
	return 0;
}