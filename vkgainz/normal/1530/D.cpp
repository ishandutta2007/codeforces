#include <bits/stdc++.h>
using namespace std;
 
#define rsz(x, n) x.clear(), x.resize(n)

vector<int> a;
vector<vector<int>> rev;
vector<bool> vis;
vector<int> in_cyc;
vector<bool> part_cyc;
vector<int> match;

void dfs(int curr) {
    vis[curr] = true;
    if(!vis[a[curr]])
        dfs(a[curr]);
    else {
        int st = curr;
        while(a[st] != curr) {
            part_cyc[st] = true;
            in_cyc.push_back(st);
            st = a[st];
        }
        part_cyc[st] = true;
        in_cyc.push_back(st);
        return;
    }
}

void dfs2(int curr) {
    for(int next : rev[curr]) {
        if(!part_cyc[next]) {
            vis[next] = true;
            dfs2(next);
        }
    }
    if(!rev[curr].empty())
        match[rev[curr][0]] = curr;
}

void get_match(vector<int> s, vector<int> r, vector<int> &c, int n) {
    int eq = -1;
    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] == r[i])
            eq = i;
    }
    if(eq != -1) {
        match[s[eq]] = a[s[eq]];
        for(int j = 0; j < n; j++) {
            if(j != s[eq] && match[j] == a[s[eq]]) {
                match[j] = s[eq];
                break;
            }
        }
    }
    for(int i = 0; i < (int) s.size(); i++) {
        if(i != eq)
            match[s[i]] = r[i];
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        rsz(a, n), rsz(rev, n);
        rsz(part_cyc, n);
        rsz(vis, n);
        match.clear(), match.resize(n, -1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
            rev[a[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            in_cyc.clear();
            dfs(i);
            for(int x : in_cyc) {
                dfs2(x);
            }
        }
        vector<bool> left(n, true);
        vector<int> r, s;
        for(int i = 0; i < n; i++) {
            if(match[i] != -1)
                left[match[i]] = false;
            else
                s.push_back(i);
        }
        for(int i = 0; i < n; i++)
            if(left[i]) 
                r.push_back(i);
        reverse(r.begin(), r.end());
        get_match(s, r, match, n);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += a[i] == match[i];
        cout << ans << "\n";
        for(int i = 0; i < n; i++) {
            cout << match[i] + 1 << " ";
        }
        cout << "\n";
    }
}