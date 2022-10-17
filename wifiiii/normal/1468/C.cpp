#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 500005;
int vis[maxn];
int q[maxn], t=0, h=1;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> m;
    int tp = 0;
    typedef pair<int,int> pii;
    priority_queue<pii> pq;
    for(int i=1;i<=m;++i)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x;
            cin >> x;
            ++tp;
            q[++t] = tp;
            pq.push({x, -tp});
        }
        else if(op == 2)
        {
            while(vis[q[h]]) ++h;
            vis[q[h]] = 1;
            cout << q[h] << ' ';
        }
        else if(op == 3)
        {
            while(vis[-pq.top().second]) pq.pop();
            vis[-pq.top().second]=1;
            cout << -pq.top().second << ' ';
        }
    }
    cout << endl;
}