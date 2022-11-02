#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
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
const int N=300005,B=500;
vector<int> v[N],V[N];
int tong[N];
int main(){
	int T=read();
	while(T--){
		int n=read(),q=read();
		for(int i=1;i<=n;i++)V[i].clear();
		for(int i=1;i<=q;i++){
			v[i].resize(read()); for(auto &j:v[i])j=read();
			if(v[i].size()<=B){
				for(auto j:v[i])V[j].push_back(i);
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)tong[i]=0;
		for(int i=1;i<=n&&ans;i++){
			for(auto j:V[i]){
				int flag=0;
				for(unsigned l=0;l<v[j].size();l++)if(flag){
					if(tong[v[j][l]]){
						if(tong[v[j][l]]!=v[j][flag])ans=0;
					}else tong[v[j][l]]=v[j][flag];
				}else if(v[j][l]==i)flag=l+1;
			}
			for(auto j:V[i])for(auto k:v[j])tong[k]=0;
		}
		for(int i=1;i<=n;i++)tong[i]=-1;
		for(int i=1;i<=q&&ans;i++)if(v[i].size()>B){
			for(unsigned j=0;j<v[i].size();j++)tong[v[i][j]]=j;
			for(int j=1;j<=q;j++)if(v[j].size()<=B||j>i){
				int mx=0;
				for(int k=v[j].size()-1;k>=0;k--)if(tong[v[j][k]]>=0){
					if(tong[v[j][k]]<mx){
						if(v[i][tong[v[j][k]]+1]!=v[j][k+1])ans=0;
					}else mx=tong[v[j][k]];
				}
			}
			for(auto j:v[i])tong[j]=-1;
		}
		if(ans)puts("Robot"); else puts("Human");
	}
}
/*
1
5
4
2 2 3
2 2 3
2 5 3
2 2 3

*/