#include<set>
#include<cstdio>
#include<cstring>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
int n,m,w0,w1,ind,f[71],sz[71],val[71],dis[71][131073];
struct ed{ed*nxt;int to,w;}pool[405],*p=pool,*lnk[71];
void ae(int u,int v,int w){*++p=(ed){lnk[u],v,w},lnk[u]=p;}
struct S{int a,b;bool operator<(const S&v)const{return dis[a][b]^dis[v.a][v.b]?dis[a][b]<dis[v.a][v.b]:a^v.a?a<v.a:b<v.b;}};std::set<S>H;
int get(int i){return f[i]==i?i:f[i]=get(f[i]);}
void push(S u,int x){if(dis[u.a][u.b]>x)H.erase(u),dis[u.a][u.b]=x,H.insert(u);}
int main(){
	memset(dis,63,sizeof(dis));
	scanf("%d%d%d%d",&n,&m,&w0,&w1);
	rep(i,1,n)sz[i]=1,f[i]=i,val[i]=-1;
	rep(i,1,m){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);ae(u,v,w),ae(v,u,w);
		if(w==w0)sz[get(v)]+=sz[get(u)],f[get(u)]=get(v);
	}
	rep(i,1,n)if(get(i)==i&&sz[i]>3){
		rep(j,1,n)if(get(i)==get(j))val[j]=ind;
		++ind;
	}
	push((S){1,~val[1]?1<<val[1]:0},0);
	while(!H.empty()){
		S u=*H.begin();H.erase(H.begin());
		for(ed*i=lnk[u.a];i;i=i->nxt){
			if(i->w==w0)push((S){i->to,u.b},dis[u.a][u.b]+i->w);
			else{
				if(get(u.a)==get(i->to))continue;
				if((~val[i->to])&&(u.b&(1<<val[i->to])))continue;
				push((S){i->to,u.b|(~val[i->to]?1<<val[i->to]:0)},dis[u.a][u.b]+i->w);
			}
		}
	}
	rep(i,1,n){
		int res=0x3f3f3f3f;
		rep(s,0,(1<<ind)-1)if(dis[i][s]<res)res=dis[i][s];
		printf("%d ",res);
	}
	return 0;
}