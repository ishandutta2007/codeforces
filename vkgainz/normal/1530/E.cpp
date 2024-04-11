#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = sz(s);
        vector<int> freq(26);
        for(int i = 0; i < n; i++) {
            ++freq[s[i]-'a'];
        }
        bool nul = false;
        for(int i = 0; i < 26; i++) nul |= freq[i] == n;
        if(nul) {
            cout << s << "\n";
            continue;
        }
        nul = false;
        for(int i = 0; i < 26; i++) nul |= freq[i] == 1;
        string ref = "abcdefghijklmnopqrstuvwxyz";
        if(nul) {
            int j = -1;
            for(int i = 0; i < 26; i++) {
                if(freq[i] == 1) {
                    j = i;
                    freq[j] = 0;
                    break;
                }
            }
            string ans = "";
            ans += ref[j];
            --freq[j];
            for(int i = 0; i < 26; i++)
                for(int j = 0; j < freq[i]; j++)
                    ans += ref[i];
            cout << ans << "\n";
            continue;
        }
        sort(s.begin(), s.end());
        string ans = "";
        if(freq[s[0] - 'a'] <= n / 2 + 1) {
            //aabababaaba...
            for(int j = 0; j < n; j++)
                ans += '0';
            int fir = s[0] - 'a';
            ans[0] = ref[fir];
            ans[1] = ref[fir];
            --freq[fir];
            --freq[fir];
            for(int j = 3; j < n; j += 2) {
                if(freq[fir]) {
                    ans[j] = ref[fir];
                    --freq[fir];
                }
            }
            int curr = 0;
            for(int j = 2; j < n; j++) {
                if(ans[j] != '0') continue;
                while(curr < 26 && freq[curr] == 0)
                    ++curr;
                ans[j] = ref[curr];
                --freq[curr];
            }
            cout << ans << "\n";
            continue;
        }
        int numIn = 0;
        for(int i = 0; i < 26; i++) numIn += (freq[i] > 0);
        int fir = -1, sec = -1;
        for(int i = 0; i < 26; i++) {
            if(fir == -1) {
                if(freq[i] > 0)
                    fir = i;
            }
            else {
                if(freq[i] > 0) {
                    sec = i;
                    break;
                }
            }
        }
        ans += ref[fir];
        ans += ref[sec];
        --freq[fir], --freq[sec];
        if(numIn == 2) {
            //abbbbaaa...
            for(int j = 0; j < freq[sec]; j++)
                ans += ref[sec];
            for(int j = 0; j < freq[fir]; j++)
                ans += ref[fir];
            cout << ans << "\n";
        }
        else {
            //xyxxxxzyyy...
            int third = -1;
            for(int i = 0; i < 26; i++) {
                if(i != fir && i != sec && freq[i] > 0) {
                    third = i;
                    break;
                }
            }
            for(int j = 0; j < freq[fir]; j++) 
                ans += ref[fir];
            freq[fir] = 0;
            ans += ref[third];
            --freq[third];
            for(int i = 0; i < 26; i++)
                for(int j = 0; j < freq[i]; j++)
                    ans += ref[i];
            cout << ans << "\n";
        }
    
    }
}