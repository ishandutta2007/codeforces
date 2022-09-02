#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1000005;
int n,m,st[N*4],d[N],top;bool ban[N];
int pp=1,lnk[N],nxt[N*4],to[N*4],col[N*4];bool vis[N*4];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void euler(int k1){
	ban[k1]=1;
//	for(int&i=lnk[k1];i;i=nxt[i])if(!vis[i>>1]){
//		vis[i>>1]=1;
//		int j=i>>1;
//		euler(to[i]);
//		st[++top]=j;
//	}
	for(;lnk[k1];lnk[k1]=nxt[lnk[k1]])if(!vis[lnk[k1]>>1]){
		vis[lnk[k1]>>1]=1;
		int j=lnk[k1]>>1;
		euler(to[lnk[k1]]);
		st[++top]=j;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2;scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
		++d[k1],++d[k2];
	}
	rep(i,1,n)if(d[i]&1){
		ae(i,n+1),ae(n+1,i);
	}
	rep(i,1,n){
		if(!ban[i]){
			top=0;
			euler(i);
			for(int j=1;j<=top;j+=2)
				if(st[j]>m)col[st[j+1]]=col[st[j-1]]=1;
				else col[st[j]]=1;
//			rep(j,1,top)printf("{%d,%d,*%d}",to[st[j]*2+1],to[st[j]*2],st[j]);
//			puts("");
		}
	}
	int tot=0;
	rep(i,1,m)if(col[i])++tot;
	printf("%d\n",tot);
	rep(i,1,m)if(col[i])printf("%d %d\n",to[i*2+1],to[i*2]);
	return 0;
}