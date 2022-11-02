#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define int long long
#define PI pair<ll,ll>
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
const ll inf=1e18;
const int N=1005;
PI ans[N];
ll L;
int n;
void hb(vector<int> &a,vector<int> &b){
	for(auto i:b)a.pb(i);
}
ll ask(int id,ll pos){
	putchar('?'); putchar(' '); wri(id); writeln(pos); fflush(stdout);
	return read();
}
ll get(int id,ll x,ll l,ll r){
	while(l<r){
		ll mid=(l+r)>>1;
		if(ask(id,mid)>=x)r=mid; else l=mid+1;
	}
	return l;
}
void solve(ll fl,ll fr,vector<int> v,int lll,int rrr){
	if(v.size()==1){ans[v[0]]=mp(fl,fr); return;}
	assert(v.size()==rrr-lll+1); 
	int dq; ll dd;
	int k=(v.size()+1)>>1;
	ll mid=(lll+rrr)/2*(L/n); 
	vector<int> LL,RR;
	ll gl=fl,gr=fr;
	while(1){
		vector<int> jb,jj,md;
		random_shuffle(v.begin(),v.end()); dq=v[v.size()-1]; v.pop_back(); dd=get(dq,mid,fl,fr); md.pb(dq);
		assert(k&&k<=v.size()+1);
		for(auto i:v){ll t=ask(i,dd); if(t==mid)md.pb(i); else if(t>mid)jb.pb(i); else jj.pb(i);}
		if(k>jb.size()&&k<=md.size()+jb.size()){
			hb(LL,jb); For(i,1,k-jb.size()){LL.pb(md.back()); md.pop_back();} hb(RR,md); hb(RR,jj); break;
		}else if(k<=jb.size()){
			hb(RR,md); hb(RR,jj); //for(auto i:jj)RR.pb(i);
			swap(v,jb); gr=dd;
		}else{
			hb(LL,md);hb(LL,jb); k-=md.size()+jb.size();
			swap(v,jj); gl=dd+1;//+1
		}
	}
	solve(fl,dd,LL,lll,(lll+rrr)/2);
	solve(dd,fr,RR,(lll+rrr)/2+1,rrr);
}
signed main(){
	n=read(); L=read();
	vector<int> v;
	For(i,1,n)v.pb(i);
	solve(0,inf,v,1,n);
	puts("!");
	For(i,1,n){wri(ans[i].fi); writeln(ans[i].se);}
	fflush(stdout); 
}