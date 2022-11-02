#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld double
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
int n,m,c[N];
ld k[N],b[N],x,y;
#define lowbit(i) i&-i
inline void change(int pos,int de){
	for(int i=pos;i<N;i+=lowbit(i))c[i]+=de;
}
inline int ask(int pos){
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))ans+=c[i];
	return ans;
}
pair<ld,ld> q[N];
pair<ld,pair<ld,int> > Q[N];
set<pair<ld,int> > s;
ld qq[N];
/*
(X-x)*(X-x)+(kX+b-y)*(kX+b-y)-r*r=0
X*X+x*x-2xX+k*k*X*X+b*b-y*y+2bkX-2kyX+b*b+y*y-2by-r*r=0
*/
int check(ld r){
	int tot=0,tt=0;
	for(int i=1;i<=n;i++){
		ld A=1+k[i]*k[i],B=2*(b[i]*k[i]-x-y*k[i]),C=x*x+(b[i]-y)*(b[i]-y)-r*r;
		ld delta=B*B-4*A*C;
		if(delta>0){
			ld X1=(-B+sqrt(delta))/2/A,X2=(-B-sqrt(delta))/2/A;
			ld Y1=k[i]*X1+b[i],Y2=k[i]*X2+b[i];
			X1-=x; X2-=x; Y1-=y; Y2-=y;
			ld L=atan2(Y1,X1),R=atan2(Y2,X2);
			if(L>R)swap(L,R);
			//cout<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<<" "<<L<<" "<<R<<endl;
			q[++tot]=mp(R,L);
			qq[++tt]=L; qq[++tt]=R;
		}
	}
	sort(&qq[1],&qq[tt+1]); 
	sort(&q[1],&q[tot+1]);
	memset(c,0,sizeof(c));
	int ans=0;
	for(int i=1;i<=tot;i++){
		int L=lower_bound(&qq[1],&qq[tt+1],q[i].first)-qq,R=lower_bound(&qq[1],&qq[tt+1],q[i].second)-qq;
		ans+=ask(R)-ask(L);
		change(L,-1); change(R,1);
	}
	return ans;
}
ld insert(int A,int B){
	ld X=(b[A]-b[B])/(k[B]-k[A]),Y=k[A]*X+b[A]; 
	return sqrt(sqr(X-x)+sqr(Y-y));
}
/*x*k[A]+b[A]=x*k[B]+y[b]*/
pair<ld,ld> sol(ld r){
	int tot=0;
	for(int i=1;i<=n;i++){
		ld A=1+k[i]*k[i],B=2*(b[i]*k[i]-x-y*k[i]),C=x*x+(b[i]-y)*(b[i]-y)-r*r;
		ld delta=B*B-4*A*C;
		if(delta>0){
			ld X1=(-B+sqrt(delta))/2/A,X2=(-B-sqrt(delta))/2/A;
			ld Y1=k[i]*X1+b[i],Y2=k[i]*X2+b[i];
			X1-=x; X2-=x; Y1-=y; Y2-=y;
			//cout<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<<endl;
			ld L=atan2(Y1,X1),R=atan2(Y2,X2);
			if(L>R)swap(L,R);
			Q[++tot]=mp(R,mp(L,i));
		}
	}
	sort(&Q[1],&Q[tot+1]);
	ld ans=0,sum=0;
	s.clear();
	for(int i=tot;i;i--){
		ld L=Q[i].second.first,R=Q[i].first;
		for(auto it=s.lower_bound(mp(L,0));it!=s.end()&&(*it).first<=R;it++){
			//cout<<Q[i].second.second<<" wzp "<<(*it).second<<endl;
			ans+=insert(Q[i].second.second,(*it).second); sum=sum+1;
		}
		s.insert(mp(L,Q[i].second.second));
	}
	return mp(ans,sum);
}

int main(){
	n=read();
	x=(ld)read()/1000; y=(ld)read()/1000; m=read();
	for(int i=1;i<=n;i++){
		k[i]=(ld)read()/1000; b[i]=(ld)read()/1000;
	}
	ld l=0,r=4e9;
	//cout<<check(6.001)<<endl; return 0;
	for(int i=1;i<=60;i++){
		ld mid=(l+r)/2;
		if(check(mid)>=m)r=mid; else l=mid;
	}
	//cout<<l<<" "<<r<<" "<<check(r)<<" "<<sol(l)<<endl;
	pair<ld,ld> t=sol(l);
	printf("%.8lf\n",(double)(t.first+(m-t.second)*l));
}