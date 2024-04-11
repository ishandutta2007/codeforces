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
const int N=30;
ll sum[N];
int s;
struct heap{
	priority_queue<int,vector<int>,greater<int> > add,del;
	void push(int x){
		add.push(x);
	}
	void erase(int x){
		del.push(x);
	}
	int top(){
		while(add.size()&&del.size()&&add.top()==del.top()){
			add.pop(); del.pop();
		}
		return add.size()?add.top():0;
	}
}q[30];
void ins(int id,int x){
	sum[id]+=x; s++; q[id].push(x);
}
void era(int id,int x){
	sum[id]-=x; s--; q[id].erase(x);
}
int get(){
	ll dq=0;
	int ans=s;
	for(int i=0;i<30;i++){
		if(q[i].top()>dq*2)ans--;
		dq+=sum[i]; 
	}
	return ans;
}
char ch[5];
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		int x=read();
		if(ch[0]=='+')ins(log2(x),x);
		else era(log2(x),x);
		writeln(get());
	}
}