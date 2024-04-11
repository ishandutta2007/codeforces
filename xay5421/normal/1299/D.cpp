#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005,P=1e9+7;
int n,m,f[400],g[400],pre[N],dep[N];
bool pd[N];
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int mul(int k1,int k2){return 1LL*k1*k2%P;}
int add(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int sub(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
struct XXJ{
	int b[5];
	void clear(){memset(b,0,sizeof(b));}
	bool operator<(const XXJ&k)const{
		rep(i,0,4)if(b[i]!=k.b[i])return b[i]<k.b[i];
		return 0;
	}
	bool ins(int x){
		per(i,4,0)if(x>>i&1){
			if(!b[i]){
				per(j,i-1,0)if(x>>j&1)x^=b[j];
				b[i]=x;
				rep(j,i+1,4)if(b[j]>>i&1)b[j]^=x;
				return 1;
			}
			x^=b[i];
		}
		return 0;
	}
	void pt(){
		D("%3d %3d %3d %3d %3d\n",b[4],b[3],b[2],b[1],b[0]);
	}
}q[400];
int ind;
map<XXJ,int>mp;
int go[400][400];
void getXXJ(XXJ cur){
	if(mp.count(cur))return;
	mp[cur]=++ind;
	//cur.pt();
	q[ind]=cur;
	rep(i,1,31){
		XXJ nex=cur;
		if(nex.ins(i))getXXJ(nex);
	}
}
int dis[N];
bool vis[N];
void sol(int k1,int k2,XXJ&cur,bool&can){
	vis[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&to[i]!=1){
		if(!vis[to[i]]){
			dis[to[i]]=dis[k1]^we[i];
			sol(to[i],k1,cur,can);
		}
		else{
			if(k1<to[i]&&(dep[k1]!=1||dep[to[i]]!=1)){
				D("ins %d\n",dis[k1]^dis[to[i]]^we[i]);
				can&=cur.ins(dis[k1]^dis[to[i]]^we[i]);
			}
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		ae(k1,k2,k3),ae(k2,k1,k3);
	}
	{
		XXJ tmp;
		tmp.clear();
		getXXJ(tmp);
		f[mp[tmp]]=1;
		rep(i,1,ind){
			rep(j,1,ind){
				tmp=q[i];
				bool flg=1;
				rep(k,0,4)if(q[j].b[k]){
					if(!tmp.ins(q[j].b[k])){
						flg=0;
						break;
					}
				}
				if(flg){
					go[i][j]=mp[tmp];
				}
			}
		}
	}
	{
		queue<int>q;
		q.push(1);
		dep[1]=1;
		while(SZ(q)){
			int k1=q.front();
			q.pop();
			for(int i=lnk[k1];i;i=nxt[i])if(!dep[to[i]]){
				pre[to[i]]=k1;
				dep[to[i]]=dep[k1]+1;
				q.push(to[i]);
			}
		}
	}
	rep(k1,2,n)if(dep[k1]==2&&!pd[k1]){
		int k2=-1,k3=-1;
		for(int i=lnk[k1];i;i=nxt[i])if(dep[to[i]]==2){
			k2=to[i],k3=we[i];
		}
		memcpy(g,f,sizeof(g));
		XXJ tmp;
		tmp.clear();
		bool can=1;
		pd[k1]=1;
		sol(k1,1,tmp,can);
		if(can==0)continue;
		int id=mp[tmp];
		if(k2==-1){
			rep(i,1,ind)if(g[i]){
				if(go[i][id]){
					f[go[i][id]]=add(f[go[i][id]],g[i]);
				}
			}
		}else{
			pd[k2]=1;
			XXJ tem=tmp;
			bool ok=can;
			int key1=0;
			for(int i=lnk[k1];i;i=nxt[i]){
				if(to[i]==1){
					key1=we[i];
					break;
				}
			}
			int key2=0;
			for(int i=lnk[k2];i;i=nxt[i]){
				if(to[i]==1){
					key2=we[i];
					break;
				}
			}
			int id2=0;
			if(!tem.ins(key1^key2^k3)){
				ok=0;
			}else id2=mp[tem];
			rep(i,1,ind)if(g[i]){
				if(go[i][id])f[go[i][id]]=add(f[go[i][id]],add(g[i],g[i]));
				if(ok&&go[i][id2])f[go[i][id2]]=add(f[go[i][id2]],g[i]);
			}
		}
	}
	int ans=0;
	rep(i,1,ind)ans=add(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}