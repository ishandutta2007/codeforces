#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=3005;
int n,f[N][N],fafa[N],sz[N],inq[N][N];vector<int>G[N];
struct data{
	int a,fa,b,fb;
};
queue<data>q;
void dfs(int k1){
	sz[k1]=1;
	for(auto j:G[k1])if(j!=fafa[k1])fafa[j]=k1,dfs(j),sz[k1]+=sz[j];
}
int getsz(int k1,int k2){
	if(fafa[k1]==k2)return sz[k1];
	else return n-sz[k2];
}
signed main(){
	rd(n);
	auto push=[&](int x,int fx,int y,int fy){
//		fprintf(stderr,"push:%d %d %d %d\n",x,fx,y,fy); 
		if(!inq[x][y])q.push((data){x,fx,y,fy}),inq[x][y]=inq[y][x]=1;
	};
	for(int i=1;i<n;++i){
		int k1,k2;rd(k1),rd(k2);
		G[k1].push_back(k2),G[k2].push_back(k1);
		push(k1,k2,k2,k1);
	}
	dfs(1);
	for(int k1=1;k1<=n;++k1)for(auto k2:G[k1])if(k1<k2)
		f[k1][k2]=f[k2][k1]=getsz(k1,k2)*getsz(k2,k1);
	int ans=0;
	while(!q.empty()){
		int a=q.front().a,fa=q.front().fa;
		int b=q.front().b,fb=q.front().fb;
		q.pop();
//		fprintf(stderr,"%d %d %d %d = %d\n",a,fa,b,fb,f[a][b]);
		for(auto x:G[a])if(x!=fa){
			f[b][x]=f[x][b]=max(f[x][b],f[a][b]+getsz(b,fb)*getsz(x,a));
			push(x,a,b,fb);
		}
		for(auto x:G[b])if(x!=fb){
			f[x][a]=f[a][x]=max(f[x][a],f[a][b]+getsz(a,fa)*getsz(x,b));
			push(x,b,a,fa);
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)ans=max(ans,f[i][j]);
	pt(ans,'\n');
	return 0;
}