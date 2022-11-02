#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int N=250005;
int leaf[N],vis[N],dep[N],fa[N];
vector<int> v[N];
void dfs(int p){
	vis[p]=1; dep[p]=dep[fa[p]]+1;
	for(auto i:v[p])if(!vis[i]){leaf[p]=1; fa[i]=p;dfs(i);}
}
void print(int x,int y){
	writeln(dep[x]-dep[y]+1);
	for(;;x=fa[x]){
		wri(x);
		if(x==y)break;
	}
	puts("");
}
signed main(){
	int n=read(),m=read(),k=read();
	while(m--){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1);
	for(int i=1;i<=n;i++)if((ll)dep[i]*k>=n){
		puts("PATH");
		print(i,1); return 0;
	}
	puts("CYCLES"); int tot=0;
	for(int i=1;i<=n;i++)if(leaf[i]==0){
		int q[4]; q[0]=0;
		for(auto j:v[i])if(j!=fa[i])q[++*q]=j;
		if((dep[i]-dep[q[1]]+1)%3)print(i,q[1]);
		else if((dep[i]-dep[q[2]]+1)%3)print(i,q[2]);
		else {
			if(dep[q[1]]<dep[q[2]])swap(q[1],q[2]);
			writeln(dep[q[1]]-dep[q[2]]+2);
			wri(i);
			for(int i=q[1];;i=fa[i]){
				wri(i);
				if(i==q[2])break;
			}
		}
		tot++; if(tot==k)return 0;
	}
}