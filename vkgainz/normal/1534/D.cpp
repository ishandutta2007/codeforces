#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> ask(int r) {
    cout << "? " << r + 1 << "\n";
    cout.flush();
    vector<int> ret(n);
    for(int i = 0; i < n; i++)
        cin >>  ret[i];
    return ret;
}

int main() {
    cin >> n;
    vector<vector<int>> dist(n);
    vector<int> st = ask(0);
    vector<int> par(n), depth(n);
    for(int i = 1; i < n; i++) {
        dist[st[i]].push_back(i);
        depth[i] = st[i];
        if(depth[i] == 1)
            par[i] = 0;
    }
    int sumOdd = 0, sumEven = 0;
    for(int i = 1; i < n; i++) {
        if(i % 2)
            sumOdd += dist[i].size();
        else
            sumEven += dist[i].size();
    }
    par[0] = -1;
    int numUsed = 1;
    if(sumOdd < sumEven) {
        for(int i = 1; i < n; i+=2) {
            for(int j : dist[i]) {
                if(numUsed >= (n + 1) / 2) continue;
                vector<int> t = ask(j);
                for(int nxt = 0; nxt < n; nxt++) {
                    if(depth[nxt] == depth[j] - 1 && t[nxt] == 1) {
                        par[j] = nxt;
                    }
                    else if(depth[nxt] == depth[j] + 1 && t[nxt] == 1) {
                        par[nxt] = j;
                    }
                }
            }
        }
    }
    else if(sumEven <= sumOdd) {
        for(int i = 2; i < n; i += 2) {
            for(int j : dist[i]) {
                if(numUsed >= (n + 1) / 2) continue;
                vector<int> t = ask(j);
                for(int nxt = 0; nxt < n; nxt++) {
                    if(depth[nxt] == depth[j] - 1 && t[nxt] == 1) {
                        par[j] = nxt;
                    }
                    else if(depth[nxt] == depth[j] + 1 && t[nxt] == 1) {
                        par[nxt] = j;
                    }
                }
            }
        }
    }
    cout << "! " << "\n";
    for(int i = 1; i < n; i++) {
        cout << i + 1 << " " << par[i] + 1 << "\n";
    }
}