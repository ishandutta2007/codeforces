#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0;
        map<pair<int,int>, int> mp;
        for(char c : s) {
            if(c == 'D') ++a;
            else ++b;
            int g = gcd(a, b);
            ++mp[{a/g,b/g}];
            cout << mp[{a/g,b/g}] << " ";
        }
        cout << endl;
    }
}