#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
int a[N];

int main(){
    int t; cin >> t;
    while (t--){
        cin >> n;
        priority_queue <pair <int, pair <int, int>> > pq; // {length, {n + 1 - l, n + 1 - r}}
        pq.push({n, {n, 1}});
        for (int i = 1; i <= n; i++){
            int l = n + 1 - pq.top().second.first;
            int r = n + 1 - pq.top().second.second;
            pq.pop();
            int mid = l + (r - l) / 2;
            a[mid] = i;
            pq.push({mid - 1 - l, {n + 1 - l, n + 1 - (mid - 1)}});
            pq.push({r - mid - 1, {n + 1 - (mid + 1), n + 1 - r}});
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}