#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=200050;
const int M=2*N;
void ckmn(int &x,int y){x=min(x,y);}
char s[2][N];
struct Node{
	int l,r;
	int dp[2][2];
	Node(){}
	Node(int x){
		l=r=x;
		dp[0][1]=dp[1][0]=(s[0][x]=='.'&&s[1][x]=='.')?1:inf;
		dp[0][0]=s[0][x]=='.'?0:inf;
		dp[1][1]=s[1][x]=='.'?0:inf;
	}
}node[M];
Node operator + (Node L,Node R){
	Node ans;
	ans.l=L.l;ans.r=R.r;
	for(int st=0;st<2;st++){
		for(int ed=0;ed<2;ed++){
			ans.dp[st][ed]=inf;
			for(int i=0;i<2;i++)if(s[i][L.r]=='.'&&s[i][R.l]=='.'){
				ckmn(ans.dp[st][ed],L.dp[st][i]+R.dp[i][ed]+1);
			}
		}
	}
	return ans;
}
int ls[M],rs[M],tsz,root;
void Build(int &c,int ss,int se){
	c=++tsz;if(ss==se){node[c]=Node(ss);return;}
	int mid=ss+se>>1;Build(ls[c],ss,mid);Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss&&qe>=se)return node[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	scanf("%s %s",s[0]+1,s[1]+1);
	Build(root,1,n);
	while(m--){
		int u,v;scanf("%i %i",&u,&v);
		if((u-1)%n>(v-1)%n)swap(u,v);
		int l=(u-1)%n+1;
		int r=(v-1)%n+1;
		Node ans=Get(root,1,n,l,r);
		int res=ans.dp[u>n][v>n];
		printf("%i\n",res<inf?res:-1);
	}
	return 0;
}