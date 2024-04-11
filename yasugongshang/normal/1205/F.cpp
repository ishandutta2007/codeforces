#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=105;
int zy[N][N*N/2];
bool dp[N][N*N/2];
deque<int> ans;
int id;
void dfs(int n,int k){
	if(n==1){
		ans.push_back(1); return;
	}else{
		if(zy[n][k]>0){
			dfs(n-zy[n][k]+1,k-zy[n][k]);
			int sz=ans.size();
			if(zy[n][k]&1){
				ans.push_front(zy[n][k]/2+sz);
				for(int i=1;i<zy[n][k]/2-1;i++){ans.push_back(sz+zy[n][k]/2+i);ans.push_back(sz+i); }
				ans.push_back(sz+zy[n][k]-1);
				ans.push_back(sz+zy[n][k]/2-1);
				ans.push_back(sz+zy[n][k]-2);
			}else{
				ans.push_front(zy[n][k]/2+sz);
				for(int i=1;i<zy[n][k]/2;i++){ans.push_back(sz+zy[n][k]/2+i);ans.push_back(sz+i); }
			}
		}else{
			dfs(n+zy[n][k]+1,k+zy[n][k]*(1-zy[n][k])/2+1);
			int sz=ans.size();
			if(id){
				For(i,1,-zy[n][k]-1)ans.push_back(sz+i);
			}else{
				For(i,1,-zy[n][k]-1)ans.push_front(sz+i);
			}
			id^=1;
		}
	}
}
int main(){
	dp[1][1]=1;
	For(i,2,100){
		For(j,i,i*(i+1)/2){
			For(k,2,i){
				if(k*(k+1)/2<=j&&dp[i-k+1][j-k*(k+1)/2+1]){
					dp[i][j]=1; zy[i][j]=-k; break;
				}
				if(k>=4&&dp[i-k+1][j-k]){
					dp[i][j]=1; zy[i][j]=k; break;
				}
			}
		}
	}
	int q=read();
	while(q--){
		int n=read(),k=read();
		if(!dp[n][k]){puts("NO");}
		else{
			id=1;
			dfs(n,k);
			puts("YES");
			while(ans.size()){
				wri(ans.front()); ans.pop_front();
			}puts("");
		}
	}
}