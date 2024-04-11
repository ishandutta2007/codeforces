#include <bits/stdc++.h>
using namespace std;

int t;
int n;
string flip(string s,int len){
    for(int i=0;i<len;i++){
        if(s[i]=='1') s[i]='0';
        else s[i]='1';
    }
    string ret = "";
    for(int i=0;i<len;i++){
        ret+=s[len-1-i];
    }
    return ret;

}
void solve(string a,string b){
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(a[i]==b[i]){
            continue;
        }
        else{
            if(a[0]==a[i]){
                ans.push_back(i);
                a = flip(a.substr(0,i+1),i+1)+a.substr(i+1,n);
            }
            else{
                ans.push_back(0);
                if(a[0]=='0') a[0]='1';
                else a[0] = '0';
                ans.push_back(i);
                a = flip(a.substr(0,i+1),i+1)+a.substr(i+1,n);
            }

        }
    }
    cout << ans.size() << " ";
    auto it = ans.begin();
    while(it!=ans.end()){
        cout << *it+1 << " ";
        it++;
    }

}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string a,b;
        cin >> a >> b;
        solve(a,b);
    }
}