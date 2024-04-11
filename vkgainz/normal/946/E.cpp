#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int bit = 0;
        bit = bit^(1<<(s[0]-'0'));
        int maxTake = 0;
        for(int i=1;i<s.length();i++) {
            bool work = false;
            int cnt = 0;
            for(int j=0;j<10;j++) {
                if(bit&(1<<j)) {
                    ++cnt;
                    if(j<s[i]-'0') work = true;
                }
            }
            bit = bit^(1<<(s[i]-'0'));
            if(s[i]-'0'==0) continue;
            if(work && cnt<=s.length()-i) {
                maxTake = i;
                continue;
            }
            int tempBit = bit^(1<<(s[i]-'0'-1));
            tempBit^=(1<<(s[i]-'0'));
            cnt = 0;
            for(int j=0;j<10;j++) if(tempBit&(1<<j)) ++cnt;
            if(cnt<=s.length()-i-1) maxTake = i;
        }
        string ans = "";
        if(maxTake==0) {
            if(s[0]=='1') {
                while(ans.length()!=s.length()-2) {
                    ans+="9";
                }
            }
            else {
                ans+=to_string(s[0]-'0'-1);
                ans+=to_string(s[0]-'0'-1);
                while(ans.length()!=s.length()) ans+="9";
            }
        }
        else {
            int bit = 0;
            for(int i=0;i<maxTake;i++) {
                ans+=s[i];
                bit^=(1<<(s[i]-'0'));
            }
            int take = -1;
            int cnt = 0;
            for(int j=0;j<10;j++) {
                if(bit&(1<<j) && j<s[maxTake]-'0') {
                    take = j;
                    ++cnt;
                }
            }
            int tempBit = bit^(1<<(s[maxTake]-'0'-1));
            cnt = 0;
            for(int j=0;j<10;j++) if(tempBit&(1<<j)) ++cnt;
            if(cnt<=s.length()-maxTake-1) {
                ans+=to_string(s[maxTake]-'0'-1);
                cnt = 0;
                for(int j=0;j<10;j++) if(tempBit&(1<<j)) ++cnt;
                while(ans.size()!=s.length()-cnt) ans+="9";
                for(int j=9;j>=0;j--) if(tempBit&(1<<j)) ans+=to_string(j);
            }
            else {
                ans+=to_string(take);
                bit^=1<<take;
                cnt = 0;
                for(int j=0;j<10;j++) if(bit&(1<<j)) ++cnt;
                while(ans.size()!=s.length()-cnt) ans+="9";
                for(int j=9;j>=0;j--) if(bit&(1<<j)) ans+=to_string(j);
            }
        }
        cout << ans << endl;
    }
}