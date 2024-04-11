#include <bits/stdc++.h>
using namespace std;
string s;
int get(int x){
    int cnt =0;
    int ret =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')
            cnt+=x;
        else
            cnt-=x;
        ret = max(ret,cnt);
        if(cnt<0) cnt=0;
    }
    return ret;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cin >> s;
        int num = max(get(1),get(-1));
        cout << num << endl;
        int max = 0;
        int curr = 0;
        int last[n];
        set<int, greater<int>> zero;
        set<int, greater<int>> one;
        if(s[0]=='0'){
            last[0] = 0;
            zero.insert(0);
        }
        else{
            last[0] = 1;
            one.insert(0);
        }
        int ans[n];
        ans[0] = curr;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                if(one.empty()){
                    ans[i] = curr+1;
                    curr++;
                    zero.insert(curr);
                }
                else{
                    auto it = one.begin();
                    ans[i] = *it;
                    zero.insert(*it);
                    one.erase(it);
                }
            }
            else{
                if(zero.empty()){
                    ans[i] = curr+1;
                    curr++;
                    one.insert(curr);
                }
                else{
                    auto it = zero.begin();
                    ans[i] = *it;
                    one.insert(*it);
                    zero.erase(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << ans[i]+1 << " ";
        }
        cout << endl;
    }
}