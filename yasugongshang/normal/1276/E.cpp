#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<PI>
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
void GG(){
	puts("-1"); exit(0);
}
ll a[4],b[4],ta,tb;
int aa[2],bb[2];
poly dq,ans;
ll g;
void pp(ll *a){
	For(i,0,3)wri(a[i]); puts("");
}
void bao(ll &a,ll &b){
	if(a==b)return;
	dq.pb(mp(a,b));
	a=2*b-a;
}
void pr(poly &a){
	for(auto i:a){
		ans.pb(i);
	}
}
poly bao(ll *a){
	while(a[3]-a[0]>g){
		ll t=(a[3]-a[0]+3)/4;
		if(a[1]>=a[0]+t&&a[1]<=a[3]-t){
			if(a[1]-a[0]<a[3]-a[1])bao(a[0],a[1]); else bao(a[3],a[1]);
		}else if(a[2]>=a[0]+t&&a[2]<=a[3]-t){
			if(a[2]-a[0]<a[3]-a[2])bao(a[0],a[2]); else bao(a[3],a[2]);
		}else{
			if(a[1]-a[0]<a[3]-a[2]){
				if(a[3]-a[2]<a[2]-a[0]){bao(a[1],a[2]); bao(a[1],a[3]);}
				else{bao(a[1],a[0]); bao(a[1],a[2]);}
			}else{
				if(a[3]-a[1]<a[1]-a[0]){bao(a[2],a[3]); bao(a[2],a[1]);}
				else{bao(a[2],a[1]); bao(a[2],a[0]);}
			}
		}
		sort(a,a+4);
	}
	poly jj=dq;
	dq.clear();
	return jj;
}
void chu(poly &x){
	reverse(x.begin(),x.end());
	for(auto &i:x){
		i.fi=2*i.se-i.fi;
	}
}
void solve(ll *a,ll d,int id){
	d/=2;  if(!d)return;
	while(a[3]-a[0]<d){
		bao(a[2],a[0]); bao(a[1],a[3]);
		sort(a,a+4);
	}
	while(1){
		while(a[3]-a[0]<=d){
			d-=a[3]-a[0];
			For(i,0,2)bao(a[i],a[3]);
			sort(a,a+4);
			For(i,0,2)bao(a[i],a[3]);
			sort(a,a+4);
		}
		if(a[3]-a[0]==g)break;
		bao(a[0],a[1]); bao(a[3],a[2]);//pp(a); exit(0);
		sort(a,a+4);
	}
	if(id)chu(dq);
	pr(dq); 
	dq.clear();
}
int main(){
	For(i,0,3)a[i]=read();
	sort(a,a+4);
	For(i,0,3)b[i]=read();
	sort(b,b+4);
	For(i,1,3)ta=__gcd(ta,a[i]-a[0]);
	For(i,1,3)tb=__gcd(tb,b[i]-b[0]);
	if(ta!=tb)GG();
	if(!ta){
		if(a[0]!=b[0])GG(); else{ puts("0"); return 0;}
	}
	g=ta; 
	poly A=bao(a);
	pr(A);
	poly B=bao(b);
	sort(a,a+4); sort(b,b+4);
	
	if(g&&(b[0]-a[0])/g%2)For(j,0,2)if((a[j]/g+a[3]/g)%2){
		bao(a[j],a[3]);
	}
	pr(dq); dq.clear();
	sort(a,a+4);   
	if(b[0]>=a[0])solve(a,b[0]-a[0],0); else solve(b,a[0]-b[0],1);
	For(i,0,3)if(a[i]!=b[i])GG();
	chu(B);
	pr(B);
	cout<<ans.size()<<endl;
	for(auto i:ans){
		wri(i.fi); writeln(i.se);
	}
}