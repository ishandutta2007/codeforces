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
const int N=400005,B=500;
int c[N],ans,n,k,ddd,a[N],b[N];
char ch[5];
struct data{
	int to[1<<14|2];
	inline int& operator [](int x){
		return to[x];
	}
};
vector<data> to[N];
vector<int> v[N],V[N];
void change(int pos,int de){
	int id=pos%k;
	if((v[id][0]^V[id][0])&&id!=k-1)ddd--;
	pos/=k; int be=pos/B,x=V[id][be],meiju=pos/B*B;
	for(int i=pos;i>=meiju;i--){
		if(v[id][i]==x)ans++;
		if(be<to[id].size())to[id][be][v[id][i]]--; v[id][i]^=de;
		if(be<to[id].size())to[id][be][v[id][i]]++;
		if(v[id][i]==x)ans--;
	}
	for(int i=be-1;i>=0;i--){
		ans+=to[id][i][V[id][i]]; V[id][i]^=de; ans-=to[id][i][V[id][i]];
	}
	if((v[id][0]^V[id][0])&&id!=k-1)ddd++;
}
void build(int id){
	int x=n/k+(id<n%k)-1;
	for(int j=id;j<n;j+=k)v[id][j/k]=c[j];
	for(int i=x;i>=0;i--){
		v[id][i]^=v[id][i+1]; if(v[id][i]==0)ans--;
		if(i/B<to[id].size())to[id][i/B][v[id][i]]++;
	}
	if(v[id][0]&&id!=k-1)ddd++;
}
void pr(){
	writeln(ddd?-1:ans);
}
int main(){
	ans=n=read(); k=read(); int Tq=read();
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<n;i++)b[i]=read();
	for(int i=n-1;i>=0;i--)c[i]=a[i]^b[i]^a[i+1]^b[i+1];
	for(int i=0;i<k;i++){v[i].resize(n/k+3); V[i].resize((n/k/B)+3); to[i].resize(v[i].size()/B); build(i);}
	pr();
	while(Tq--){
		scanf("%s",ch);
		int p=read()-1,v=read();
		if(ch[0]=='a'){
			change(p,v^a[p]); if(p)change(p-1,v^a[p]); a[p]=v;
		}else{
			change(p,v^b[p]); if(p)change(p-1,v^b[p]); b[p]=v;
		}
		pr();
	}
}
/*
3 3 0
0 4 2
1 5 3

*/