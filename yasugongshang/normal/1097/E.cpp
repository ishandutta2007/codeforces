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
const int N=100005;
int n,a[N],vis[N],f[N],c[N];
#define lowbit(i) i&-i
void change(int pos,int de){
	for(int i=pos;i<=n;i+=lowbit(i))c[i]=max(c[i],de);
}
int ask(int pos){
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))ans=max(ans,c[i]);
	return ans;
}
vector<int> get(){
	int ans=0,dq=1e9;
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<=n;i++)if(!vis[i]){
		f[i]=ask(a[i])+1;
		change(a[i],f[i]);
		ans=max(ans,f[i]); 
	}
	vector<int> an;
	for(int i=n;i;i--)if(!vis[i]&&a[i]<dq&&f[i]==ans){
		ans--; an.push_back(i); dq=a[i];
	}
	reverse(an.begin(),an.end());
	return an;
}
int lim[N];
vector<vector<int> > alb;
void bao(){
	vector<vector<int> > v;
	for(int i=1;i<=n;i++)if(!vis[i]){
		int flag=0;
		for(auto &j:v)if(a[j[j.size()-1]]>a[i]){
			//cout<<j[j.size()-1]<<" "<<a[i]<<endl;
			j.push_back(i); flag=1; break;
		}
		if(!flag){
			vector<int> dd(1); dd[0]=i;
			v.push_back(dd);
		}
	}
	for(auto i:v)alb.push_back(i);
}
int main(){
	int T=read();
	for(int i=1;i<N;i++){
		lim[i]=lim[i-1]; while(lim[i]*(lim[i]+1)/2<i)lim[i]++;
	}
	while(T--){
		alb.clear();
		int nn=n=read();
		for(int i=1;i<=n;i++){a[i]=read(); vis[i]=0;}
		while(1){
			vector<int> x=get(); 
			if(!x.size())break;
			if((int)x.size()<lim[nn]){bao(); break;}
			nn-=x.size();
			alb.push_back(x);
			for(auto i:x){ vis[i]=1;}
		}
		writeln(alb.size()); //assert((ll)alb.size()*((ll)alb.size()+1)<=(ll)2*n);
		for(auto i:alb){
			wri(i.size());
			for(auto j:i)wri(a[j]); puts("");
		}
	}
}
/*
1
14
9 7 10 4 12 8 6 14 1 2 13 3 11 5 

*/