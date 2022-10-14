#include <bits/stdc++.h>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int p[110000],len,pd[210000],n,m,pre[210000],in[210000],flag;
queue<int>Q;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add( int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k){
	in[k]=1; pd[k]=1;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) dfs(j);
		else if (in[j]) flag=1;
	}
	in[k]=0;
}
vector<int>way;
void printpath(int K){
	for (int i=K;i;i=pre[i]) way.push_back(i/2);
	for (int i=0;i<way.size();i++) printf("%d ",way[way.size()-i-1]);
	cout<<endl;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		for (;k1;k1--){
			int k2; scanf("%d",&k2); ade(i,k2);
		}
	}
	int s; scanf("%d",&s);
	Q.push(s*2); pd[s*2]=1;
	while (!Q.empty()){
		int k=Q.front(); Q.pop();// cout<<k<<endl;
		int k1=k/2,sign=k&1;
		for (int i=p[k1];i;i=b[i].next){
			int j=b[i].point;
			int k2=j*2+(sign^1);
			if (pd[k2]==0){
				pd[k2]=1; Q.push(k2); pre[k2]=k;
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (p[i]==0&&pd[i*2+1]){
			printf("Win\n");
			printpath(i*2+1);
			return 0;
		}
	memset(pd,0x00,sizeof pd);
	dfs(s);
	if (flag) printf("Draw\n"); else printf("Lose\n");
	return 0;
}