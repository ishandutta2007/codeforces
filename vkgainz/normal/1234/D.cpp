#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s; cin >> s;
    set<int> x[26];
    for(int i=0;i<s.length();i++){
        x[s[i]-'a'].insert(i);
    }

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t==1){
            int p;
            char c;
            cin >> p >> c;
            --p; 
            x[s[p]-'a'].erase(p);
            s[p] = c;
            x[s[p]-'a'].insert(p);
        }
        else{
            int l,r; cin >> l >> r;
            --l; --r;
            int cnt = 0;
            for(int i=0;i<26;i++){
                auto k = x[i].lower_bound(l);
                if(k!=x[i].end() && *k<=r)
                    ++cnt;
            }
            cout << cnt << endl;
        }
    }
}