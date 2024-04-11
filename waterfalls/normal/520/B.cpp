#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int best[100000];

int main() {
    cin >> n >> m;
    if (m<n) cout << n-m;
    else {
        for (int i=0;i<100000;i++) best[i] = 1000000;
        queue<int> frontier;
        frontier.push(n);
        best[n] = 0;
        while (frontier.size()>0) {
            int next = frontier.front();
            frontier.pop();
            if (2*next<100000 && best[2*next]>best[next]+1) {
                best[2*next] = best[next]+1;
                frontier.push(2*next);
            }
            if (next-1>=0 && best[next-1]>best[next]+1) {
                best[next-1] = best[next]+1;
                frontier.push(next-1);
            }
        }
        cout << best[m];
    }

    return 0;
}