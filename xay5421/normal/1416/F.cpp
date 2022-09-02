// author: xay5421
// created: Tue Jan  5 11:22:29 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100010,M=5000005,INF=0X3F3F3F3F,dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
const char dc[4]={'L','U','R','D'};
int T,n,m,maxn,dep[N],s[N],d[N],v[N];
char mp[N];
bool vis[N];
int pp,lnk[N],cur[N],nxt[M],we[M],to[M];
void ae(int k1,int k2,int k3){
	//D("%d %d %d\n",k1,k2,k3);
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
	to[++pp]=k1,we[pp]=0, nxt[pp]=lnk[k2],lnk[k2]=pp;
}
int zip(int x,int y){return (x-1)*m+y;}
void dinic(int s,int t){
	auto bfs=[&](){
		queue<int>q;
		rep(i,1,maxn)dep[i]=-1;
		dep[s]=0;
		q.push(s);
		while(!q.empty()){
			int k1=q.front(); q.pop();
			for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&dep[to[i]]==-1){
				dep[to[i]]=dep[k1]+1;
				q.push(to[i]);
				if(to[i]==t)return 1;
			}
		}
		return 0;
	};
	function<int(int,int)>dfs=[&](int k1,int k2){
		if(k1==t)return k2;
		int k3=k2;
		for(int&i=cur[k1];i;i=nxt[i])if(we[i]&&dep[k1]+1==dep[to[i]]){
			int f=dfs(to[i],min(we[i],k3));
			assert(f>=0);
			we[i]-=f,we[i^1]+=f,k3-=f;
			if(!k3)return k2;
		}
		return k2-k3;
	};
	int res=0;
	while(bfs()){
		rep(i,1,maxn)cur[i]=lnk[i];
		res+=dfs(s,INF);
	}
	D("flow=%d\n",res);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		pp=1;
		rep(i,1,n*m+4)lnk[i]=0,d[i]=0;
		rep(i,1,n*m)vis[i]=0,mp[i]=0,v[i]=0;
		rep(i,1,n)rep(j,1,m)scanf("%d",&s[zip(i,j)]);
		bool err=0;
		auto out=[&](int k1){
			if(k1==n*m+1)D("S ");
			else if(k1==n*m+2)D("T ");
			else{
				int x=(k1-1)/m+1,y=(k1-1)%m+1;
				D("(%d,%d) ",x,y);
			}
		};
		auto jb=[&](int k1,int k2,int lb,int rb){
			/*D("jb ");
			out(k1);
			out(k2);
			D("%d %d\n",lb,rb);*/
			d[k2]+=lb,d[k1]-=lb;
			ae(k1,k2,rb-lb);
		};
		rep(i,1,n)rep(j,1,m){
			int mn=INF;
			rep(k,0,3){
				int ni=i+dx[k],nj=j+dy[k];
				if(ni>=1&&ni<=n&&nj>=1&&nj<=m){
					mn=min(mn,s[zip(ni,nj)]);
					if(((i+j)&1)&&s[zip(i,j)]==s[zip(ni,nj)]){
						jb(zip(i,j),zip(ni,nj),0,1);
					}
				}
			}
			if(mn>s[zip(i,j)]){
				err=1;
				break;
			}
			if(mn==s[zip(i,j)])vis[zip(i,j)]=1;
		}
		if(err){
			puts("NO");
			continue;
		}
		rep(i,1,n)rep(j,1,m){
			if((i+j)&1){
				jb(n*m+1,zip(i,j),vis[zip(i,j)],1);
			}else{
				jb(zip(i,j),n*m+2,vis[zip(i,j)],1);
			}
		}
		jb(n*m+2,n*m+1,0,INF);
		int ss=n*m+3,tt=n*m+4;
		maxn=tt;
		rep(i,1,n*m+2){
			if(d[i]>0)ae(ss,i,d[i]);
			if(d[i]<0)ae(i,tt,-d[i]);
		}
		dinic(ss,tt);
		for(int i=lnk[ss];i;i=nxt[i])if(we[i])err=1;
		for(int i=lnk[tt];i;i=nxt[i])if(we[i^1])err=1;
		if(err){
			puts("NO");
			continue;
		}
		puts("YES");
		auto link=[&](int k1,int k2){
			v[k1]=s[k1]-1,v[k2]=1;
			if(k2==k1-1)mp[k1]='L',mp[k2]='R';
			if(k2==k1+1)mp[k1]='R',mp[k2]='L';
			if(k2==k1+m)mp[k1]='D',mp[k2]='U';
			if(k2==k1-m)mp[k1]='U',mp[k2]='D';
		};
		auto link2=[&](int x,int y){
			rep(i,0,3){
				int nx=x+dx[i],ny=y+dy[i];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[zip(nx,ny)]<s[zip(x,y)]){
					mp[zip(x,y)]=dc[i];
					v[zip(x,y)]=s[zip(x,y)]-s[zip(nx,ny)];
					return;
				}
			}
			assert(0);
		};
		rep(i,1,n)rep(j,1,m)if(!mp[zip(i,j)]&&vis[zip(i,j)]){
			int u=-1;
			if((i+j)&1){
				for(int k=lnk[zip(i,j)];k;k=nxt[k])if(to[k]<=n*m&&!we[k]){
					assert(u==-1),u=to[k];
				}
			}else{
				for(int k=lnk[zip(i,j)];k;k=nxt[k])if(to[k]<=n*m&&!we[k^1]){
					assert(u==-1),u=to[k];
				}
			}
			link(zip(i,j),u);
		}
		rep(i,1,n)rep(j,1,m)if(!mp[zip(i,j)])link2(i,j);
		rep(i,1,n)rep(j,1,m)printf("%d%c",v[zip(i,j)],j==m?'\n':' ');
		rep(i,1,n)rep(j,1,m)printf("%c%c",mp[zip(i,j)],j==m?'\n':' ');
	}
	return 0;
}