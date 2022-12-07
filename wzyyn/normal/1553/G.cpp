#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int M=1020;
int pri[M];
void init(){
	for (int i=2;i<M;i++){
		bool flag=0;
		for (int j=2;j*j<=i;j++)
			if (i%j==0) flag=1;
		if (!flag) pri[++*pri]=i;
	}
}

const int N=1000005;
int n,Q,fa[N],a[N],la[N];
vector<int> adj[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}

bool Check(int x,int y){
	int p=lower_bound(adj[x].begin(),adj[x].end(),y)-adj[x].begin();
	if (adj[x].size()<=p) return 0;
	else return adj[x][p]==y;
}
int main(){
	init();
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int x=a[i];
		for (int j=1;pri[j]*pri[j]<=x;++j)
			if (x%pri[j]==0){
				for (;x%pri[j]==0;x/=pri[j]);
				if (la[pri[j]])
					fa[get(i)]=get(la[pri[j]]);
				la[pri[j]]=i;
			}
		if (x!=1){
			if (la[x])
				fa[get(i)]=get(la[x]);
			la[x]=i;
		}
	}
	for (int i=1;i<=n;i++) get(i);
	static int q[10];
	for (int i=1;i<=n;i++){
		int x=a[i]+1; *q=0;
		for (int j=1;pri[j]*pri[j]<=x;++j)
			if (x%pri[j]==0){
				for (;x%pri[j]==0;x/=pri[j]);
				q[++*q]=fa[la[pri[j]]];
			}
		if (x!=1) q[++*q]=fa[la[x]];
		for (int j=1;j<=*q;j++)
			if (q[j]) adj[fa[i]].push_back(q[j]);
		for (int j=1;j<=*q;j++)
			for (int k=j+1;k<=*q;k++)
				if (q[j]&&q[k]) adj[q[j]].push_back(q[k]);
	}
	for (int i=1;i<=n;i++)
		sort(adj[i].begin(),adj[i].end());
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (get(x)==get(y)) puts("0");
		else{
			x=get(x); y=get(y);
			if (Check(y,x)||Check(x,y)) puts("1");
			else puts("2");
		}
	}
}