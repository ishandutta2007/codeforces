#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
const int maxn = 600005;
int st[maxn][22];
int query(int l,int r) {
   int k = 31 - __builtin_clz(r-l+1);
   return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(3 * n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i+n] = a[i+n+n] = a[i];
        }
        for(int i=0;i<3*n;++i) st[i][0]=a[i];
        for(int j=1;j<=21;++j)
            for(int i=0;i+(1<<j)-1<3*n;++i)
                st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        int ans = 0;
        auto check = [&]() {
            for(int i = 1; i < n; ++i) if(a[i] != a[0]) return 1;
            return 0;
        };
        int lo = 0, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int p = -1, ok = 1;
            for(int i = n; i < 2 * n; ++i) {
                int tmp = query(i, i + mid);
                if(p == -1) p = tmp;
                else if(p != tmp) {
                    ok = 0;
                    break;
                }
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}