// author: xay5421
// created: Sun Jul 11 22:00:56 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int N=1005;
int a[N][N];LL sum[N],sum2[N];
int n,k,pos;
signed main(){
    rd(n);rd(k);
    rep(i,1,k)rep(j,1,n)rd(a[i][j]),sum[i]+=a[i][j],sum2[i]+=1LL*a[i][j]*a[i][j];
    LL det=-1;
    {
        LL a[4];a[0]=sum[2]-sum[1];a[1]=sum[3]-sum[2];a[2]=sum[4]-sum[3];a[3]=sum[5]-sum[4];sort(a,a+4);
        rep(i,1,3)if(a[i-1]==a[i])det=a[i];
        assert(det!=-1);
    }
    rep(i,2,k-1)if(sum[i]-sum[i-1]!=det&&sum[i+1]-sum[i]!=det)pos=i;
    if(!pos&&sum[2]-sum[1]!=det)pos=1;
    if(!pos&&sum[k]-sum[k-1]!=det)pos=k;
    pt(pos-1,' ');
    if(pos<=3){
        pos=k-pos+1;
        rep(i,1,n){
            int l=1,r=k;
            while(l<r){
                swap(a[l][i],a[r][i]);
                ++l;--r;
            }
        }
        reverse(sum+1,sum+k+1);reverse(sum2+1,sum2+k+1);
        det=-det;
    }
    LL need=sum[1]+det*(pos-1)-sum[pos];
    LL xy=(sum2[3]-sum2[1])/4,x=sum2[2]-sum2[1]-xy,y=xy-x;
    LL need2=sum2[1]+x*2*(pos-1)+y*(pos-1)*(pos-1);
    rep(i,1,n){
        if(sum2[pos]-1LL*a[pos][i]*a[pos][i]+1LL*(a[pos][i]+need)*(a[pos][i]+need)==need2){
            pt(a[pos][i]+need,'\n');
            return 0;
        }
    }
    return 0;
}