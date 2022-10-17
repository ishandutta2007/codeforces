#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string get(int k) {
    string s;
    map<string,int> vis;
    for(int i=0;i<k;++i) s+=string(2,'a'+i);
    for(int i=0;i+1<s.size();++i) vis[s.substr(i,2)]=1;
    int found=1;
    while(found) {
        found=0;
        for(int i=k-1;i>=0;--i) {
            string tmp=string(1,s.back())+(char)('a'+i);
            if(!vis[tmp]) {
                vis[tmp]=1;
                s+='a'+i;
                found=1;
                break;
            }
        }
    }
    s.pop_back();
    return s;
}
int main() {
    int n,k;
    cin>>n>>k;
    string s=get(k);
    string ans=s;
    while(ans.size()<n) ans+=s;
    cout<<ans.substr(0,n)<<'\n';
}