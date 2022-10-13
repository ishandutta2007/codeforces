#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s; cin >> s;
        int numW = 0;
        for(int i=0;i<n;i++) numW+=(s[i]=='W');
        if(numW+k>=n) {
            cout << 2*n-1 << endl;
        }
        else {
            if(numW==0){
                cout << max(0,2*k-1) << endl;
            }
            else{
                vector<int> diff;
                int i = 0;
                int lastW = 0;
                bool seen = false;
                int numSeg = 0;
                while(i<n) {
                    if(s[i]=='W'){
                        if(!seen) ++numSeg;
                        if(i>lastW+1 && seen){
                            diff.push_back(i-lastW-1);
                            ++numSeg;
                        }                        
                        lastW = i;
                        seen = true;
                    }
                    ++i;
                }
                sort(diff.begin(),diff.end());
                int tot = 0;
                for(auto &it : diff){
                    if(tot+it<=k){
                        --numSeg;
                        tot+=it;
                    }
                }
                int ans = (numW+tot)*2-numSeg;
                ans+=2*(k-tot);
                cout << ans << endl;
            }
        }
    }
}