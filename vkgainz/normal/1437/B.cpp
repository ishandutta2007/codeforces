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
        string s; cin >> s;
        int ans = 0;
        for(int i=0;i<n;i++) if(s[i]==s[(i+1)%n]) ++ans;
        cout << ans/2 << endl;
    }
}