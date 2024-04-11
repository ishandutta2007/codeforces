#include<cstdio>
#include<vector>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=1005,P=998244353;
int n,m,a[N],f[N][N];std::vector<int>pos[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,m){
		rd(a[i]);
		if(a[i]==a[i-1]){--i,--m;continue;}
		if(i>2*n)return puts("0"),0;
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=m+1;++i)f[i][i-1]=1;
	for(int L=1;L<=m;++L){
		for(int i=1;i<=m+1-L;++i){
			int j=i+L-1,x=0x3f3f3f3f,L=0,R=0;
			for(int k=i;k<=j;++k)if(a[k]<x)x=a[k];
			if(pos[x][0]<i||pos[x].back()>j){f[i][j]=0;continue;}
			for(int k=i;k<=pos[x][0];++k)(L+=1ll*f[i][k-1]*f[k][pos[x][0]-1]%P)%=P;
			for(int k=pos[x].back();k<=j;++k)(R+=1ll*f[pos[x].back()+1][k]*f[k+1][j]%P)%=P;
			f[i][j]=1ll*L*R%P;
			for(int k=0;k<(int)pos[x].size()-1;++k){
				f[i][j]=1ll*f[i][j]*f[pos[x][k]+1][pos[x][k+1]-1]%P;
			}
		}
	}
	pt(f[1][m],'\n');
	return 0;
}