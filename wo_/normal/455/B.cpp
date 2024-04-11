#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct trie{
	struct node{
		int nxt[26];
		bool leaf;
		node(){
			for(int i=0;i<26;i++) nxt[i]==-1;
			leaf=false;
		}
	};
	node nodes[200200];
	int c;
	void init(){
		c=1;
		for(int i=0;i<200200;i++) for(int j=0;j<26;j++){
			nodes[i].nxt[j]=-1;
		}
	}
	void add(string str){
		int N=str.size();
		int id=0;
		for(int i=0;i<N;i++){
			int x=str[i]-'a';
			if(nodes[id].nxt[x]==-1){
				nodes[id].nxt[x]=c++;
			}
			id=nodes[id].nxt[x];
		}
	}
	void decide(){
		for(int i=0;i<c;i++){
			nodes[i].leaf=true;
			for(int j=0;j<26;j++) if(nodes[i].nxt[j]!=-1){
				nodes[i].leaf=false;
			}
		}
	}
	bool dp[2][200200];
	void dfs(int v){
		if(nodes[v].leaf==true){
			dp[0][v]=false;
			dp[1][v]=true;
			return;
		}
		for(int i=0;i<26;i++) if(nodes[v].nxt[i]!=-1){
			dfs(nodes[v].nxt[i]);
		}
		dp[0][v]=false;
		dp[1][v]=false;
		for(int i=0;i<26;i++){
			if(nodes[v].nxt[i]!=-1){
				int u=nodes[v].nxt[i];
				if(dp[0][u]==false) dp[0][v]=true;
				if(dp[1][u]==false) dp[1][v]=true;
			}
		}
	}
};

trie tr;

int main(){
	int N,K;
	cin>>N>>K;
	tr.init();
	for(int i=0;i<N;i++){
		string str;
		cin>>str;
		tr.add(str);
	}
	tr.decide();
	tr.dfs(0);
	int dest[2];
	dest[0]=tr.dp[0][0]?1:0;
	dest[1]=tr.dp[1][0]?1:0;
	int ans;
	if(dest[0]==0) ans=0;
	else{
		if(dest[1]==1) ans=1;
		else ans=K%2;
	}
	if(ans==0) cout<<"Second\n";
	else cout<<"First\n";
	return 0;
}