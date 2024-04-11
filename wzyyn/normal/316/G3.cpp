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
const int N=1100005;
int ch[N][26],S[N][11];
int fa[N],l[N],L[11],R[11];
int n,ans,nd,la;
vector<int> e[N];
char s[N];
void extend(int c,int id){
	int p=la,np=++nd;
	l[np]=l[p]+1; ++S[np][id];
	for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (l[q]==l[p]+1) fa[np]=q;
		else{
			int nq=++nd; l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
	la=np;
}
void dfs(int x){
	for (auto i:e[x]){
		dfs(i);
		For(j,0,n) S[x][j]+=S[i][j];
	}
	if (S[x][0]){
		bool fl=1;
		For(j,1,n)
			if (S[x][j]<L[j]||S[x][j]>R[j])
				fl=0;
		if (fl) ans+=l[x]-l[fa[x]];
	}
}
int main(){
	nd=la=1;
	scanf("%s",s+1);
	int m=strlen(s+1);
	For(i,1,m) extend(s[i]-'a',0);
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s%d%d",s+1,&L[i],&R[i]);
		int m=strlen(s+1); la=1;
		For(j,1,m) extend(s[j]-'a',i);
	}
	For(i,2,nd) e[fa[i]].PB(i);
	dfs(1);
	printf("%d\n",ans);
}