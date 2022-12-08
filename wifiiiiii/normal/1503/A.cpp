#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt0 = 0;
        for(char c : s) if(c == '0') ++cnt0;
        if(cnt0 & 1 || s[0] == '0' || s.back() == '0') {
            cout << "NO" << endl;
            continue;
        }
        string s1(s.size(),'0'), s2(s.size(),'0');
        vector<int> pos[2];
        for(int i=0;i<n;++i) {
            pos[s[i]-'0'].push_back(i);
        }
        for(int i=0;i<pos[0].size();i+=2) {
            s1[pos[0][i]]='(';s1[pos[0][i+1]]=')';
            s2[pos[0][i]]=')';s2[pos[0][i+1]]='(';
        }
        int l=0,r=pos[1].size()-1;
        while(l<r) {
            s1[pos[1][l]]=s2[pos[1][l]]='(';
            s1[pos[1][r]]=s2[pos[1][r]]=')';
            ++l,--r;
        }
        cout<<"YES"<<endl;
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
}