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
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<31||(n<32&&(n-30==6||n-30==10||n-30==14)))cout<<"NO"<<endl;
        else {
            int x=n-30;
            if(x==6)cout<<"YES"<<endl<<"5 6 10 15"<<endl;
            else {
                if(x==10)cout<<"YES"<<endl<<"6 9 10 15"<<endl;
                if(x==14)cout<<"YES"<<endl<<"6 10 13 15"<<endl;
                else if(x!=6&&x!=10&&x!=14)cout<<"YES"<<endl<<"6 10 14 "<<n-30<<endl;
            }

        }
    }
    return 0;
}