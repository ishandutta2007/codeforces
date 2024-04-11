#include<bits/stdc++.h>
#define intt long long 
using namespace std;
const int maxx = 6000001;
const int inf = 100000001;
int q[maxx],head,tail,tot,st,ed,n,m,Min;
int lin[maxx],len=1,flag[maxx],dis[maxx],nt[maxx];
int v[maxx];
struct edge{
	int x,y,v,next,f,M;
}e[maxx];
int read(){int k;scanf("%d",&k);return k;}
int ans=0;
int X(int x,int y){if(x>y)return x-y;else return y-x;}
void init(int x,int y,int f,int v){e[++len].M=f;e[len].y=y;e[len].next=lin[x];e[len].x=x;e[len].v=v;e[len].f=f;lin[x]=len;}
bool spfa(){	
	for(int i=1;i<=tot;i++)dis[i]=inf,flag[i]=0,nt[i]=-1;
	q[++tail]=st;flag[st]=1;dis[st]=0;nt[st]=0;
	while(head+1<=tail){
		int x=q[++head];flag[x]=0;
		for(int i=lin[x];i;i=e[i].next){
			if(e[i].f==0)continue;
			int y=e[i].y;
			if(dis[y]>dis[x]+e[i].v){
				dis[y]=dis[x]+e[i].v;nt[y]=i;	
				if(flag[y])continue;	
				flag[y]=1;q[++tail]=y;	
			}	
		}	
	}	
	return dis[ed]!=inf;
}	
int rid[maxx];
int w=0;
void updata(){
	int i=nt[ed];int x=e[i].x;Min=inf;
	while(i){
		Min=min(Min,e[i].f);
		i=nt[x];x=e[i].x;
	}i=nt[ed];x=e[i].x;
	while(i){
		e[i].f-=Min;
		e[i^1].f+=Min;
		i=nt[x];x=e[i].x;
	}	
	ans+=dis[ed]*Min;
	w+=Min;
}
void slove(){	
	ans=0;
	while(spfa())updata();
}
void insert(int x,int y,int f,int v){
	init(x,y,f,-v);init(y,x,0,+v);
}
int lx[maxx],rx[maxx],valx[maxx];
int fs[maxx],rxid[maxx];
int bit(int x,int id){	
	return (x>>id)&1;
}	
void pre(){	
	int N = 1<<11;
	for(int i=0;i<N;i++)lx[i]=++tot,fs[tot]=1,rxid[tot]=i,rx[i]=++tot,fs[tot]=2,rid[tot]=i;
	for(int i=0;i<N;i++){	
		for(int x=0;x<11;x++){
			if(bit(i,x))valx[i]++,insert(lx[i],lx[i-(1<<x)],inf,0),insert(lx[i],rx[i-(1<<x)],inf,0);
		}	
	}	
}	
//?????
char s[maxx];
int fw[maxx],fk[maxx]; 
int ntx[maxx];
int dfs(int x,int fa){	
	int flag=0;	
	for(int i=lin[x];i;i=e[i].next){	
		if(e[i].f>=e[i].M)continue;	
		if(e[i].y==ed){		
			ntx[rid[x]]=fa;
			e[i].f+=1;e[i^1].f-=1;	
			return 1;	
		}	
		flag=dfs(e[i].y,fa);
		if(flag){	
			e[i].f+=1;
			e[i^1].f-=1;
			return flag;
		}	
	}	
	return 0;	
}	
void initx(){	
	pre();
	int k=read();n=read();int N = 1<<11;
	intt Ans=0;
	for(int i=1;i<=n;i++){	
		scanf("%s",s+1);
		int len = strlen(s+1),w=1,idx = 0;
		for(int i=1;i<=len;i++){
			if(s[i]=='1')idx+=w;
			w=w*2;
		}	
		fw[idx]=1;
	}	
	Ans--;
	st=++tot;ed=++tot;
	
	
	for(int i=0;i<N;i++){	
		if(fw[i]){
			Ans+=valx[i]+1;
			insert(st,lx[i],1,0);
			insert(rx[i],ed,1,valx[i]+1);
		}	
	}	
	
	slove();
	cout<<Ans+ans<<endl;
	for(int i=lin[st];i;i=e[i].next){	
		int y=e[i].y;
		if(e[i].f==0&&fw[rxid[y]]){	
			fk[rxid[y]]=1;
		}	
	}	
	
	for(int i=0;i<N;i++)if(fk[i])dfs(lx[i],i);
	
	int fd=0;
	for(int i=0;i<N;i++){	
		if(!fw[i])continue;
		int x = i,lt=0;
		if(fd)printf("R ");fd=1;
		while(x){	
			for(int c=0;c<11;c++){	
				if(bit(x,c)&&!bit(lt,c))printf("%d ",c);
			}	
			lt=x;x=ntx[x];fw[x]=0;
		}	
	}	
	return ;
}	
int main(){
	initx();
	slove();
	return 0;
}