#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define fec(i,x) for (i=x.begin();i!=x.end();++i)
#define re(i,a) for (int i=0;i<a;++i)
#define clr(x) memset(x,0,sizeof x)
#define mp make_pair
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
#define N 111111
int ans,a[N],n;
int main() {
    read(n);rep(i,1,n)read(a[i]);
    rep(i,1,n-1) {
        int t=1;
        while (i+t<=n) t<<=1;t>>=1;
        a[i+t]+=a[i];
        ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}