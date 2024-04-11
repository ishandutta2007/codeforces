    #include<bits/stdc++.h>
     
    using namespace std;
     
    int main () {
        int tt;
        cin >> tt;
        while (tt--) {
            int n, k;
            cin >> k >> n;
            if(k == 1) cout << 0 << endl;
            if(k == 2) cout << n << endl;
            if( k > 2) cout << n * 2 << endl;
        }
    }