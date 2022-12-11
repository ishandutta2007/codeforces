#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 1e5 + 10;

priority_queue<ii> q1, q2;

int main() { 
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        q1.push(ii(v1,i));
        q2.push(ii(v2,i));
    }
    long long ans = n;
    for(int i = 1; i <= n; i++){
        ans += max(q1.top().X, q2.top().X);
        q1.pop(); q2.pop();
    }
    cout << ans;
}