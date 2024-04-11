#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

void four(int x){
    cout << x-1 << " " << x-3 << " " << x << " " << x-2 << " ";
}
// 3 1 4 2

void five(int x){
    cout << x-2 << " " << x << " " << x-4 << " " << x-1 << " " << x-3 << " ";
}
// 3 5 1 4 2

void six(int x){
    cout << x-1 << " " << x-3 << " " << x << " " << x-4 << " " << x-2 << " " << x-5 << " ";
}
// 5 3 6 2 4 1 

void seven(int x){
    cout << x-2 << " " << x << " " << x-4 << " " << x-1 << " " << x-5 << " " << x-3 << " " << x-6 << " ";
}
// 5 7 3 6 2 4 1 

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n<4){
            cout << -1 << '\n';
            continue;
        }
        while (n!=0){
            if (n%4==0){
                four(n);
                n-=4;
            }
            else if (n%4==1){
                five(n);
                n-=5;
            }
            else if (n%4==2){
                six(n);
                n-=6;
            }
            else if (n%4==3){
                seven(n);
                n-=7;
            }
        }
        cout << '\n';

    }
}