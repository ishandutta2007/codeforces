#include<cstdio>
#include<cstring>
const int N=400005;
int n;char s[N];
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
struct SAM{
	int cnt,lst,fa[N],ch[N][26],len[N],a[N],c[N],r[N],f[N],id[N];
	int cur,root[N],lc[N*50],rc[N*50];
	SAM(){cnt=lst=1;}
	void change(int&u,int l,int r,int x){
		if(!u)u=++cur;if(l==r)return;int mid=l+r>>1;
		if(x<=mid)change(lc[u],l,mid,x);else change(rc[u],mid+1,r,x);
	}
	int merge(int u,int v){
		if(!u||!v)return u+v;int now=++cur;
		lc[now]=merge(lc[u],lc[v]);
		rc[now]=merge(rc[u],rc[v]);
		return now;
	}
	int query(int u,int l,int r,int lx,int rx){
		if(!u||lx>r||rx<l)return 0;if(lx<=l&&r<=rx)return 1;int mid=l+r>>1;
		if(rx<=mid)query(lc[u],l,mid,lx,rx);else
		if(mid<lx)query(rc[u],mid+1,r,lx,rx);else
			return query(lc[u],l,mid,lx,mid)||query(rc[u],mid+1,r,mid+1,rx);
	}
	void print(int u,int l,int r){
		if(!u)return;
		if(l==r)return;
		int mid=l+r>>1;
		print(lc[u],l,mid),print(rc[u],mid+1,r);
	}
	void extend(int c,int pos){
		int p=lst,np=lst=++cnt;len[np]=len[p]+1,r[np]=pos;
		for (;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if (!p)fa[np]=1;
		else{
			int q=ch[p][c];
			if (len[p]+1==len[q])fa[np]=q;
			else{
				int nq=++cnt;len[nq]=len[p]+1,r[nq]=pos;
				memcpy(ch[nq],ch[q],sizeof(ch[nq])),fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for (;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
			}
		}
	}
	void solve(){
		for(int i=1;i<=cnt;++i)++c[len[i]];
		for(int i=1;i<=cnt;++i)c[i]+=c[i-1];
		for(int i=cnt;i>=1;--i)a[c[len[i]]--]=i;
		for(int i=cnt;i>=1;--i){
			int p=a[i];
			if(r[p])
				change(root[p],1,n,r[p]);
			root[fa[p]]=merge(root[fa[p]],root[p]);
//			print(root[p],1,n);
		}
		int ans=0;
		for(int i=2;i<=cnt;++i){
			int p=a[i];
//			fprintf(stderr,"%d %d %d\n",id[fa[p]],r[p]-len[p]+len[id[fa[p]]],r[p]-1);
			if(fa[p]==1)f[p]=1,id[p]=p;
			else if(query(root[id[fa[p]]],1,n,r[p]-len[p]+len[id[fa[p]]],r[p]-1))f[p]=f[id[fa[p]]]+1,id[p]=p;
			else id[p]=id[fa[p]],f[p]=f[id[fa[p]]];
			ans=max(ans,f[p]);
		}
		printf("%d\n",ans);
	}
}sam;
int main(){
	scanf("%d",&n);
	scanf("%s",s);for(int i=0;s[i];++i)sam.extend(s[i]-'a',i+1);
	sam.solve();
	return 0;
}