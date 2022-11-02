#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
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
const int N=100005;
vector<int> v[N],to[4];
stack<int> q[2];
char s[N];
int tot;
void mer(int a,int b){
	for(auto i:v[b])v[a].pb(i); v[b].clear();
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n)s[i]=s[i]=='R';
	For(i,1,n)if(q[s[i]^1].size()){
		int t=q[s[i]^1].top();
		v[t].pb(i);
		q[s[i]].push(t); q[s[i]^1].pop();
	}else{
		q[s[i]].push(++tot);
		v[tot].pb(i);
	}
	writeln(tot-1);
	For(i,1,tot){
		to[s[v[i][0]]*2+s[v[i].back()]].pb(i);
	}
	while(to[0].size()&&to[3].size()){
		mer(to[0].back(),to[3].back());
		to[1].pb(to[0].back());
		to[0].pop_back(); to[3].pop_back();
	}
	For(o,1,2){
		if(to[o].size()){
			For(i,1,to[o].size()-1){
				mer(to[o][0],to[o][i]);
			}
			to[o].resize(1);
		}
	}
	if(to[1].size()&&to[2].size()){
		if(v[to[1][0]].back()<v[to[2][0]].back()){
			v[to[1][0]].pb(v[to[2][0]].back()); v[to[2][0]].pop_back();
			mer(to[1][0],to[2][0]);
			to[2].pop_back();
		}else{
			v[to[2][0]].pb(v[to[1][0]].back()); v[to[1][0]].pop_back();
			mer(to[2][0],to[1][0]); 
			to[1].pop_back();
		}
	}
	for(int i=0;i<=3;i+=3)For(j,1,2)if(to[i].size()&&to[j].size()){
		if((i&1)==(j&1))mer(to[i][0],to[j][0]);else mer(to[j][0],to[i][0]);
	}
	For(i,1,tot)if(v[i].size()){
		for(auto j:v[i])wri(j); 
	}
}