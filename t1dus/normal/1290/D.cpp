#include<bits/stdc++.h>
using namespace std;

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
int q = 0,qlim;
int a[1025];
int BLS,BLK;

bool ask(int ind){
    q++;
    if(q > qlim) return 0;
    cout << "? " << ind << endl;
    char c; cin >> c;
    if(c == 'N') return 0;
    a[ind] = 0;
    return 1;
}

signed main(){
    cin >> n >> k;
    qlim = (n*n*3)/(2*k);
    for(int i = 1; i <= n; i ++) a[i] = 1;
    BLS = (k+1)/2;
    BLK = n/BLS;
    for(int st = 1; st <= BLK; st ++){
        cout << "R" << endl;
        int cur = st,d = 0;
        for(int j = 0; j < BLK; j ++){
            int x = st+d;
            if(x > BLK) x -= BLK;
            if(x <= 0) x += BLK;
            for(int i = x*BLS-BLS+1; i <= x*BLS; i ++){
                if(a[i]) ask(i);
            }
            if(d <= 0){
                d = (-d+1);
            }
            else d = -d;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i]) ans++;
    }
    cout << "! " << ans << endl;
}