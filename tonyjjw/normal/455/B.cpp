#include<stdio.h>
#include<string.h>
#define MN 100000
//#pragma warning(disable:4996)

int N,C=1,D[MN+1],D2[MN+1],K;
char str[MN+1];

struct NODE{
	int next[26];
}node[MN+1];

void dfs(int n){
	int i;
	for(i=0;i<26;i++){
		if(node[n].next[i]==-1)continue;
		dfs(node[n].next[i]);
		if(D[node[n].next[i]]==0)D[n]=1;
	}
}

void dfs2(int n){
	int i,f=0,g=0;
	for(i=0;i<26;i++){
		if(node[n].next[i]==-1)continue;
		g=1;
		dfs2(node[n].next[i]);
		if(D2[node[n].next[i]]==0)f=1;
	}
	if(g)D2[n]=f;
}

int main(){
	int i,j,l,p;
	scanf("%d%d",&N,&K);
	for(j=0;j<=MN;j++)for(i=0;i<26;i++)node[j].next[i]=-1;
	for(i=0;i<=MN;i++)D2[i]=1;
	for(i=0;i<N;i++){
		scanf("%s",str);
		l=strlen(str);
		p=0;
		for(j=0;j<l;j++){
			if(node[p].next[str[j]-'a']==-1){
				node[p].next[str[j]-'a']=C++;
			}
			p=node[p].next[str[j]-'a'];
		}
	}
	dfs(0);
	dfs2(0);
	if(D[0]&&D2[0]){
		puts("First");
	}
	if(D[0]&&!D2[0]){
		if(K&1)puts("First");
		else
		{
			puts("Second");
		}
	}
	if(!D[0]&&D2[0]){
		puts("Second");
	}
	if(!D[0]&&!D2[0]){
		puts("Second");
	}
	return 0;
}