#include <bits/stdc++.h>
using namespace std;

int t;
int n;
void solve(string a,string b){
    int allCurr = 0;
    vector<int> ans;
    if(a[0]=='1'){
        allCurr = 1;
    }
    for(int i=1;i<n;i++){
        if(allCurr){
            if(a[i]=='0'){
                ans.push_back(i-1);
                allCurr = 0;
            }
        }
        else{
            if(a[i]=='1'){
                ans.push_back(i-1);
                allCurr = 1;
            }

        }
    }
    for(int i=n-1;i>=0;i--){
        if(allCurr){
            if(b[i]=='0'){
                ans.push_back(i);
                allCurr = 0;
            }
        }
        else{
            if(b[i]=='1'){
                ans.push_back(i);
                allCurr = 1;
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