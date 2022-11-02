#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct num {
    int val, pos;
} a[220];

bool cmp(num a, num b){
    return a.val > b.val;
}

int main() {
    int n, k, bol[220], t[220], s[220];
    priority_queue <int, vector <int>, greater <int> > q;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        a[i].val = s[i];
        a[i].pos = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int mx = -1e9;
    for (int i = 1; i <= n; i++){
        memset (bol, 0, sizeof(bol));
        while (!q.empty()) q.pop();
        int sum = 0;

        for (int j = i; j <= n; j++)
        {
            sum += s[j];
            bol[j] = 1;
            q.push (s[j]);
            int ti = 0, bi = 1 ,ts = sum;
            while (1)
            {
                while (bol[a[bi].pos] == 1)bi++;
                if(bi == n + 1)break;
                if(q.top() < a[bi].val){
                    ts += a[bi].val - q.top();
                    t[++ti] = q.top();
                    q.pop();
                    bi++;
                }
                else break;
                if(ti == k || q.empty()) break;
            }
            for (int k = 1; k <= ti; k++)
                q.push(t[k]);
            if(mx < ts) mx = ts;
//
//            cout << sum << ' ' << ts << endl;
//            for (int k = 1; k <= n; k++)
//            cout << bol[k];
//            cout << endl;
        }
    }
    cout << mx;
}