#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= n; i++)
#define dep(i,a,n) for (int i = a; i >= n; i++)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define eps 1e-8
#define lowbit(x) (x&(-x))
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define inf 0x7fffffff
#define mod 1000000007
#define N 100005
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<int,int> ma;int P[N],to[N],n,a,b,q[N],use[N],id,l,r;
bool ok(int p,int c,int a,int b){
    q[l=r=1]=p,use[p]=++id;
    while(l<=r){
        int p=q[l++],x;
        x=ma[a-P[p]];
        if(!x)return 0;
        if(use[x]!=id)use[x]=id,q[++r]=x;
        x=ma[a-(b-P[p])];
        if(x&&use[x]!=id)use[x]=id,q[++r]=x;
        x=ma[b-P[p]];
        if(x&&use[x]!=id)use[x]=id,q[++r]=x;
    }
    rep(i,1,r) to[q[i]]=c;
    return 1;
}
int main() {
    read(n,a,b);rep(i,1,n)read(P[i]),ma[P[i]]=i;
    rep(i,1,n)if(!to[i]&&!ok(i,1,a,b)&&!ok(i,2,b,a)) return puts("NO"),0;
    puts("YES");rep(i,1,n)printf("%d%c",to[i]-1,i<n?' ':'\n');
    return 0;
}