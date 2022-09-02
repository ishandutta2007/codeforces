#include<cstdio>
#include<vector>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=3005,P=1000000007;
int n,a[N],f[N][N];
int min(int a,int b){return a<b?a:b;}
struct SAM{
	int cnt,lst,len[N*2],fa[N*2],ch[N*2][2],pos[N*2],ans[N*2];std::vector<int>g[N*2];
	SAM(){cnt=lst=1;}
	void ex(int c,int i){
		int p=lst,np=lst=++cnt;len[np]=len[p]+1;pos[np]=i;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p)fa[np]=1;
		else{
			int q=ch[p][c];
			if(len[p]+1==len[q])fa[np]=q;
			else{
				int nq=++cnt;len[nq]=len[p]+1;pos[nq]=i;
				fa[nq]=fa[q],ch[nq][0]=ch[q][0],ch[nq][1]=ch[q][1];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
			}
		}
	}
	void ae(){
		for(int i=2;i<=cnt;++i)g[fa[i]].push_back(i);
	}
	void dfs(int u){
		for(int i=0;i<(int)g[u].size();++i)dfs(g[u][i]),pos[u]=min(pos[u],pos[g[u][i]]);
		for(int i=len[fa[u]]+1;i<=len[u];++i)(ans[pos[u]]+=f[pos[u]-i+1][pos[u]])%=P;
	}
	void pt(){
		for(int i=1;i<=n;++i)(ans[i]+=ans[i-1])%=P,printf("%d\n",ans[i]); 
	}
}sam;
bool chk(int x){
	int v=a[x]+(a[x-1]<<1)+(a[x-2]<<2)+(a[x-3]<<3);
	if(v==3||v==5||v==14||v==15)return 0;
	else return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i),sam.ex(a[i],i);sam.ae();
	rep(i,1,n){
		f[i][i-1]=1;
		rep(j,i,n){
			f[i][j]=f[i][j-1];
			if(j-1>=i)(f[i][j]+=f[i][j-2])%=P;
			if(j-2>=i)(f[i][j]+=f[i][j-3])%=P;
			if(j-3>=i&&chk(j))(f[i][j]+=f[i][j-4])%=P;
		}
	}
	sam.dfs(1);
	sam.pt();
	return 0;
}