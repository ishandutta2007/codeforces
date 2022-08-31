#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int c[605][605],dis[605],to[605];
bool vis[605];

int main(){
	n=readint(); m=readint();
	int x,y,z;
	memset(c,0x3f,sizeof(c));
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		c[x][y]=z;
	}
	for(int i=0;i<n;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[i]=0;
		for(int j=1;j<=n;j++){
			int mina=dis[n],opt=0;
			for(int k=0;k<n;k++) if(!vis[k]&&chkmin(mina,dis[k])) opt=k;
			vis[opt]=1;
			int tmp=dis[opt]%n;
			for(int k=0;k<n;k++) to[k]=dis[n];
			for(int k=0;k<n;k++) to[(k+tmp)%n]=c[opt][k];
			for(int k=1;k<n;k++) chkmin(to[k],to[k-1]+1);
			chkmin(to[0],to[n-1]+1);
			for(int k=1;k<n;k++) chkmin(to[k],to[k-1]+1);
			for(int k=0;k<n;k++) chkmin(dis[k],dis[opt]+to[k]);
		}
		for(int j=0;j<n;j++) printf("%d ",dis[j]);
		printf("\n");
	}
	return 0;
}