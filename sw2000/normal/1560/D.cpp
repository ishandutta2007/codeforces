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
#define mid (l+r>>1)
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
const int N=2e5+10;
const int Q=998244353;

vector<pair<string,int>>v;
int solve(){
    string s;I(s);
    int ret=s.size()+1;
    for(auto i:v){
        int j=0;
        for(auto k:s){
            if(k==i.fi[j])j++;
            if(j==i.fi.size()){
                Min(ret,(int)s.size()-(int)i.fi.size()+i.se);
                break;
            }
        }
    }
    return ret;
}
int main() {
    freopen("A.in","r",stdin);
    for(ll i=0;i<60;i++){
        string s=to_string(1ll<<i);
        K(s);
        int cnt=0;
        while(!s.empty()){
            v.push_back({s,cnt});
            cnt++;
            s.pop_back();
        }
    }
    K(v.size());
    int _;I(_);
    while(_--){
        O(solve(),'\n');
    }
}