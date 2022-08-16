#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)

const int MAXN = 1000005;
 
int n,a[MAXN],b[MAXN],c[MAXN];
int cnt[31];
 
signed main(){
    cin >> n;
    int s = 0;
    FOR(i,1,n+1){
        cin >> b[i];
        s += b[i];
    }
    FOR(i,1,n+1){
        cin >> c[i];
        s += c[i];
    }
    if(s%(2*n)){
        cout << "-1\n";
        return 0;
    }
    s /= 2*n;
    FOR(i,1,n+1){
        if((b[i]+c[i]-s)%n){
            cout << "-1\n";
            return 0;
        }
        a[i] = (b[i]+c[i]-s)/n;
        REP(j,30){
            if(a[i]&(1<<j)) cnt[j]++;
        }
    }
    FOR(i,1,n+1){
        int x = 0,y = 0;
        REP(j,30){
            if(a[i]&(1<<j)){
                x += (1<<j)*n;
                y += (1<<j)*cnt[j];
            }
            else{
                x += (1<<j)*cnt[j];
            }
        }
        if(y != b[i] or x != c[i]){
            cout << "-1\n";
            return 0;
        }
    }
    FOR(i,1,n+1) cout << a[i] << " ";
    cout << "\n";
}