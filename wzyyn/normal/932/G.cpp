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
const int mo=1000000007;
const int N=1000005;
int ch[N][26];
int nd,la,fa[N],l[N];
int dif[N],anc[N];
int f[N],g[N],n;
char ss[N],s[N];
void init(){
	nd=1; l[1]=-1;
	fa[0]=fa[1]=1; anc[0]=1;
}
void extend(int c,int n){
	int p=la;
	//cout<<la<<' '<<fa[la]<<endl;
	for (;s[n-l[p]-1]!=s[n];p=fa[p]);
	if (!ch[p][c]){
		int np=++nd,x=fa[p];
		//cout<<x<<' '<<p<<endl;
		for (;s[n-l[x]-1]!=s[n];x=fa[x]);
		l[np]=l[p]+2; fa[np]=ch[x][c];
		dif[np]=l[np]-l[fa[np]]; ch[p][c]=np;
		anc[np]=(dif[np]==dif[fa[np]]?anc[fa[np]]:fa[np]);
	}
	la=ch[p][c];
}
int main(){
	init();
	scanf("%s",ss+1);
	n=strlen(ss+1);
	assert(n%2==0);
	For(i,1,n/2) s[i*2-1]=ss[i];
	For(i,1,n/2) s[i*2]=ss[n-i+1];
	//printf("%s\n",s+1);
	g[0]=1;
	For(i,1,n){
		//cout<<233<<endl;
		extend(s[i]-'a',i);
		for (int j=la;j>1;j=anc[j]){
			//cout<<j<<' '<<l[j]<<' '<<anc[j]<<' '<<i-l[anc[j]]-dif[j]<<endl;
			f[j]=g[i-l[anc[j]]-dif[j]];
			if (anc[j]!=fa[j]) f[j]=(f[j]+f[fa[j]])%mo;
			if (i%2==0) g[i]=(g[i]+f[j])%mo;
		}
	}
	printf("%d\n",g[n]);
}