#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int niz[100005];
bool bio[200005];
string a[100005], b[100005];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    for(int i=0; i<n; i++) cin >> niz[i];
    string prev = "";
    for(int j=0; j<n; j++){
        int i = niz[j]-1;
        string x = min(a[i], b[i]), y = max(a[i], b[i]);
        if(x > prev) prev = x;
        else{
            if(y > prev) prev = y;
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}