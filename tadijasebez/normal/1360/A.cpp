/*
Fuck what you want
Bitch, I got what you need
Don't call me up once
'Cause you cried and you need me
So fuck what you want
Bitch, I cried way too much
Bitch, I died way too much
For that shit, eh
*/
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
        int a,b;rd(a,b);
        if(a>b)swap(a,b);
        int len=max(a*2,b);
        printf("%i\n",len*len);
    }
    return 0;
}