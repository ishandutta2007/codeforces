//zisha :(
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}

int main(){
    int t=ri();
    while(t--){
        int n=ri();
        vector<int> a(n);
        for(int&i:a)scanf("%i",&i);
        bool ok=0;
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]){
                printf("YES\n");
                printf("%i %i %i\n",i,i+1,i+2);
                ok=1;break;
            }
        }
        if(!ok)printf("NO\n");
    }
    return 0;
}