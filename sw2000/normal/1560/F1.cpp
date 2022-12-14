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

vi v;
void solve(){
    int a,k;I(a,k);
    v.clear();
    while(a){
        v.push_back(a%10);
        a/=10;
    }
    reverse(v.begin(),v.end());
    bool vis[14]{};
    int cnt=0,mi=10,lst=0;
    for(int i=0;i<v.size();i++)if(!vis[v[i]]){
        if(cnt==k){
            for(int j=v[i]+1;j<10;j++)if(vis[j]){
                v[i]=j;
                for(int t=i+1;t<v.size();t++)v[t]=mi;
                return;
            }
            for(int j=i-1;j>lst;j--){
                for(int l=v[j]+1;l<10;l++)if(vis[l]){
                    v[j]=l;
                    for(int t=j+1;t<v.size();t++)v[t]=mi;
                    return;
                }
            }
            v[lst]++;
            if(vis[v[lst]])mi=0;
            else{
                mi=10;
                for(int j=0;j<=lst;j++)Min(mi,v[j]);
            }
            for(int j=lst+1;j<v.size();j++)v[j]=mi;
            return;
        }
        cnt++;
        lst=i;
        vis[v[i]]=1;
        Min(mi,v[i]);
    }
}
int main() {
    freopen("A.in","r",stdin);
    int _;I(_);
    while(_--){
        solve();
        for(auto i:v)O(i);
        O('\n');
    }
}