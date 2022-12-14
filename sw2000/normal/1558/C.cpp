#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
char gc(void){
    const int S=3e7;
    static char buf[S],*s=buf,*t=buf;
    if (s==t) t=buf+fread(s=buf,1,S,stdin);
    if (s==t) return EOF;
    return *s++;
}
void read(char &c){while(c=gc(),c==' '||c=='\n');}
void read(string &s){
    char c;
    while(c=gc(),c!=' '&&c!='\n'&&c!=EOF)s+=c;
}
void read(char *s){
    char c;
    while(c=gc(),c!=' '&&c!='\n'&&c!=EOF)*s=c,s++;
}
template<class T>void read(T&ret) {
	char c;
	if(c=gc(),c==EOF)return;
	while(c!='-'&&c!='.'&&(c<'0'||c>'9'))c=gc();
	int sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=gc(),c>='0'&&c<='9')ret=ret*10+(c-'0');
	if(c==' '||c=='\n') {
		ret*=sgn;
		return;
	}
	T bit=0.1;
	while(c=gc(),c>='0'&&c<='9')ret+=(c-'0')*bit,bit/=10;
	ret*=sgn;
}
void I(){};
template<class T,class... A>void I(T &a,A&... x){read(a);I(x...);}
void write(char x){putchar(x);}
void write(string x){cout<<x;}
void write(const char *x){printf(x);}
void write(double x){printf("%.10lf",x);}
void write(long double x){printf("%.10Lf",x);}
template<class T>void write(T x) {
    if(x<0)putchar('-'),x*=-1;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void O(){};
template<class T,class... A>void O(T a,A... x){write(a);O(x...);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#define K(a...)
#endif
typedef __int128_t il;
typedef unsigned long long ul;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<int>vl;
const double PI=acos(-1);
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=2030+10;
const int mod=998244353;

int n,ar[N];
void solve(){
    I(n);
    for(int i=1;i<=n;i++)I(ar[i]);
    for(int i=1;i<=n;i++){
        if(ar[i]%2!=i%2){
            O(-1);
            return;
        }
    }
    vi v;
    for(int i=n;i>=3;i-=2){
        int p=1;
        while(ar[p]!=i)p+=2;
        v.push_back(p);
        reverse(ar+1,ar+1+p);

        p=2;
        while(ar[p]!=i-1)p+=2;
        p--;
        v.push_back(p);
        reverse(ar+1,ar+1+p);

        p+=2;
        v.push_back(p);
        reverse(ar+1,ar+1+p);

        p=3;
        v.push_back(p);
        reverse(ar+1,ar+1+p);

        p=i;
        v.push_back(p);
        reverse(ar+1,ar+1+p);
    }
    for(int i=1;i<=n;i++)K(ar[i]);

    O(v.size(),'\n');
    for(auto i:v)O(i,' ');
}
int main() {
    freopen("A.in","r",stdin);
    int _;I(_);
    while(_--){
        solve();
        O('\n');
    }
}