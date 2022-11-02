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
const int N=4005;
vector<int> ans,S,T;
int n,to[4];
char s[N],t[N];
vector<int> get(char ch[]){
	vector<int> v(n);
	For(i,0,n-1)v[i]=(ch[2*i]-'0')<<1|(ch[2*i+1]-'0');
	return v;
}
void work(int pos){
	if(pos<0)return;
	ans.pb(pos*2+2);
	reverse(S.begin(),S.begin()+pos+1);
	For(i,0,pos)if(S[i]==1||S[i]==2)S[i]^=3;
}
int main(){
	int Te=read();
	while(Te--){
		scanf("%s%s",s,t);
		n=strlen(s)/2;
		S=get(s); T=get(t);
		for(auto &i:T)if(i==1||i==2)i^=3;
		memset(to,0,sizeof(to));
		for(auto i:S)to[i]++;
		for(auto i:T)to[i]--;
		if(to[0]||to[3]){
			puts("-1"); continue;
		}
		ans.clear();
		int bef=-1,aft=-1,zs=0;
		For(i,0,n-1){
			if(S[i]==2)zs++; else if(S[i]==1)zs--;
			if(to[1]+zs==0&&to[1]){
				to[1]+=zs; zs=0; bef=i;
			}
		}
		zs=0;
		For(i,0,n-1){
			if(T[i]==1)zs++; else if(T[i]==2)zs--;
			if(to[1]+zs==0&&to[1]){
				to[1]+=zs; zs=0; aft=i;
			}
		}
		reverse(T.begin(),T.begin()+aft+1);
		For(i,0,aft)if(T[i]==1||T[i]==2)T[i]^=3;
		//cout<<bef<<" "<<aft<<" "<<to[1]<<endl;
		work(bef);
		//for(auto i:S)wri(i); puts("SSS"); for(auto i:T)wri(i); puts("TTT");
		Rep(i,n-1,0){
			int pos;
			For(j,n-i-1,n-1)if(T[i]==S[j]){pos=j; break;}
			//cout<<pos<<endl;
			work(pos-1); 
			work(pos);
		}
		work(aft); 
		writeln(ans.size());
		for(auto i:ans)wri(i); puts(""); 
	}
}
/*

4
0100011011
1101011000
10101010
10101010
0011
1001
100011
110010

1
10101010
10101010

*/