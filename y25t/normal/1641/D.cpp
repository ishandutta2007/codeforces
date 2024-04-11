#include<bits/stdc++.h>
#define ull unsigned long long
#define N 100005

std::mt19937_64 rng(58);

int n,m,w[N];

std::unordered_map<int,ull> A;
std::unordered_map<ull,int> B;
int tot,c[N][1<<5],f[N<<5],g[N<<5];

inline int cal(int x){
	int res=0;
	for(int i=0;i<(1<<m);i++)
		res+=(f[c[x][i]]-1)*g[c[x][i]];
	return res;
}

int p[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		std::vector<ull> a(m),b(1<<m);
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			if(!A.count(x))
				A[x]=rng();
			a[j]=A[x];
		}
		b[0]=0;
		for(int j=1;j<(1<<m);j++)
			b[j]=b[j^(j&-j)]^a[__builtin_ctz(j)];
		for(int j=0;j<(1<<m);j++){
			if(!B.count(b[j]))
				B[b[j]]=++tot,g[tot]=__builtin_parity(j)?-1:1;
			c[i][j]=B[b[j]];
			f[c[i][j]]++;
		}
		scanf("%d",&w[i]);
	}
	std::iota(p+1,p+n+1,1),std::sort(p+1,p+n+1,[&](int i,int j){
		return w[i]<w[j];
	});
	int ans=2e9+1;
	for(int l=1,r=n;l<r;l++){
		int o=r;
		while(r>l&&cal(p[l])){
			for(int i=0;i<(1<<m);i++)
				f[c[p[r]][i]]--;
			r--;
		}
		if(o!=r)
			ans=std::min(ans,w[p[l]]+w[p[r+1]]);
		for(int i=0;i<(1<<m);i++)
			f[c[p[l]][i]]--;
	}
	printf("%d\n",ans>2e9?-1:ans);
}