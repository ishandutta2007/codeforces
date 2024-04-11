#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++)
            cin >> A[i];
        set<int> d;
        for(int i = 1; i <= N; i++)
            d.insert(i);

        int newOne = 0;
        bool fails = false;
        vector<int> ans(N);
        for(int i =0; i < N; i++) {
            if(A[i] != newOne) {
                newOne = A[i];
                ans[i] = A[i];
                d.erase(A[i]);
            } else {
                int t = *d.begin();
                if(t <= A[i])
                    ans[i] = t, d.erase(t);
                else{ 
                    fails = true;
                    break;
                }
            }
        }
        if(fails) {
            cout << "-1" << '\n';
        } else {
            for(int i = 0; i < N; i++)
                cout << ans[i] << ' ';
            cout<< '\n';
        }
    }
}