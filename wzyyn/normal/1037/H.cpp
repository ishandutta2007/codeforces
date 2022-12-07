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
const int N=200005;
const int M=10000005;
int ch[N][26],nd,la,n;
int l[N],fa[N],id[N];
vector<int> e[N];
char s[N];
void extend(int c,int id){
	::id[la]=id;
	int p=la,np=++nd; l[np]=l[p]+1;
	//cout<<p<<endl;
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
int ls[M],rs[M],S[M];
int rt[N],ndd;
void insert(int &k,int l,int r,int p){
	if (!k) k=++ndd;
	S[k]|=1<<(s[p]-'a');
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p);
}
int merge(int x,int y){
	if (!x||!y) return x|y;
	int k=++ndd;
	S[k]=S[x]|S[y];
	ls[k]=merge(ls[x],ls[y]);
	rs[k]=merge(rs[x],rs[y]);
	return k;
}
int ask(int k,int l,int r,int x,int y){
	if (!k) return 0;
	if (l==x&&r==y) return S[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)|ask(rs[k],mid+1,r,mid+1,y);
}
void dfs(int x){
	if (id[x]) insert(rt[x],1,n,id[x]);
	for (auto i:e[x]) dfs(i),rt[x]=merge(rt[x],rt[i]); 
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1); nd=la=1;
	For(i,1,n) extend(s[i]-'a',i); 
	For(i,2,nd) e[fa[i]].PB(i);
	//For(i,2,nd) printf("%d %d %d\n",fa[i],l[i],id[i]);
	dfs(1);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d%s",&l,&r,s+1);
		int m=strlen(s+1); s[++m]='a'-1;
		int p1=-1,p2=-1,x=1;
		For(i,1,min(m,r-l+1)){
			int st=ask(rt[x],1,n,l+i-1,r);
			Rep(j,25,s[i]-'a'+1)
				if (st&(1<<j)) p1=i,p2=j;
			if (!(x=ch[x][s[i]-'a'])) break;
		}
		if (p1==-1) puts("-1");
		else{
			s[p1]=p2+'a',s[p1+1]=0;
			printf("%s\n",s+1);
		}
	}
}