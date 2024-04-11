#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=505,M=1<<16,mod=1e9+7;
const ll mod2=(ll)mod*mod;
int q[N],top,tot,zt[20],res[20],tj;
vector<int> son[N];
char ch[505],fh[N];

void re(poly &a){
	reverse(a.begin(),a.end());
}
void fwt(poly &a){
	For(i,0,15){
		For(j,0,M-1)if(j>>i&1)a[j]+=a[j^(1<<i)];
	}
}
void ufwt(poly &a){
	For(i,0,15){
		For(j,0,M-1)if(j>>i&1)a[j]-=a[j^(1<<i)];
	}
}
poly mer(poly A,poly B,char fh){
	if(fh=='&')re(A),re(B);
	fwt(A); fwt(B);
	For(i,0,M-1)A[i]=A[i]%mod*(B[i]%mod)%mod;
	ufwt(A);
	For(i,0,M-1)A[i]=(mod2+A[i])%mod;
	if(fh=='&')re(A);
	return A;
}
poly dfs(int p){
	if(son[p].size()){
		poly A=dfs(son[p][0]),B=dfs(son[p][1]);
		if(fh[p]=='?'){
			poly C=mer(A,B,'&'),D=mer(A,B,'|');
			For(i,0,M-1)C[i]=(C[i]+D[i])%mod;
			return C;
		}else{
			poly ans=mer(A,B,fh[p]); 
			return ans;
		}
	}else{
		poly ans(M);
		For(FH,'a','d')if(FH==fh[p]||fh[p]=='?'){
			int t=FH>='a'?FH-'a':FH-'A';
			int zt=0;
			For(i,0,15)zt|=((i>>t&1)^(FH>='a'))<<i;
			ans[zt]=1;
		}
		For(FH,'A','D')if(FH==fh[p]||fh[p]=='?'){
			int t=FH>='a'?FH-'a':FH-'A';
			int zt=0;
			For(i,0,15)zt|=((i>>t&1)^(FH>='a'))<<i;
			ans[zt]=1;
		}
		return ans;
	}
}
int main(){
	scanf("%s",ch);
	int n=strlen(ch); 
	q[top=1]=tot=1;
	For(i,0,n-1)if(ch[i]=='('){
		q[++top]=++tot;
	}else if(ch[i]==')'){
		son[q[top-1]].pb(q[top]); top--;
	}else{
		fh[q[top]]=ch[i];
	}
	poly ans=dfs(1);
	int m=read();
	For(i,1,m){
		For(j,0,3)zt[i]|=read()<<j;
		res[i]=read();
	}
	For(i,0,M-1){
		int f=1;
		for(int j=1;j<=m&&f;j++)if((i>>zt[j]&1)!=res[j])f=0;
		if(f)tj=(tj+ans[i])%mod;
	}
	cout<<tj<<endl;
}