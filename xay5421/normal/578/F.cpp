#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define EB emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=205;
int n,m,P,fa[N*N],tp[N*N],bel[N*N],G[2][666][666],cnt[2];
char s[N][N];
int zip(int k1,int k2){
	return k1*(m+1)+k2;
}
void ae(int(*g)[666],int k1,int k2){
	++g[k1][k1],++g[k2][k2],--g[k1][k2],--g[k2][k1];
}
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int det(int(*g)[666],int n){
	int res=1,f=0;
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j)
			if(g[j][i]){
				if(i!=j)f^=1;
				swap(g[i],g[j]);
				break;
			}
		if(!g[i][i])return 0;
		res=1LL*res*g[i][i]%P;
		for(int j=i+1;j<n;++j){
			int num=1LL*g[j][i]*fpow(g[i][i],P-2)%P;
			for(int k=0;k<n;++k){
				g[j][k]=(g[j][k]+P-1LL*g[i][k]*num%P)%P;
			}
		}
	}
	return f?P-res:res;
}
int main(){
	scanf("%d%d%d",&n,&m,&P);
	rep(i,0,n)rep(j,0,m)fa[zip(i,j)]=zip(i,j),tp[zip(i,j)]=(i+j)&1;
	rep(i,1,n)scanf("%s",s[i]+1);
	vector<pair<int,int> >e;
	rep(i,1,n){
		rep(j,1,m){
			if(s[i][j]=='/'){
				fa[fd(zip(i-1,j))]=fd(zip(i,j-1));
			}
			if(s[i][j]=='\\'){
				fa[fd(zip(i-1,j-1))]=fd(zip(i,j));
			}
			if(s[i][j]=='*'){
				e.EB(zip(i-1,j),zip(i,j-1));
				e.EB(zip(i-1,j-1),zip(i,j));
			}
		}
	}
	rep(i,0,n)rep(j,0,m)if(fd(zip(i,j))==zip(i,j))bel[zip(i,j)]=cnt[tp[zip(i,j)]]++;
	rep(i,0,n)rep(j,0,m)bel[zip(i,j)]=bel[fd(zip(i,j))];
	for(auto x:e){
		int k1,k2;
		tie(k1,k2)=x;
		D("%d %d(%d,%d) %d(%d,%d)\n",tp[k1],bel[k1],k1/(m+1),k1%(m+1),bel[k2],k2/(m+1),k2%(m+1));
		ae(G[tp[k1]],bel[k1],bel[k2]);
	}
	printf("%d\n",(det(G[0],cnt[0]-1)+det(G[1],cnt[1]-1))%P);
	return 0;
}