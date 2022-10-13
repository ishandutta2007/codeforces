#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> nums;
        vector<int> g2;
        int idx = 0;
        for(int i=0;i<s.length();i++) {
            int diff = 0;
            for(int j=i;j<s.length() && s[j]==s[i];j++){
                ++diff;
                i = j;
            }
            nums.push_back(diff);

            if(diff>=2) g2.push_back(idx);
            idx++;
        }
        int ans = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>1) {
                ++ans;
            }
            else {
                if(j<g2.size()) {
                    --nums[g2[j]];
                    if(nums[g2[j]]==1) ++j;
                    ++ans;
                }
                else {
                    ++ans;
                    ++i;
                }
            }
            if(j<g2.size() && g2[j]==i) ++j;
        }
        cout << ans << endl;

    }
}