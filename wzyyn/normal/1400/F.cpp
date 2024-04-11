#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=90005;
int ch[N][10],fa[N],q[N];
int vi[30],a[30],nd=1;
int f[N],g[N],GG[N],n,x;
char s[N];
void Insert(int d){
	int x=1;
	For(i,1,d){
		//cout<<a[i]<<' ';
		if (!ch[x][a[i]])
			ch[x][a[i]]=++nd;
		x=ch[x][a[i]];
	}
	cout<<endl;
	GG[x]=1; 
}
void dfs(int d,int s){
	//cout<<d<<' '<<s<<endl;
	For(i,(s==x?1:0),s-1) if (x%(s-i)==0&&vi[i]) return;
	if (s==x) return Insert(d-1);
	For(i,1,min(x-s,9)) a[d]=i,vi[s+i]=1,dfs(d+1,s+i),vi[s+i]=0;
}
void build_fail(){
	int h=0,t=0;
	For(i,1,9)
		if (!ch[1][i])
			ch[1][i]=1;
		else{
			q[++t]=ch[1][i];
			fa[ch[1][i]]=1;
		}
	while (h!=t){
		int x=q[++h];
		For(i,1,9)
			if (!ch[x][i])
				ch[x][i]=ch[fa[x]][i];
			else{
				fa[ch[x][i]]=ch[fa[x]][i];
				q[++t]=ch[x][i];
			}
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&x);
	vi[0]=1; dfs(1,0);
	build_fail();
	memset(f,233,sizeof(f));
	memset(g,233,sizeof(g));
	f[1]=0;
	For(i,1,n){
		int c=s[i]-'0';
		For(j,1,nd) g[ch[j][c]]=max(g[ch[j][c]],f[j]+1);
		For(j,1,nd) if (!GG[j]) f[j]=max(f[j],g[j]);
	}
	int ans=0;
	For(i,1,nd) ans=max(ans,f[i]);
	cout<<n-ans<<endl;
}