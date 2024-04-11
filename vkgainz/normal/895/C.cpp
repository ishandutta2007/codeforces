#include <bits/stdc++.h>
using namespace std;
#define ll long long
int basis[20];
int sz;
void insert(int msk) {
    for(int i=0;i<20;i++) {
        if(msk&(1<<i)) {
            if(!basis[i]) {
                basis[i] = msk;
                ++sz;
                return;
            }
            msk^=basis[i];
        }
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> nums;
    int val[71];
    val[1] = 0;
    map<int,int> m;
    m[2] = 0, m[3] = 1, m[5] = 2, m[7] = 3, m[11] = 4, m[13] = 5, m[17] = 6, m[19] = 7, m[23] = 8, m[29] = 9, m[31] = 10, m[37] = 11, m[41] = 12, m[43] = 13, m[47] = 14, m[53] = 15, m[59] = 16, m[61] = 17, m[67] = 18;
    for(int i=2;i<=70;i++) {
        val[i] = 0;
        int temp = i;
        for(int j=2;j<=70;j++) {
            if(i%j==0) {
                int cnt = 0;
                while(i%j==0) i/=j, ++cnt;
                if(cnt%2)   
                val[temp]+=1<<m[j];
            }
        }
        i = temp;
    }
    for(int i=0;i<n;i++) {
        insert(val[a[i]]);
    }
    int ans = 1;
    int mod = 1000000007;
    for(int i=1;i<=n-sz;i++) {
        ans*=2;
        if(ans>mod) ans-=mod;
    }
    ans--;
    if(ans<0) ans+=mod;
    cout << ans << endl;
    
}