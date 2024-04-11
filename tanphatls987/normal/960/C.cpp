#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int main(){
        int n,dist;
        cin>>n>>dist;
        long long cur=1;
        vector <long long> ans;
        for(int i=0;n;i++,n>>=1) if (n&1){
                for(int j=0;j<i;j++) ans.push_back(cur);
                cur+=dist;
                ans.push_back(cur);
                cur+=dist;
        }
        cout<<ans.size()<<'\n';
        for(auto i:ans) cout<<i<<" ";
}