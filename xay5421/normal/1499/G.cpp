// author: xay5421
// created: Sat Mar 20 08:49:11 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=400005;
int n1,n2,m,Q,hs,deg[N],num,id[N],pw[N];
vector<deque<int> >cycs,paths;
int h[N][2],be[N],en[N];
void ps(int k1,int k2){
	D("ps %d %d\n",k1,k2);
	if(!deg[k1]&&!deg[k2]){
		int cur=id[k1]=id[k2]=SZ(paths);
		be[cur]=k1,en[cur]=k2;
		paths.push_back({num});
		h[cur][0]=pw[num];
	}else{
		if(deg[k1])swap(k1,k2);
		if(!deg[k1]){
			int cur=id[k1]=id[k2];
			usu(hs,h[cur][1]);
			if(k2==en[cur]){
				uad(h[cur][SZ(paths[cur])&1],pw[num]);
				paths[cur].push_back(num);
				en[cur]=k1;
			}else{
				paths[cur].push_front(num);
				swap(h[cur][0],h[cur][1]);
				uad(h[cur][0],pw[num]);
				be[cur]=k1;
			}
			id[k2]=-1;
			uad(hs,h[cur][1]);
		}else{
			if(id[k1]==id[k2]){
				int cur=id[k1];
				cycs.push_back(paths[cur]);
				usu(hs,h[cur][1]);
				uad(h[cur][SZ(paths[cur])&1],pw[num]);
				cycs.back().push_back(num);
				uad(hs,h[cur][1]);
				paths[cur].clear();
				id[k1]=id[k2]=-1;
			}else{
				if(SZ(paths[id[k1]])<SZ(paths[id[k2]]))swap(k1,k2);
				usu(hs,h[id[k2]][1]);
				if(be[id[k2]]!=k2)reverse(paths[id[k2]].begin(),paths[id[k2]].end()),swap(be[id[k2]],en[id[k2]]);
				int cur=id[k1];
				usu(hs,h[cur][1]);
				if(k1==be[cur]){
					paths[cur].push_front(num);
					swap(h[cur][0],h[cur][1]);
					uad(h[cur][0],pw[num]);
					for(int x:paths[id[k2]]){
						paths[cur].push_front(x);
						swap(h[cur][0],h[cur][1]);
						uad(h[cur][0],pw[x]);
					}
					be[cur]=en[id[k2]];
				}else{
					uad(h[cur][SZ(paths[cur])&1],pw[num]);
					paths[cur].push_back(num);
					for(int x:paths[id[k2]]){
						uad(h[cur][SZ(paths[cur])&1],pw[x]);
						paths[cur].push_back(x);
					}
					en[cur]=en[id[k2]];
				}
				uad(hs,h[cur][1]);
				id[en[id[k2]]]=id[k1];
				paths[id[k2]].clear();
				id[k1]=id[k2]=-1;
			}
		}
	}
	deg[k1]^=1,deg[k2]^=1,++num;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(id,-1,sizeof(id));
	pw[0]=1;
	rep(i,1,N-1)pw[i]=ad(pw[i-1],pw[i-1]);
	scanf("%d%d%d",&n1,&n2,&m);
	rep(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		y+=n1;
		ps(x,y);
	}
	scanf("%d",&Q);
	while(Q--){
		int o;
		scanf("%d",&o);
		if(o==1){
			int x,y;
			scanf("%d%d",&x,&y);
			y+=n1;
			ps(x,y);
			printf("%d\n",ad(hs,hs));
			fflush(stdout);
		}else{
			D("working and hash=%d\n",ad(hs,hs));
			vector<int>res;
			for(auto v:cycs){
				rep(i,0,SZ(v)-1)if(i&1)res.push_back(v[i]);
			}
			for(auto v:paths){
				rep(i,0,SZ(v)-1)if(i&1)res.push_back(v[i]);
			}
			printf("%d ",SZ(res));
			for(int x:res)printf("%d ",x+1);
			puts("");
			fflush(stdout);
		}
		/*for(auto v:paths){
			for(int x:v)D("|%d",x);
			D("|\n");
		}
		D("\n");
		rep(i,1,n1+n2)if(id[i]!=-1)assert(be[id[i]]==i||en[id[i]]==i);*/
	}
	return 0;
}