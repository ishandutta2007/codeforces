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
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=32,P=50000;
int n,p,lst[N+1][N][P],b[N],c[N],a[100005];
bool dp[N+1][N][P];
vector<int> ans;
void gao(int n,int i,int j){
	//cout<<n<<" "<<i<<" "<<j<<endl;
	if(n==0)return;
	if(dp[n-1][i][j])gao(n-1,i,j); else{
		ans.push_back(c[n-1]);
		gao(n-1,i^b[n-1],lst[n][i][j]);
	}
}
int main(){
	n=read(); p=read();
	if(n==1){
		puts("No"); return 0;
	}
	for(int i=1;i<=n;i++)a[i]=read(); int tot=-1;
	for(int i=1;i<=n;i++)if(a[i]<=31){b[++tot]=a[i]; c[tot]=i;}
	dp[0][0][0]=1;
	for(int i=0;i<=tot;i++){
		if(i==1)dp[i][0][0]=0;
		for(int j=0;j<32;j++){
			for(int k=0;k<p;k++)if(dp[i][j][k]){
				dp[i+1][j][k]=1; lst[i+1][j][k]=k;
				dp[i+1][j^b[i]][(k*(b[i]<10?10:100)+b[i])%p]=1;
				lst[i+1][j^b[i]][(k*(b[i]<10?10:100)+b[i])%p]=k;
			}
		}
	}
	if(dp[tot+1][0][0]){
		puts("Yes");
		gao(tot+1,0,0);
		cout<<ans.size()<<endl; reverse(ans.begin(),ans.end());
		for(unsigned i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	}else{
		puts("No");
	}
}
/*
42 53 54 55 101 101 102
*/