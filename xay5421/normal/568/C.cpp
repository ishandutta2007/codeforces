#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=205,M=4*N*N,INF=0X3F3F3F3F;
int n,m,ans[N*2];
bool g[N*2][N*2];
char a[N],s[N];
void ae(int k1,int k2){
	g[k1][k2]=1;
}
int getc(){
	int c;while(!isalpha(c=getchar()));
	return c;
}
int fdnot(int pos){
	pos-='a';
	for(int i=pos+1;a[i];++i){
		if(a[pos]!=a[i])return i+'a';
	}
	return INF;
}
int fdsame(int pos){
	pos-='a';
	for(int i=pos+1;a[i];++i){
		if(a[pos]==a[i])return i+'a';
	}
	return INF;
}
int qd[N*2],nqd[N*2],mxp[2];
bool chk(int pos,int now,int x,int f){
	if(qd[pos]!=-1&&qd[pos]!=(a[now-'a']=='V'))return 0;
	for(int i=1;i<=n;++i)if(g[x][i]&&g[x][i+n])return 0;
	for(int i=1;i<=n;++i){
		nqd[i]=-1;
		if(g[x][i])nqd[i]=0;
		if(g[x][i+n])nqd[i]=1;
		nqd[i]=max(nqd[i],qd[i]);
		if(qd[i]!=-1&&nqd[i]!=-1&&qd[i]!=nqd[i]){
			return 0;
		}
	}
	if(f){
		for(int i=pos+1;i<=n;++i){
			int tmp=max(qd[i],nqd[i]);
			if(tmp==-1)break;
			if(mxp[tmp]<s[i]-'a')return 0;
			if(mxp[tmp]>s[i]-'a')break;
		}
	}
	for(int i=1;i<=n;++i)qd[i]=max(qd[i],nqd[i]);
	return 1;
}
int main(){
	memset(qd,-1,sizeof(qd));
	scanf("%s",a);
	mxp[0]=mxp[1]=-1;
	for(int i=0;a[i];++i)mxp[a[i]=='V']=i;
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2,k3,k4;
		scanf("%d",&k1),k2=(getc()=='V'),scanf("%d",&k3),k4=(getc()=='V');
		ae(k1+k2*n,k3+k4*n),ae(k3+(k4^1)*n,k1+(k2^1)*n);
	}
	scanf("%s",s+1);
	rep(k,1,n*2)rep(i,1,n*2)rep(j,1,n*2)g[i][j]|=g[i][k]&&g[k][j];
	bool f=1;
	rep(i,1,n){
		int cur=f?s[i]:'a';
		if(chk(i,cur,i+(a[cur-'a']=='V')*n,f))ans[i]=cur;
		else{
			int pos1=fdnot(cur),pos2=fdsame(cur);
			if(pos1>pos2)swap(pos1,pos2);
			if(pos1<INF&&chk(i,pos1,i+(a[pos1-'a']=='V')*n,0))ans[i]=pos1,f=0;
			else if(pos2<INF&&chk(i,pos2,i+(a[pos2-'a']=='V')*n,0))ans[i]=pos2,f=0;
			else{
				puts("-1"),exit(0);
			}
		}
	}
	rep(i,1,n)putchar(ans[i]);
	return 0;
}