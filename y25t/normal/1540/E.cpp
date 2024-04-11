#include<bits/stdc++.h>
#define P 1000000007
#define N 305

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n,a[N],q;

std::vector<int> E[N];

int A[N][N],b[N][N],c[N][N],s[N][N];
inline void init(){
	static int B[N][N];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				B[i][j]=A[i][j];
		for(int i=1;i<=n;i++)
			B[i][n+1]=0;
		for(int i=1;i<=n;i++)
			B[i][i]=fmo(B[i][i]-k);
		for(int i=n;i;i--){
			b[k][i]=B[i][i]?1ll*B[i][n+1]*fp(B[i][i])%P:1;
			for(int j=i-1;j;j--)
				B[j][n+1]=fmo(B[j][n+1]-1ll*b[k][i]*B[j][i]%P);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=fmo(s[i][j-1]+b[i][j]-P);
	for(int i=1;i<=n;i++){
		c[i][i]=1;
		for(int j=i;j;j--)
			for(int k=j-1;k;k--)
				c[i][k]=fmo(c[i][k]-1ll*c[i][j]*b[j][k]%P);
	}
}

int t[N][N];
inline int lb(int x){
	return x&-x;
}
inline void add(int i,int x,int d){
	for(;x<=n;x+=lb(x))
		t[i][x]=fmo(t[i][x]+d-P);
}
inline int sum(int i,int x){
	int res=0;
	for(;x;x-=lb(x))
		res=fmo(res+t[i][x]-P);
	return res;
}

std::pair<int,int> D[N]; 
int d[N],p[N];
inline int dfs(int u){
	if(~d[u])
		return d[u];
	if(a[u]>0)
		return d[u]=0;
	d[u]=P-1;
	for(auto v:E[u])
		d[u]=std::min(d[u],dfs(v)+1);
	return d[u];
}
int val[N][N];
inline void getd(){
	for(int i=1;i<=n;i++)
		d[i]=-1;
	for(int i=1;i<=n;i++)
		dfs(i);
	for(int i=1;i<=n;i++)
		D[i]={d[i],i};
	std::sort(D+1,D+n+1);
	for(int i=1;i<=n;i++)
		p[D[i].second]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			t[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			val[i][j]=1ll*c[i][j]*fp(j,P-1-d[i])%P;
			add(j,p[i],1ll*fmo(a[i])*val[i][j]%P);
		}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		A[i][i]=i;
		int k;
		scanf("%d",&k);
		while(k--){
			int j;
			scanf("%d",&j);
			A[i][j]=j;
			E[i].push_back(j);
		}
	}
	init();
	getd();
	scanf("%d",&q);
	while(q--){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int k,l,r;
			scanf("%d%d%d",&k,&l,&r);
			int i=std::upper_bound(D+1,D+n+1,std::make_pair(k,0))-D-1;
			int ans=0;
			for(int j=1;j<=n;j++)
				ans=fmo(ans+1ll*fp(j,k)*fmo(s[j][r]-s[j][l-1])%P*sum(j,i)%P-P);
			for(int j=l;j<=r;j++)
				if(d[j]>=k)
					ans=fmo(ans+fmo(a[j])-P);
			printf("%d\n",ans);
		}
		else{
			int i,x;
			scanf("%d%d",&i,&x);
			if(a[i]<=0&&a[i]+x>0){
				a[i]+=x;
				getd();
			}
			else{
				if(a[i]<=0)
					a[i]+=x;
				else
					a[i]=fmo(a[i]+x-P);
				for(int j=1;j<=n;j++)
					add(j,p[i],1ll*x*val[i][j]%P);
			}
		}
	}
}