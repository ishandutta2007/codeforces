#include<bits/stdc++.h>
using namespace std;
int k,n;
int l[200005],r[200005],fa[210000];
char c[200005];
int tot=0;
int dfn[210000];
bool o[210000];
int a[210000];
int nxt[210000];
void dfs1(int i){
	if(i==0)return;
	nxt[l[i]]=nxt[i]+1;
	dfs1(l[i]);
	dfn[++tot]=i;
	nxt[r[i]]=1;
	dfs1(r[i]);
}
void dfs2(int i){
	if(i==0)return;
	if(a[i]==1)return;
	dfs2(l[i]);
	dfs2(r[i]);
	a[i]=1;
}
int main(){
	cin>>n>>k;
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=n;i++)fa[l[i]]=i,fa[r[i]]=i;
	fa[1]=0,nxt[1]=1;
	dfs1(1);
	char now='a'-1;
	for(int i=n;i>=1;i--){
		if(c[dfn[i]]>now)o[i]=1;
		else o[i]=0;
		if(i>1)if(c[dfn[i]]!=c[dfn[i-1]])now=c[dfn[i]];
	}
	for(int i=1;i<=n;i++){
		if(a[dfn[i]])continue;
	    if(o[i])dfs2(dfn[i]);
	    else{
	    	int num=nxt[dfn[i]];
			if(num>k){
				dfs2(dfn[i]);
				continue;
			}
			for(int j=dfn[i];j && a[j]==0;j=fa[j])a[j]=2;
			k-=num;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%c",c[dfn[i]]);
		if(a[dfn[i]]==2)printf("%c",c[dfn[i]]);
	}
	return 0;
}