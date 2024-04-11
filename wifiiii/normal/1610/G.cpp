#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 5;
deque<char> stk[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dep(n + 1), del(n + 1);
    int tp = 0, cnt = 0;
    for(char c : s) {
        if(c == '(') {
            ++tp;
            ++cnt;
            stk[tp] = {'('};
            dep[tp] = cnt;
            del[tp] = 0;
        } else {
            if(cnt > 0) {
                while(tp && dep[tp] != cnt) {
                    if(stk[tp].size() < stk[tp-1].size()) {
                        while(!stk[tp].empty()) {
                            stk[tp-1].push_back(stk[tp].front());
                            stk[tp].pop_front();
                        }
                    } else {
                        while(!stk[tp-1].empty()) {
                            stk[tp].push_front(stk[tp-1].back());
                            stk[tp-1].pop_back();
                        }
                        swap(stk[tp], stk[tp-1]);
                    }
                    --tp;
                }
                --cnt;
                stk[tp].push_back(')');
                del[tp] = 1;
            } else {
                stk[++tp] = {')'};
                del[tp] = 0;
            }
        }
        while(tp >= 2 && del[tp] && del[tp-1] && stk[tp] < stk[tp-1]) {
            swap(stk[tp-1], stk[tp]);
            --tp;
        }
    }
    vector<int> bad(tp + 1);
    for(int i = tp; i >= 1; --i) {
        if(del[i]) bad[i] = 1;
        if(stk[i] == deque<char>{')'}) break;
    }
    for(int i = 1; i <= tp; ++i) if(!bad[i]) for(char c:stk[i]) cout << c;
}