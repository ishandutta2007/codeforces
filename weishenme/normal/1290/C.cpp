#include<bits/stdc++.h>
using namespace std;
const int N=600005;
vector<int> v[N];
int Id[N],vis[N],n,m,id[N],x,y,f[N],fi[N],ne[N],size1[N],size2[N],zz[N],tot,rk[N];
char s[N];
struct Tree{
	int l,r,num1,num2,flag;
}T[N*4];
void update(int x){
	T[x].num1=T[x*2].num1+T[x*2+1].num1;
	T[x].num2=T[x*2].num2+T[x*2+1].num2;
}
void build(int x,int l,int r){
	T[x].l=l;T[x].r=r;
	if (l==r){
		T[x].num1=Id[l]<=m;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	update(x);
}
void down(int x){
	if (T[x].flag){
		T[x*2].flag^=1;
		T[x*2+1].flag^=1;
		T[x*2].num2=T[x*2].num1-T[x*2].num2;
		T[x*2+1].num2=T[x*2+1].num1-T[x*2+1].num2;
		T[x].flag=0;
	}
}
void insert(int x,int l,int r){
	if (T[x].l>r||l>T[x].r)return;
	if (T[x].l>=l&&T[x].r<=r){
		T[x].flag^=1;
		T[x].num2=T[x].num1-T[x].num2;
		return;
	}
	down(x);
	insert(x*2,l,r);
	insert(x*2+1,l,r);
	update(x);
}
int find(int x,int l,int r){
	if (T[x].l>r||l>T[x].r)return 0;
	if (T[x].l>=l&&T[x].r<=r)return T[x].num2;
	down(x);
	return find(x*2,l,r)+find(x*2+1,l,r);
}
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x){
	rk[x]=++tot;Id[tot]=x;
	size1[x]=x<=m;
	size2[x]=1;
	for (int i=fi[x];i;i=ne[i]){
		dfs(zz[i]);
		size1[x]+=size1[zz[i]];
		size2[x]+=size2[zz[i]];
		vis[x]|=vis[zz[i]];
	}
}
int Find(int x){
	if (x==f[x])return x;
	return f[x]=Find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		while (x--)scanf("%d",&y),v[y].push_back(i);
	}
	for (int i=1;i<=n+m;i++)f[i]=i;
	int cnt=m;
	for (int i=1;i<=n;i++){
		if (!v[i].size())continue;
		if (v[i].size()==1){
			id[i]=Find(v[i][0]);
			vis[id[i]]=1;
			continue;
		}
		int x=Find(v[i][0]),y=Find(v[i][1]);
		if (x==y)continue;
		cnt++;
		f[x]=f[y]=cnt;
		id[i]=cnt;
		jb(cnt,x);jb(cnt,y);
	}
	tot=0;
	for (int i=1;i<=cnt;i++)
		if (Find(i)==i)dfs(i);
	build(1,1,cnt);
	cnt=m;
	for (int i=1;i<=n+m;i++)f[i]=i;
	for (int i=1;i<=n;i++){
		if (!v[i].size()){
			printf("%d\n",T[1].num2);
			continue;
		}
		if (v[i].size()==1){
			int x=v[i][0];
			if (find(1,rk[x],rk[x])==s[i]-'0')
				insert(1,rk[id[i]],rk[id[i]]+size2[id[i]]-1);
		}
		else {
			int x=v[i][0],y=v[i][1];
			if (!id[i]){
				printf("%d\n",T[1].num2);
				continue;
			}
			if ((find(1,rk[x],rk[x])^find(1,rk[y],rk[y]))==s[i]-'0'){
				x=Find(x);y=Find(y);
				int s1=find(1,rk[x],rk[x]+size2[x]-1);
				int s2=find(1,rk[y],rk[y]+size2[y]-1);
				if (vis[x])s1=-1e9;
				if (vis[y])s2=-1e9;
				if (size1[x]-2*s1<=size1[y]-2*s2)insert(1,rk[x],rk[x]+size2[x]-1);
				else insert(1,rk[y],rk[y]+size2[y]-1);
			}
			x=Find(x);y=Find(y);
			f[x]=f[y]=++cnt;
		}
		printf("%d\n",T[1].num2);
	}
}