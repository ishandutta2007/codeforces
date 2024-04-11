#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        vector<int> c;
        vector<int> ans;
        int pw = 1;
        while(a) {
            c.push_back(a % 10);
            for(int i = 0; i < a % 10; ++i) ans.push_back(pw);
            pw = pw * 10;
            a /= 10;
        }
        while(ans.size() > b) {
            ans[ans.size()-2] += ans.back();
            ans.pop_back();
        }
        if(ans.size() == b) {
            for(int i : ans) cout << i << " ";
            cout << endl;
        } else {
            int cur = ans.size();
            priority_queue<int, vector<int>, greater<int>> q;
            vector<int> nxt;
            for(int i : ans) if(i > 1) q.push(i); else nxt.push_back(i);
            while(cur < b) {
                int p = q.top(); q.pop();
                if(p == 1) {
                    nxt.push_back(p);
                    continue;
                }
                cur += 9;
                for(int i = 0; i < 10; ++i) q.push(p / 10);
            }
            while(!q.empty()) nxt.push_back(q.top()), q.pop();
            ans = nxt;
            while(ans.size() > b) {
                ans[ans.size()-2] += ans.back();
                ans.pop_back();
            }
            for(int i : ans) cout << i << " ";
            cout << endl;
        }
    }
}