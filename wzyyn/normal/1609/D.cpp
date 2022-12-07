#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int n,d,ans,rem;
int sz[N],fa[N],q[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++)
		sz[i]=1,fa[i]=i;
	for (int i=1;i<=d;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=get(x); y=get(y);
		if (x!=y){
			fa[x]=y;
			sz[y]+=sz[x];
		}
		else
			++rem;
		*q=0;
		for (int j=1;j<=n;j++)
			if (fa[j]==j) q[++*q]=sz[j];
		sort(q+1,q+*q+1,greater<int>());
		int ans=0;
		for (int i=1;i<=rem+1&&i<=*q;i++)
			ans+=q[i];
		cout<<ans-1<<endl;
	}
}