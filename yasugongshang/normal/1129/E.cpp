#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
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
const int N=505;
int fa[N],sz[N],q[N];
vector<int> lea,s;
bool cmp(int a,int b){
	return sz[a]<sz[b];
}
int get(vector<int> &s,vector<int> &t,int id){
	writeln(s.size());
	for(auto i:s)wri(i); puts("");
	writeln(t.size());
	for(auto i:t)wri(i); puts("");
	cout<<id<<endl; fflush(stdout);
	int jb=read();
	return jb;
}
void bao(int id,vector<int> v){
	if(v.size()==1){
		fa[v[0]]=id; 
		for(auto it=lea.begin();it!=lea.end();it++){
			if(*it==v[0]){
				lea.erase(it); return;
			}
		}
		return;
	}
	int mid=v.size()/2;
	vector<int> V=v;
	V.resize(mid);
	if(get(s,V,id))bao(id,V);
	V=v;
	V.erase(V.begin(),V.begin()+mid);
	if(get(s,V,id))bao(id,V); 
}
int main(){
	int n=read(); sz[1]=n;
	s.resize(1);
	vector<int> t(n-1),V;
	s[0]=1; for(int i=1;i<n;i++)t[i-1]=i+1;
	for(int i=1;i<=n;i++)q[i]=i;
	for(int i=2;i<=n;i++){
		sz[i]=get(s,t,i);
		if(sz[i]==1)lea.push_back(i);
		else V.push_back(i);
	}
	sort(V.begin(),V.end(),cmp);
	for(auto i:V){
		bao(i,lea);
		lea.push_back(i);
	}
	puts("ANSWER");
	for(int i=2;i<=n;i++){
		if(!fa[i])fa[i]=1; wri(fa[i]); writeln(i);
	}
}