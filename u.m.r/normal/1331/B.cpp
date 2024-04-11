#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

void solve(int casi){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << i << n / i << endl;
            return ;
        }
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}