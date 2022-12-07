#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=405;
bitset<N> e[N];
int n,m,chr,vis[5];
char t[N],s[N],ans[N];
void dfs(int x,int y){
	if (x>n){
		printf("%s\n",ans+1);
		exit(0);
	}
	int V=1,C=1;
	For(i,1,x-1){
		V&=!e[i*2+t[ans[i]-'a']][x*2];
		V&=!e[x*2+1][i*2+1-t[ans[i]-'a']];
		C&=!e[i*2+t[ans[i]-'a']][x*2+1];
		C&=!e[x*2][i*2+1-t[ans[i]-'a']];
	}
	For(i,(y?'a':s[x]),'a'+chr-1)
		if ((t[i-'a']&&V)||(!t[i-'a']&&C))
			ans[x]=i,dfs(x+1,y|(i>s[x]));
}
int main(){
	scanf("%s%d%d",t,&n,&m);
	chr=strlen(t);
	For(i,0,chr-1) t[i]=(t[i]=='V');
	For(i,0,chr-1) vis[t[i]]=1;
	For(i,1,n){
		if (!vis[0]) e[i*2][i*2+1]=1;
		if (!vis[1]) e[i*2+1][i*2]=1;
	}
	For(i,1,m){
		int x,y;
		char s1[5],s2[5];
		scanf("%d%s%d%s",&x,s1,&y,s2);
		x=x*2+(s1[0]=='V');
		y=y*2+(s2[0]=='V');
		e[x][y]=e[y^1][x^1]=1;
	}
	For(k,2,2*n+1) For(i,2,2*n+1)
		if (e[i][k]) e[i]|=e[k];
	For(i,1,n)
		if (e[i*2][i*2+1]&&e[i*2+1][i*2])
			return puts("-1"),0;
	scanf("%s",s+1);
	dfs(1,0);
	puts("-1");
}