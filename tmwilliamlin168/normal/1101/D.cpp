#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#define inf 1000000000
#define N 200005
typedef long long ll;
using namespace std;
int flag[N],tot,ans,n,to[N*2],head[N],net[N*2],fa[N],a[N],f[N][10][3],a1,a2;
int gets(){
	int v=0;bool f=0;char ch;
	while(!isdigit(ch)) { f|=ch=='-'; ch=getchar(); }
	while( isdigit(ch)) { v=(v<<3)+(v<<1)+ch-48; ch=getchar(); }
	return f?-v:v;
}
vector <int> p[N];
void init(){
	int lim=200000;
	for(int i=2;i<=lim;i++)	if(!flag[i]) 
		for(int j=i;j<=lim;j+=i) p[j].push_back(i), flag[j]=1;
}
int gcd(int a,int b){
	return (b==0?a:(b,a%b));
}
int ins(int frm,int to2){
	to[++tot]=to2, net[tot]=head[frm], head[frm]=tot;
	to[++tot]=frm, net[tot]=head[to2], head[to2]=tot;
}
void dfs(int x){
	for(int t=head[x];t;t=net[t])
		if(fa[x]!=to[t]){
			fa[to[t]]=x, dfs(to[t]);
		}
	for(int i=0;i< p[a[x]].size();i++) {
		for(int t=head[x];t;t=net[t]) if(fa[x]!=to[t]){
			for(int j=0;j< p[a[to[t]]].size();j++) if(p[a[x]][i]==p[a[to[t]]][j]){
				if(f[to[t]][j][1]>=f[x][i][1]) f[x][i][2]=f[x][i][1], f[x][i][1]=f[to[t]][j][1];
				else if(f[to[t]][j][1]>f[x][i][2]) f[x][i][2]=f[to[t]][j][1];
			}
		}
		f[x][i][1]++; ans=max(ans,f[x][i][1]+f[x][i][2]);
	}
}
int main ()
{
	init();
	n=gets();
	for(int i=1;i<=n;i++) a[i]=gets();
	for(int i=1;i< n;i++) 
		a1=gets(), a2=gets(), ins(a1,a2);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}