#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int INF=0X3F3F3F3F;
int n,m,len,S,T,typ[405],u1[805],v1[805],in[805];
char s[25][25],ans[55][55];
int pp,lnk[805],nxt[640005],to[640005];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int zip(int k1,int k2){return (k1-1)*m+k2;}
struct ufs{
	int fa[805];
	void init(int n){
		rep(i,1,n)fa[i]=i;
	}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
};
struct M1:ufs{
	bool chk(int k1,int k2){return fd(k1)!=fd(k2);}
	void mer(int k1,int k2){
		assert(chk(k1,k2));
		fa[fd(k1)]=fd(k2);
	}
}G1;
struct M2{
	int d[805];
	void init(int n){
		rep(i,1,n)d[i]=0;
	}
	bool chk(int k1,int k2){
		if(typ[k1]==2&&d[k1]>=2)return 0;
		if(typ[k2]==2&&d[k2]>=2)return 0;
		return 1;
	}
	void mer(int k1,int k2){
		assert(chk(k1,k2));
		++d[k1],++d[k2];
	}
}G2;
void bud(int bad){
	//D("bud bad=%d\n",bad);
	G1.init(n*m),G2.init(n*m);
	rep(i,1,len)if(in[i]&&i!=bad)
		G1.mer(u1[i],v1[i]),G2.mer(u1[i],v1[i]);
}
int dis[805],pre[805];
void bfs(){
	rep(i,1,T)dis[i]=INF,pre[i]=0;
	queue<int>q;
	dis[S]=0;
	q.push(S);
	while(SZ(q)){
		int k1=q.front();
		q.pop();
		for(int i=lnk[k1];i;i=nxt[i])if(dis[k1]+1<dis[to[i]]){
			dis[to[i]]=dis[k1]+1;
			pre[to[i]]=k1;
			q.push(to[i]);
		}
	}
}
void sol(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)	{
		if(s[i][j]=='X'||(i==1&&j==1)||(i+j)&1){
			typ[zip(i,j)]=1;
		}else{
			typ[zip(i,j)]=2;
		}
	}
	len=0;
	rep(i,1,n)rep(j,1,m-1)if((i!=1||j!=1)&&s[i][j]!='X'&&s[i][j+1]!='X'){
		u1[++len]=zip(i,j);
		v1[len]=zip(i,j+1);
	}
	rep(i,1,n-1)rep(j,1,m)if((i!=1||j!=1)&&s[i][j]!='X'&&s[i+1][j]!='X'){
		u1[++len]=zip(i,j);
		v1[len]=zip(i+1,j);
	}
	rep(i,1,len)in[i]=0;
	S=len+1,T=S+1;
	while(1){
		rep(i,1,T)lnk[i]=0;
		pp=0;
		rep(i,1,len)if(in[i]){
			bud(i);
			rep(j,1,len)if(!in[j]){
				if(G1.chk(u1[j],v1[j]))ae(i,j);
				if(G2.chk(u1[j],v1[j]))ae(j,i);
			}
		}
		bud(0);
		rep(i,1,len)if(!in[i]){
			if(G1.chk(u1[i],v1[i]))ae(S,i);
			if(G2.chk(u1[i],v1[i]))ae(i,T);
		}
		bfs();
		if(dis[T]==INF)break;
		for(int i=pre[T];i!=S;i=pre[i]){
			in[i]^=1;
		}
		/*D("((\n");
		bud(0);
		D("))\n");*/
	}
	/*rep(i,1,len)if(in[i]){
		D("(%d,%d) (%d,%d)\n",(u1[i]-1)/m+1,(u1[i]-1)%m+1,(v1[i]-1)/m+1,(v1[i]-1)%m+1);
	}*/
	G1.init(n*m);
	G2.init(n*m);
	memset(ans,' ',sizeof(ans));
	auto paint=[&](int k1,int k2){
		int a,b,c,d;
		a=(k1-1)/m+1;
		b=(k1-1)%m+1;
		c=(k2-1)/m+1;
		d=(k2-1)%m+1;
		int x=(a*2+c*2)/2-1;
		int y=(b*2+d*2)/2-1;
		ans[x][y]='$';
	};
	rep(i,1,n)rep(j,1,m)ans[i*2-1][j*2-1]=s[i][j];
	rep(i,1,len)if(in[i]){
		G1.mer(u1[i],v1[i]);
		G2.mer(u1[i],v1[i]);
		paint(u1[i],v1[i]);
	}
	rep(i,1,n*m){
		if(typ[i]==2&&G2.d[i]<2){
			puts("NO");return;
		}
	}
	rep(i,1,1)rep(j,1,1)if(s[i][j]!='X'&&s[i][j+1]!='X'){
		u1[++len]=zip(i,j);
		v1[len]=zip(i,j+1);
	}
	rep(i,1,1)rep(j,1,1)if(s[i][j]!='X'&&s[i+1][j]!='X'){
		u1[++len]=zip(i,j);
		v1[len]=zip(i+1,j);
	}
	rep(i,1,len){
		if(G1.chk(u1[i],v1[i])){
			G1.mer(u1[i],v1[i]);
			paint(u1[i],v1[i]);
		}
	}
	puts("YES");
	rep(i,1,n*2-1){
		rep(j,1,m*2-1)putchar(ans[i][j]);
		puts("");
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int tt;
	scanf("%d",&tt);
	rep(_,1,tt){
		//D("tt=%d\n",_);
		sol();
	}
	return 0;
}