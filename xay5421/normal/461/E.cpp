#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
using LL=long long;
const int N=200005,INF=0X3F3F3F3F;
LL n;
char s[N];
struct SAM{
	int fa[N],ch[N][4],len[N],lst,cnt;
	SAM(){lst=cnt=1;}
	void ps(int c){
		int p=lst,np=lst=++cnt; len[np]=len[p]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];
		if(len[p]+1==len[q]){fa[np]=q;return;}
		int nq=++cnt; len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=fa[np]=nq;
		for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	bool vis[N];
	int dp[N][4];
	void dfs(int k1){
		if(vis[k1])return;
		vis[k1]=1;
		fill(dp[k1],dp[k1]+4,INF);
		rep(i,0,3){
			if(ch[k1][i]){
				dfs(ch[k1][i]);
				rep(j,0,3){
					umin(dp[k1][j],dp[ch[k1][i]][j]+1);
				}
			}else{
				umin(dp[k1][i],1);
			}
		}
	}
	void bud(){
		dfs(1);
	}
}A;
struct mat{
	LL a[4][4];
	mat operator*(const mat&b)const{
		mat c;
		memset(c.a,63,sizeof(c.a));
		rep(i,0,3)rep(j,0,3)rep(k,0,3)umin(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
}pw[65];
int main(){
	scanf("%lld%s",&n,s+1);
	for(int i=1;s[i];++i)A.ps(s[i]-'A');
	A.bud();
	rep(i,0,3)rep(j,0,3){
		pw[0].a[i][j]=A.dp[A.ch[1][i]][j];
	}
	rep(i,1,60)pw[i]=pw[i-1]*pw[i-1];
	mat cur;
	memset(cur.a,0,sizeof(cur.a));
	LL ans=0;
	per(i,60,0){
		mat nex=cur*pw[i];
		LL res=5e18;
		rep(j,0,3)rep(k,0,3){
			umin(res,nex.a[j][k]);
		}
		if(res<n){
			ans+=1LL<<i;
			cur=nex;
		}
	}
	printf("%lld\n",ans+1);
	return 0;
}