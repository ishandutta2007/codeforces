#include<bits/stdc++.h>
#define N 50
#define M 23

int n,a[N][N];
char s[N];

int f[N],sz[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
inline void uni(int x,int y){
	int fx=fnd(x),fy=fnd(y);
	if(fx!=fy){
		f[fx]=fy;
		sz[fy]+=sz[fx];
	}
}

int m,num[M],id[N],b[M][M];

int lg[1<<M],cnt[1<<M];
inline int lb(int x){
	return x&-x;
}

int g[1<<M],h[1<<M];
inline void fwt(){
	for(int k=1;k<(1<<m);k<<=1)
		for(int i=0;i<(1<<m);i+=(k<<1))
			for(int j=0;j<k;j++)
				g[i+j+k]+=g[i+j];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		sz[i]=1;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			a[i][j]=s[j]=='X';
			if(s[j]=='A')
				uni(i,j);
		}
	}
	memset(id,-1,sizeof(id));
	for(int i=1;i<=n;i++)
		if(!f[i]&&sz[i]>1){
			id[i]=m;
			num[m++]=i;
		}
	if(!m){
		printf("%d\n",n-1);
		return 0;
	}
	for(int i=1;i<=n;i++)
		id[i]=id[fnd(i)];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]&&(~id[i])&&(~id[j])){
				if(id[i]==id[j]){
					puts("-1");
					return 0;
				}
				b[id[i]][id[j]]=1;
			}
	for(int i=0;i<m;i++)
		lg[1<<i]=i;
	for(int i=1;i<(1<<m);i++)
		cnt[i]=cnt[i>>1]+(i&1);
	g[0]=1;
	for(int l=1;l<(1<<m);l++){
		int i=lg[lb(l)];
		g[l]=g[l^(1<<i)];
		for(int j=i+1;j<m;j++)
			if(((l>>j)&1)&&b[j][i])
				g[l]=0;
	}
	fwt();
	for(int i=0;i<(1<<m);i++)
		h[i]=g[i];
	for(int i=1;i<=m;i++){
		int tmp=0;
		for(int j=0;j<(1<<m);j++)
			tmp+=(cnt[j^((1<<m)-1)]&1?-1:1)*h[j];
		if(tmp){
			printf("%d\n",n+i-1);
			break;
		}
		for(int j=0;j<(1<<m);j++)
			h[j]*=g[j];
	}
}