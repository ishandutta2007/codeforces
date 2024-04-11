#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
#define pb push_back
#define ll long long
const int MAXN = 2e3 + 1;
const int M = 1e9+7;


void go()
{
    int N; cin >> N;
    priority_queue<int> pq;
    ll ans = 0;
    int x; cin >> x;
    pq.push(x);
    for(int i = 1, x; i < N; i++) {
        cin >> x;
        x -= i;
        pq.push(x);
        if(pq.top() > x) {
            ans += pq.top() - x;
            pq.pop();
            pq.push(x);
        }
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while(t--)
		go();
}