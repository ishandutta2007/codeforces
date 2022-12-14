#include <cstdio>
#include <cstring>
#define max_char 127
#define max_k 3968
#define max_n 200000
using namespace std;
typedef const int& ci;
struct edge_node{
	int v,nxt;
	edge_node(){}
	edge_node(ci _v,ci _nxt):v(_v),nxt(_nxt){}
};
struct graph{
	int head[max_k+1],cnt;
	edge_node edge[max_n];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void push(ci u,ci v){
		edge[++cnt]=edge_node(v,head[u]);
		head[u]=cnt;
	}
};
graph g;
int ideg[max_k+1],odeg[max_k+1];
int ans[max_n+3],s[max_n+3],tot;
int hsh[max_k+1],dic[max_char+1];
#define h(x,y) (dic[x]*63+dic[y])
void dfs(ci x) {
	if(~g.head[x]){
		edge_node&ed=g.edge[g.head[x]];
		g.head[x]=ed.nxt;
		dfs(s[++tot]=ed.v);
	}
}
void Fleury(ci n,ci st) {
	int x,anstot=0;
	for(s[tot=1]=st; tot; ~g.head[x=s[tot]]?dfs(x),1:(ans[++anstot]=x,--tot));
	if (anstot^(n+1)){
		puts("NO");
		return;	
	}
	puts("YES");
	for(int i=anstot+1; --i; putchar(hsh[ans[i]/63]));
	putchar(hsh[ans[1]%63]);
}
int main(){
	for(int i=96; ++i<='z'; hsh[dic[i]=i^96]=i);
	for(int i=64; ++i<='Z'; hsh[dic[i]=(i^64)+26]=i);
	for(int i=47; ++i<='9'; hsh[dic[i]=(i^48)+53]=i);
	int n;
	char s[4];
	scanf("%d",&n),g.build();
	int st=0;
	for(int i=0,fn; ++i<=n; ++odeg[st],++ideg[fn]){
		scanf("%s",s);
		g.push(st=h(s[0],s[1]),fn=h(s[1],s[2]));
	}
	int s1=0,s2=0,s3=0;
	for(int i=0,t; ++i<=max_k; )
		switch(t=ideg[i]-odeg[i]){
			case 1:
				++s1;
				break;
			case 0:
				++s2;
				break;
			case -1:
				++s3,st=i;
				break;
			default:
				puts("NO");
				return 0;
		}
	if(s1!=s3||s3>1){
		puts("NO");
		return 0;
	}
	Fleury(n,st);
	return 0;
}