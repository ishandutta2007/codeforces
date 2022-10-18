#include<bits/stdc++.h>
#define N 10
#define M 52
#define L 200

int T;

int n,len[N],a[N][L];
char str[L];

int pos[N][M][2],lst[M],nxt[N][L][M];

inline int tr(int x,int s,int c){
	int t=0;
	for(int i=0;i<n;i++){
		int p=~x?pos[i][x][(s>>i)&1]:0;
		if(p>len[i])
			return -1;
		int q=nxt[i][p][c];
		if(q<=len[i])
			t|=(nxt[i][q][c]<=len[i])<<i;
		else
			return -1;
	}
	return t;
}

int deg[M][1<<N];
int f[M][1<<N],pre[M][1<<N],ch[M][1<<N];
bool vis[M][1<<N];
std::queue<std::pair<int,int>> q;
inline void dij(){
	int res=0,X=0,S=-1;
	memset(f,~0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	memset(ch,0,sizeof(ch));
	for(int i=0;i<M;i++){
		int t=tr(-1,0,i);
		if(~t){
			f[i][t]=1;
			pre[i][t]=-1;
		}
	}
	for(int i=0;i<M;i++)
		for(int j=0;j<(1<<n);j++)
			if(!deg[i][j])
				q.emplace(i,j);
	while(q.size()){
		auto [x,s]=q.front();
		q.pop();
		if(f[x][s]>res)
			res=f[x][s],X=x,S=s;
		for(int i=0;i<M;i++){
			int t=tr(x,s,i);
			if(~t){
				if(f[i][t]<f[x][s]+1){
					f[i][t]=f[x][s]+1;
					pre[i][t]=s,ch[i][t]=x;
				}
				if(!--deg[i][t])
					q.emplace(i,t);
			}
		}
	}
	std::vector<char> ans;
	while(~S){
		int tmp=X;
		ans.push_back(X<26?'A'+X:'a'+X-26);
		X=ch[X][S],S=pre[tmp][S];
	}
	std::reverse(ans.begin(),ans.end());
	printf("%d\n",res);
	for(auto c:ans)
		putchar(c);
	puts("");
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(pos,0x3f,sizeof(pos));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",str+1);
			len[i]=strlen(str+1);
			for(int j=1;j<=len[i];j++)
				a[i][j]=str[j]<='Z'?str[j]-'A':str[j]-'a'+26;
			for(int j=0;j<M;j++)
				lst[j]=len[i]+1;
			for(int j=len[i];~j;j--){
				for(int k=0;k<M;k++)
					nxt[i][j][k]=lst[k];
				if(j)
					pos[i][a[i][j]][nxt[i][j][a[i][j]]<=len[i]]=j;
				lst[a[i][j]]=j;
			}
		}
		memset(deg,0,sizeof(deg));
		for(int i=0;i<M;i++)
			for(int j=0;j<(1<<n);j++)
				for(int k=0;k<M;k++){
					int t=tr(i,j,k);
					if(~t)
						deg[k][t]++;
				}
		dij();
	}
}