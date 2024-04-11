#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define reu(i,a) for(int i = h[a];~i;i = n1[i])

typedef long long ll;
typedef long double db;

template <class T> inline void read(T &x){
    char ch = getchar();    int f = 1;  while((ch != '-') && (ch < '0' || ch > '9'))    ch = getchar();
    if(ch == '-')   f = 0, x = 0;   else    x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9')   x = x * 10 + ch - 48, ch = getchar();
    if(!f)  x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
    if(!x)  putchar('0');
    else{
        if(x < 0)   putchar('-'),x = -x;
        for(_t[0] = 0;x;x /= 10)    _t[++ _t[0]] = x % 10;
        dwn(i,_t[0],1)  putchar(_t[i] + 48);
    }
    if(ln)  putchar('\n');
}

/*...........................................................................................................*/

#define N 100010

int gcd(int a,int b){
    return (!b) ? a : gcd(b,a % b);
}

int f[17][N],g[17][N];
int lg[N],a[N],n,bin[N];

vector <int> v[N];
map<int,int> id;

pair <int,int> ask(int l,int r){
    int k = lg[r - l + 1];
    return mp(min(f[k][l],f[k][r - (1 << k) + 1]),gcd(g[k][l],g[k][r - (1 << k) + 1]));
}

int coooo(int l,int r,int x){
    return upper_bound(v[id[x]].begin(),v[id[x]].end(),r) - lower_bound(v[id[x]].begin(),v[id[x]].end(),l);
}

int main(){
    read(n);
    rep(i,1,n)  read(a[i]),f[0][i] = g[0][i] = a[i],bin[i] = a[i];
    sort(bin + 1,bin + n + 1);
    int cnt = unique(bin + 1,bin + n + 1) - bin - 1;
    rep(i,1,n){
        int x = lower_bound(bin + 1,bin + n + 1,a[i]) - bin;
        v[x].pb(i);
        id[a[i]] = x;
    }
    rep(i,1,cnt)    sort(v[i].begin(),v[i].end());
    rep(i,1,16){
        for(int j = 1;j + (1 << i) - 1 <= n;j ++){
            f[i][j] = min(f[i - 1][j],f[i - 1][j + (1 << (i - 1))]);
            g[i][j] = gcd(g[i - 1][j],g[i - 1][j + (1 << (i - 1))]);
        }
    }
    lg[1] = 0;
    rep(i,2,n)  if(i & (i - 1)) lg[i] = lg[i - 1];  else    lg[i] = lg[i - 1] + 1;
    int Q,x,y;
    read(Q);
    while(Q --){
        read(x,y);
        pair <int,int> t = ask(x,y);
        if(t.se % t.fi) out(y - x + 1);
        else    out(y - x + 1 - coooo(x,y,t.fi));
    }
    return 0;
}