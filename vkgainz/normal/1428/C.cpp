#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        bool seen[s.length()];
        memset(seen,0,sizeof(seen));
        vector<int> x;
        vector<int> y;
        int k = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='A') {
                x.push_back(i);
            }
            else {
                if(x.size()>0) {
                    seen[x[x.size()-1]] = true;
                    seen[i] = true;
                    ++k;
                    x.pop_back();
                }
                else y.push_back(i);
            }
        }
        for(int i=0;!y.empty() && i<y.size()-1;i++) {
            int num = 0;
            for(int j=y[i]+1;j<y[i+1];j++) {
                if(seen[j]) ++num;
            }
            if(num==(y[i+1]-y[i]-1)) {
                ++k;
                ++i;
            }
        }
        cout << s.length()-2*k << endl;
    }
}