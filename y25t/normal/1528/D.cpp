#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 605

char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define putchar(c) (*O++=c)
inline void rd(int &x){
	x=0;
	static char c;
	c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void wr(ll x){
	if(x>=10)
		wr(x/10);
	putchar(x%10+'0');
}

int n,m;

int e[N][N],d[N][N];

ll dis[N][N];
bool vis[N];
inline void dij(int s){
	dis[s][s]=0;
	memset(vis,0,sizeof(vis));
	for(int _=1;_<=n;_++){
		int u=-1;
		for(int i=0;i<n;i++)
			if(!vis[i]&&(u==-1||dis[s][i]<dis[s][u]))
				u=i;
		if(u==-1)
			break;
		vis[u]=1;
		for(int i=0;i<n;i++)
			dis[s][i]=std::min(dis[s][i],dis[s][u]+d[u][(i-dis[s][u]%n+n)%n]);
	}
}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n),rd(m);
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++){
		int a,b,c;
		rd(a),rd(b),rd(c);
		e[a][b]=c;
	}
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				d[i][(j+k)%n]=std::min(d[i][(j+k)%n],e[i][j]+k);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<n;i++)
		dij(i);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			wr(dis[i][j]),putchar(' ');
		putchar('\n');
	}
	fwrite(obuf,O-obuf,1,stdout);
}