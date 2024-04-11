#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
string s;
int T=200,suf[maxn],n;
long long res=0;
map<int,int> mp;
vector<int> ones;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>s;
    n=s.size();
    for (int i=0;i<n;++i){
        suf[i+1]=suf[i]+s[i]-'0';
        if (s[i]>'0') ones.push_back(i+1); 
    }
    ones.push_back(n+1);
    for (int i=1;i<=T;++i){
        mp.clear();
        for (int j=0;j<=n;++j){
            int u=mp[suf[j]*i-j]++;
            res+=u;
        }
    }
    int k=0;
    auto f=[&](int i,int l,int r,int j){
 //       cout<<i<<" "<<l<<" "<<r<<" "<<j<<" "<<max((r-i)/j-max(T+1,(l-i)/j),0ll)<<endl;
        return max((r-i)/j-max(T,(l-i)/j),0);
    };
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n/T+1&&j+k<ones.size();++j){
            res+=f(i,ones[k+j-1],ones[k+j],j);
        }   
        if (ones[k]==i) k++;    
    }
    cout<<res<<endl;
    return 0;
}