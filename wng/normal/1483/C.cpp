#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define R(X) cin>>(X)
#define RII(X, Y) cin>>(X)>>(Y)
#define RIII(X, Y, Z)  cin>>(X)>>(Y)>>(Z)
#define DRI(X) int (X); cin>>(X)
#define DRII(X, Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X, Y, Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I]) 
#define DRVL(N, X) VL X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I])
#define RS(X) cin>>X
#define DRS(X) string X; cin>>X
#define CASET int ___T, case_n = 1; cin>>___T; while (___T-- > 0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define PB push_back
#define F first
#define S second

using namespace std;

const int N = 3*1e5;  // limit for array size
int n;  // array size
LL t[2 * N];
int lim=1000000009;

void build() {  // build the tree"
  for (int i = n - 1; i > 0; --i) {t[i] = max(t[i<<1], t[i<<1|1]);
  //cout<<t[i<<1]<<"   "<<t[i<<1|1]<<endl;
  }
}

void modify(int p, LL value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
    //REP(i,20) {cout<<t[i]<<" ";} cout<<endl;
}

LL query(int l, int r) {  // sum on interval [l, r)
  LL res = -lim;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res= max(res, t[l++]);
    if (r&1) res= max(res, t[--r]);
  }
  //cout<<"q "<<l<<" "<<r<<" "<<res<<endl;
  return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    R(n);
    REP(i,n){t[n+i]=0;}
    build();
    DRVI(n,h);
    DRVI(n,b);
    //t c mon max(bp)
    VL bp(n,0);
    map<int,int> lastlower;
    lastlower[-1]=-1;
    REP(i,n){
        lastlower[h[i]]=i;
        auto z=lastlower.lower_bound(h[i]);
        z++;
        lastlower.erase(z, lastlower.end());
        z=lastlower.end();
        z--;
        z--;
        int mll=z->S;
        if (mll==-1){
            //cout<<"   "<<query(0,i+1)<<endl;
            bp[i]=query(0,i+1)+b[i];
        }
        else{
            //cout<<" x "<<mll<<" "<<i<<" "<<query(mll,i)<<endl;
            bp[i]=max(bp[mll], query(mll,i)+b[i]);
        }
        modify(i, bp[i]);
    
    }
    //for (auto i: bp){
    //    cout<<i<<" ";
   // }
    //cout<<endl;

    cout<<bp[n-1]<<"\n";
}