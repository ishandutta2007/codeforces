#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
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
int main(){
	while(1){
		cout<<"next 0 1"<<endl;
		int t=read();
		string s;
		for(int i=1;i<=t;i++)cin>>s;
		cout<<"next 1"<<endl;
		t=read();
		for(int i=1;i<=t;i++)cin>>s;
		if(t==2){
			while(1){
				cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
				int t=read();
				for(int i=1;i<=t;i++)cin>>s;
				if(t==1){
					puts("done"); return 0;
				}
			}
		}
	}
}
/*
*/