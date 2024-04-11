#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int r1,r2,k; scanf("%d%d%d",&r1,&r2,&k);
        int x=r1+r2,r=r1-r2,y=r*k*2;
        db l=sqrt(1ll*x*x+1ll*y*y);
        db l1=4*r1*r2/(l+r),l2=4*r1*r2/(l-r);
        printf("%.10f\n",(l2-l1)/2);
    }
    return 0;
}