#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
const int N=100005;
int n,ti,tong[N],sum[N],f[N][26],g[N][26],l[N][26],r[N][26];
vector<int> s[26];
vector<int> v[N];
map<int,int> M[N];
char ch[N];
int solve(int L,int R){
	if(L>R)return 0;
	if(M[L].count(R))return M[L][R];
	ti++;
	for(int i=0;i<26;i++)if(r[L][i]<=R){
		//if(L==1&&R==3)cout<<i<<" "<<g[4][0]<<" "<<f[L][i]<<" "<<g[R][i]<<" "<<sum[l[R][i]]<<" "<<sum[r[L][i]]<<endl;
		tong[f[L][i]^g[R][i]^sum[l[R][i]]^sum[r[L][i]]]=ti;
	}//if(L==1&&R==4)cout<<ti<<" "<<tong[0]<<endl;
	for(int i=0;;i++)if(tong[i]!=ti)return M[L][R]=i;
}
signed main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;i++)ch[i]-='a'; for(int i=0;i<26;i++)s[i].push_back(0);
	for(int i=1;i<=n;i++)s[ch[i]].push_back(i);
	for(int i=0;i<26;i++)s[i].push_back(n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)l[i][j]=l[i-1][j];
		l[i][ch[i]]=i;
	}
	for(int i=0;i<26;i++)r[n+1][i]=n+1;
	for(int i=n;i;i--){
		for(int j=0;j<26;j++)r[i][j]=r[i+1][j];
		r[i][ch[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)if(ch[i]!=j){
			v[i].push_back(l[i][j]+1);
			v[r[i][j]-1].push_back(i);
		}
	}
	for(int i=0;i<26;i++)for(unsigned j=1;j<s[i].size();j++)v[s[i][j]-1].push_back(s[i][j-1]+1);
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end()); v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin()); reverse(v[i].begin(),v[i].end()); 
		for(auto j:v[i]){
			solve(j,i);
			for(int k=0;k<26;k++)if(l[i][k]+1==j)g[i][k]=solve(j,i);
			if(r[j][ch[i+1]]==i+1)f[j][ch[i+1]]=solve(j,i);
		}
		sum[i+1]=sum[l[i][ch[i+1]]]^solve(l[i][ch[i+1]]+1,i);
		//for(int j=0;j<26;j++)f[l[i][j]][j]=solve(l[i][j]+1,i);
	}
	//cout<<solve(1,3)<<" "<<f[1][1]<<" "<<sum[3]<<" zy "<<sum[1]<<endl;
	int m=read();
	while(m--){
		int L=read(),R=read();
		puts(solve(L,R)?"Alice":"Bob");
	}
}