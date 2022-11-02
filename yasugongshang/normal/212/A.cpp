#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI pair<int,int>
#define ld long double
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=4005;
int n1,n2,m,k,a[5005],b[5005],d[N],e[N];
int mat1[N*2][N],mat2[N*2][N],lx,ly;
void dfs(int p){
	if(!mat2[p][ly])return;
	int t=mat2[p][ly];
	swap(mat1[t][lx],mat1[t][ly]);
	if(!mat1[t][lx])return;
	swap(mat2[mat1[t][lx]][lx],mat2[mat1[t][lx]][ly]);
	dfs(mat1[t][lx]);
}
map<int,int> M[N*2];
signed main(){
	n1=read(); n2=read(); m=read(); k=read();
	for(int i=1;i<=m;i++){
		a[i]=read(); b[i]=read();
		d[a[i]]++; e[b[i]]++; 
	}
	int ans=0;
	for(int i=1;i<=n1;i++)ans+=d[i]%k!=0; for(int i=1;i<=n2;i++)ans+=e[i]%k!=0;
	int jb=n1;
	for(int i=1;i<=n1;i++){
		int dq=i,cnt=0;
		for(int j=1;j<=m;j++)if(a[j]==i){
			a[j]=dq;
			cnt++; if(cnt%k==0)dq=++jb;
		}
	}
	n1=jb;
	jb=n2;
	for(int i=1;i<=n2;i++){
		int dq=i,cnt=0;
		for(int j=1;j<=m;j++)if(b[j]==i){
			b[j]=dq;
			cnt++; if(cnt%k==0)dq=++jb;
		}
	}
	n2=jb; 
	for(int i=1;i<=m;i++){//cout<<a[i]<<" wzp "<<b[i]<<endl;
		for(int j=1;j<=k;j++)if(!mat1[a[i]][j]){lx=j; break;}
		for(int j=1;j<=k;j++)if(!mat2[b[i]][j]){ly=j; break;}
		if(lx==ly){mat1[a[i]][lx]=b[i]; mat2[b[i]][ly]=a[i]; continue;}
		mat1[a[i]][lx]=b[i]; mat2[b[i]][ly]=mat2[b[i]][lx]; mat2[b[i]][lx]=a[i];
		//for(int j=1;j<=n1;j++)for(int l=1;l<=k;l++)cout<<mat1[j][l]<<" "; puts("zhu");
		dfs(b[i]);
	}
	//for(int j=1;j<=n1;j++)for(int i=1;i<=k;i++)cout<<mat1[i][j]<<" ";
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=k;j++){
			M[i][mat1[i][j]]=j;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)wri(M[a[i]][b[i]]);
}