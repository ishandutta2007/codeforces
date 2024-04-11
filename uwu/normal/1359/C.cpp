#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

bool equal(long double a, long double b){
    return (abs(a-b)<0.000000000000001);
}

long double h,c,uwu; 
long double eval(ll x){
    return ((h*(x+1))+(c*(x)))/(2*x+1);
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> h >> c >> uwu;
        ll low=0,high=1'000'000'000'000,mid;
        if (uwu<(h+c)/2||equal(uwu,(h+c)/2)){
            cout << 2 << '\n';
            continue;
        } 
        if (uwu>h||equal(uwu,h)){
            cout << 1 << '\n';
            continue;
        }

        while (low<=high){
            mid=(low+high)/2;
            // cout << mid << " ";
            if (eval(mid+1)-(1e-22)<uwu){
                if (eval(mid)+(1e-22)>uwu) break;
                else{
                    high=mid-1;
                }
            }
            else{
                low=mid+1;
            }
        }
        // cout << '\n';
        // printf("%.10f\n",eval(mid));  
        // printf("%.10f\n",eval(mid+1));
        if (abs(uwu-eval(mid))<abs(uwu-eval(mid+1))||equal(abs(uwu-eval(mid)),abs(uwu-eval(mid+1)))){
            mid*=2;
            mid++;
            cout << mid << '\n';
        }
        else{
            mid++;
            mid*=2;
            mid++;
            cout << mid << '\n';
        }
    }
}