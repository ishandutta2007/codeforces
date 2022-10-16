#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void add(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

typedef array<array<int,maxn+5>,maxn+5> mat;
int mat_n;
mat operator *(const mat &A,const mat &B)
{
    mat C{};
    rep(i,0,mat_n-1) rep(k,0,mat_n-1) rep(j,0,mat_n-1) add(C[i][j],1ll*A[i][k]*B[k][j]%mod);
    return C;
}

mat A[maxn+5];
char s[maxn+5];

int main()
{
    int n,x; scanf("%d%d",&n,&x);
    scanf("%s",s);
    mat_n=n+1;
    rep(i,0,n) A[0][i][i]=(i==0 || i==n)?2:1;
    rep(i,0,n-1) if(s[i]=='0') A[0][i][i+1]=1;
    rep(i,0,n) A[1][i][i]=(i==0 || i==n)?2:1;
    rep(i,0,n-1) if(s[i]=='1') A[1][i][i+1]=1;
    rep(i,2,x) A[i]=A[i-1]*A[i-2];
    printf("%d\n",A[x][0][n]);
    return 0;
}