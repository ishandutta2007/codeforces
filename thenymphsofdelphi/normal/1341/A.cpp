#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a, b, c, d;

int main(){
int t; cin >> t;
while (t--){
    cin >> n >> a >> b >> c >> d;
    if (n * (a - b) > c + d || n * (a + b) < c - d) cout << "No" << endl;
    else cout << "Yes" << endl;
}
}