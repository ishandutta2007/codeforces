#include<bits/stdc++.h>
#define N 205

int T;

int n,p[N];

bool vis[N];
int q[N];

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
inline bool mrg(int u,int v){
	u=fnd(u),v=fnd(v);
	return u!=v?f[u]=v,1:0;
}
int l[N],r[N];
bool a[N],b[N],c[N],d[N];
inline bool chk(int m){
	if(m==n)
		return 1;
	for(int i=1;i<=n;i++)
		f[i]=l[i]=r[i]=a[i]=b[i]=c[i]=d[i]=0;
	for(int i=1;i<=n;i++)
		mrg(i,p[i]);
	for(int i=1;i<m;i++){
		int u=q[i],v=p[q[i+1]];
		if(u<=v){
			for(int j=u;j<v;j++){
				if(a[j])
					return 0;
				a[j]=1,c[j]=1;
			}
			c[v]=1;
			r[u]++,l[v]++;
		}
		if(u>=v){
			for(int j=v;j<u;j++){
				if(b[j])
					return 0;
				b[j]=1,d[j]=1;
			}
			d[u]=1;
			l[u]++,r[v]++;
		}
	}
	for(int i=1;i<=n;i++) if(c[i]&&d[i]&&!l[i]&&!r[i])
		return 0;
	for(int i=1;i<n;i++) if((a[i]||b[i])&&!mrg(i,i+1))
		return 0;
	for(int i=1;i<n;i++) if(l[i]<2&&r[i+1]<2)
		mrg(i,i+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=!f[i];
	return cnt==1;
	
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) if(!vis[j]){
				q[i]=j;
				if(chk(i)){
					vis[j]=1;
					break;
				}
			}
		for(int i=1;i<=n;i++)
			printf("%d ",q[i]);
		puts("");
	}
}