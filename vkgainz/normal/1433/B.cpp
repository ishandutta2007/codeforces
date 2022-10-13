#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
const int N = 1000001;
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        int f = n+1;
        int l = 0;
        int num = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==1) f = min(f,i), l = max(l,i), ++num;
        }
        cout << l-f+1-num << endl;
        
    }
}