#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct sq{
    int c, p, pos;
}s[1010];

struct tab{
    int r, pos;
}r[1010];

bool cmp1 (tab a, tab b){
    return a.r < b.r;
}

bool cmp2 (sq a, sq b) {
    if(a.p == b.p) return a.c < b.c;
    return a.p > b.p;
}

int u[1010], mp[1010];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].c >> s[i].p;
        s[i].pos = i;
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> r[i].r;
        r[i].pos = i;
    }
    sort(r + 1, r + 1 + k, cmp1);
    sort(s + 1, s + 1 + n, cmp2);

    int cnt = 0, num = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (!u[j] && s[i].c <= r[j].r){
                num++;
                cnt += s[i].p;
                u[j] = 1;
                mp[s[i].pos] = r[j].pos;
                break;
            }
        }
    }
    cout << num << ' ' << cnt << endl;
    for(int i = 1; i <= n; i++)
        if(mp[i]) cout << i << ' ' << mp[i] << endl;
}