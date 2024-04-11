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
const int N=105;
int to[N<<1];
vector<string> A[N],B[N],C[N];
char ch[N];
void Read(vector<string> a[N],int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int cnt=(r-l+2)*(r-l+1)/2;
	For(i,1,cnt){
		string s;
		cin>>s;
		a[s.length()].pb(s);
	}
}
int main(){
	int n=read();
	if(n<=3){
		string ans,s;
		For(i,1,n){
			cout<<"? "<<i<<" "<<i<<endl;
			cin>>s;
			ans+=s;
		}
		cout<<"! "<<ans<<endl;
		return 0;
	}
	Read(A,1,n);
	int len=(n+1)/2; //len=n;
	Read(B,1,len);
	Read(C,1,len-1);
	For(i,1,len){
		string ans;
		int sum=0;
		for(auto j:B[i])for(auto k:j)sum^=k;
		for(auto j:C[i])for(auto k:j)sum^=k;
		For(j,len-i+2,len)sum^=ch[j];
		ch[len-i+1]=sum;
	}
	For(i,2,n-len+1){
		mem(to);
		for(auto j:A[i])for(auto k:j)to[k]++;
		for(auto j:B[i])for(auto k:j)to[k]--;
		Rep(j,len,len-i+2)to[ch[j]]-=i-(len-j+1);
		For(j,n-i+3,n)to[ch[j]]-=n-j+1;
		For(j,'a','z'){
			if(to[j]%i)ch[n-i+2]=j;
			to[j]=0;
		}
	}
	cout<<"! "<<ch+1<<endl;
}
/*
*/