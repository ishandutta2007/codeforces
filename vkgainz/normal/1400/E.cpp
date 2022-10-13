#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int solve(int l,int r,vector<int> &x){
    if(l>r) return 0;
    int low = 1000000000;
    for(int i=l;i<=r;i++)
        low = min(low,x[i-l]);
    int ans = low;
    int nextL = l;
    vector<int> temp;
    for(int i=l;i<=r;i++){
        if(x[i-l]!=low){
            temp.push_back(x[i-l]-low);
        }
        else{
            ans+=solve(nextL,i-1,temp);
            nextL = i+1;
            temp.clear();
        }
    }
    ans+=solve(nextL,r,temp);
    return min(ans,r-l+1);
    
}
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    vector<int> temp;
    int l = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            temp.push_back(a[i]);
        }
        else{
            ans+=solve(l,i-1,temp);
            temp.clear();
            l = i+1;
        }
    }
    ans+=solve(l,n-1,temp);
    
    cout << ans << endl;
    
}