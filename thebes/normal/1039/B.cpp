#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef long long ll;
ll n, k, l, r, g, m;
string s;
inline ll R(){
    return rand()^time(0);
}
inline bool qu(ll l,ll r){
    printf("%lld %lld\n",l,r);
    fflush(stdout);
    cin >> s;
    if(s=="Bad") exit(0);
    return s=="Yes";
}

int main(){
    srand(22);
    scanf("%lld%lld",&n,&k);
    l = 1; r = n;
    while(1){
        if(r-l<=50){
            g = (R()%(r-l+1))+l;
            if(qu(g,g)) return 0;
            l = max(1LL, l-k-1);
            r = min(n, r+k+1);
        }
        else{
            l = max(1LL, l-k-1);
            r = min(n, r+k+1);
            m = l+r>>1;
            if(qu(l,m)) r=m;
            else l=m+1;
        }
    }
}