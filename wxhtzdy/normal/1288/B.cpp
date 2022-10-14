#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
vector<ll> d;
void init(){ll c=9;for(int i=0;i<9;i++){d.push_back(c);c*=10;c+=9;}}
int main(){
    init();
    int t;
    scanf("%i",&t);
    while(t--){
        ll A,B;
        scanf("%lld %lld",&A,&B);
        int cnt=0;
        for(auto c:d)if(c<=B)cnt++;
        printf("%lld\n",A*cnt);
    }
    return 0;
}