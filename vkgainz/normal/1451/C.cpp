#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k; cin >> k;
        string a, b; cin >> a >> b;
        int f1[26], f2[26];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(int i=0;i<n;i++) {
            ++f1[a[i]-'a'];
            ++f2[b[i]-'a'];
        }
        bool work = 1;
        for(int i=0;i<26 && work;i++) {
            if(f1[i]%k != f2[i]%k || f1[i]<f2[i]) {
                work = 0;
                continue;
            }
            if(i==25) {
                work = f1[i]==f2[i];
                continue;
            }
            f1[i+1]+=f1[i]-f2[i];
            f1[i] = f2[i];
        }
        if(work) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}