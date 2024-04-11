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
const int N=400005;
const int M=12000005;
int ls[M],rs[M];
int rt[N],ndd;
void insert(int &k,int l,int r,int p){
	if (!k) k=++ndd;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	int k=++ndd;
	ls[k]=merge(ls[x],ls[y]);
	rs[k]=merge(rs[x],rs[y]);
	return k;
} 
bool ask(int k,int l,int r,int x,int y){
	//printf("%d %d %d %d %d\n",k,l,r,x,y);
	if (!k) return 0;
	if (l==x&&r==y) return 1;
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)|ask(rs[k],mid+1,r,mid+1,y);
}
int ch[N][26],cnt[N];
int pos[N],fa[N],l[N];
int q[N],f[N],top[N];
int n,la,nd,ans;
char s[N];
void extend(int c,int pos){
	int p=la,np=++nd;
	l[np]=l[p]+1; ::pos[np]=pos;
	for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (l[q]==l[p]+1) fa[np]=q;
		else{
			int nq=++nd;
			l[nq]=l[p]+1; ::pos[nq]=::pos[q];
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
	la=np;
}
int main(){
	nd=la=1;
	scanf("%d%s",&n,s+1);
	For(i,1,n){
		extend(s[i]-'a',i);
		insert(rt[la],1,n,i);
	}
	For(i,1,nd) cnt[l[i]]++;
	For(i,1,nd) cnt[i]+=cnt[i-1];
	Rep(i,nd,1) q[cnt[l[i]]--]=i;
	Rep(i,nd,2) rt[fa[q[i]]]=merge(rt[fa[q[i]]],rt[q[i]]);
	For(i,2,nd){
		int x=q[i];
		//printf("%d %d %d %d\n",x,fa[x],l[x],pos[x]);
		if (fa[x]==1)
			f[x]=1,top[x]=x;
		else{
			f[x]=f[fa[x]];
			top[x]=top[fa[x]];
			if (ask(rt[top[x]],1,n,pos[x]-l[x]+l[top[x]],pos[x]-1))
				f[x]++,top[x]=x;
		}
		ans=max(ans,f[x]);
	}
	printf("%d\n",ans);
}