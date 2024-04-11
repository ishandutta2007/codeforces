#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100000;

int a[MAXN];

void Check(int n){
    ll sum = 0;
    for(int i=0; i<n; i++) sum += a[i];
    if(sum%2) return;
    map<ll, int> was;
    for(int i=0; i<n; i++) was[a[i]]++;
    if(was[sum/2]){
        cout << "YES";
        exit(0);
    }
    ll s = sum;
    for(int i=0; i<n; i++){
        was[a[i]]--;
        s -= a[i];
        ll dif = s - sum/2;
        if(was[dif]){
            cout << "YES";
            exit(0);
        }
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }    
    Check(n);
    reverse(a, a+n);
    Check(n);
    cout << "NO";
    return 0;
}