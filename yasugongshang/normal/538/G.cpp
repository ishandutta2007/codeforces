#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
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
const int N=200005,NN=2000005;
char ans[NN];
int n,l,s[NN],res[NN];
ll A[N],t[N],X[N],Y[N];
vector<PI> v[NN];
void GG(){
	puts("NO"); exit(0);
}
void solve(){
	static bool vis[2]; mem(vis);
	For(i,1,n)vis[(t[i]+A[i])&1]=1;
	if(vis[1])GG();
	For(i,0,l)v[i].clear();
	For(i,1,n){
		v[t[i]%l].pb(mp(A[i],t[i]/l));
	}
	ll L=-l,R=l;
	ll pos=0,lst=0,bl=0;
	v[l].pb(mp(0,-1));
	For(i,0,l){
		for(auto j:v[i]){
			while(L<=R&&abs((j.fi-L*j.se)-(lst-L*bl))>i-pos)L+=2;
			while(L<=R&&abs((j.fi-R*j.se)-(lst-R*bl))>i-pos)R-=2;
			pos=i; lst=j.fi; bl=j.se;
		}
	}
	if(L>R)GG(); //cout<<L<<" "<<R<<endl; exit(0);
	s[0]=0; int dq=0,ss=0;
	For(i,0,l)if(v[i].size()){
		s[i]=v[i][0].fi-v[i][0].se*L; //writeln(s[i]);
		while(dq<i){
			if(s[dq]<s[i])s[++dq]=++ss; else s[++dq]=--ss;
		}
	}
	//For(i,0,l)wri(s[i]); puts(""); cout<<L<<" "<<R<<endl;
	assert(s[l]==L); For(i,1,l)assert(abs(s[i]-s[i-1])==1);
	For(i,0,l)for(auto j:v[i])assert(s[i]+s[l]*j.se==j.fi);
}//x*T+
int main(){
	n=read(),l=read();
	For(i,1,n){
		t[i]=read(); ll x=read(),y=read();
		X[i]=x-y; Y[i]=x+y;
	}
	For(i,1,n)A[i]=X[i];
	solve();
	For(i,1,n)A[i]=Y[i];
	For(i,1,l){res[i]=s[i]-s[i-1];}
	solve();
	For(i,1,l)if(res[i]==1&&s[i]-s[i-1]==1)ans[i]='R';
	else if(res[i]==1)ans[i]='D';
	else if(s[i]-s[i-1]==1)ans[i]='U';
	else ans[i]='L';
	cout<<(ans+1)<<endl;
}
/*
56 100

1 0 1

2 -1 1

3 0 1

4 0 2

5 0 1

6 0 2

7 -1 2

8 -2 2

9 -2 3

10 -3 3

11 -4 3

12 -5 3

13 -5 4

14 -5 5

15 -4 5

16 -3 5

17 -3 6

18 -4 6

19 -4 5

20 -3 5

21 -3 4

22 -2 4

23 -3 4

24 -4 4

25 -3 4

26 -4 4

27 -4 3

28 -4 2

29 -4 3

30 -4 4

31 -4 5

32 -3 5

33 -3 4

34 -2 4

35 -1 4

36 -1 3

37 -1 2

38 -1 1

39 0 1

40 0 0

41 -1 0

42 -1 -1

43 -1 0

44 0 0

45 1 0

46 1 -1

47 1 0

48 2 0

49 1 0

50 0 0

51 -1 0

52 -1 -1

53 -2 -1

54 -2 0

55 -1 0

56 0 0

*/