#include<bits/stdc++.h>
using namespace std;
int n;
long long h[210000];
long long maxx[210000];
long long ans[210000];
vector<int> e[210000];
vector<int> ch[210000];
void dfs(int i,int fa){
	for(int j=0;j<e[i].size();j++){
		if(e[i][j]!=fa){
			dfs(e[i][j],i);
			ch[i].push_back(e[i][j]);
		}
	}
	long long sum=0;
	long long maxxx=0;
	for(int j=0;j<ch[i].size();j++){
		sum+=ans[ch[i][j]];
		maxxx=max(maxxx,maxx[ch[i][j]]);
	}
	if(maxxx>=h[i]){
		ans[i]=sum;
		maxx[i]=maxxx;
		return;
	}
	ans[i]=sum+h[i]-maxxx;
	maxx[i]=h[i];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	long long ii=1,maxxx=0;
	for(int i=1;i<=n;i++){
		if(maxxx<=h[i]){
			maxxx=h[i];
			ii=i;
		}
	}
	dfs(ii,0);
	if(ch[ii].size()==1){
		printf("%lld",ans[ii]+h[ii]);
		return 0;
	}
	long long a=0,b=0;
	for(int j=0;j<ch[ii].size();j++){
		int yy=maxx[ch[ii][j]];
		if(yy>a) {
			b=a;
			a=yy;
		}
		else{
			if(yy>b) b=yy;
		}
	}
	printf("%lld",ans[ii]+h[ii]-b);
	return 0;
}