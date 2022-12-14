#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;

vector<string>v;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for(auto i:v){
        if(s.find(i)==-1){
            cout<<i<<'\n';
            return;
        }
    }
}
int main(){
    for(string i="a";i<="z";i[0]++)
    v.push_back(i);
    for(string i="a";i<="z";i[0]++)for(string j="a";j<="z";j[0]++)v.push_back(i+j);
    for(string i="a";i<="z";i[0]++)for(string j="a";j<="z";j[0]++)for(string k="a";k<="z";k[0]++)v.push_back(i+j+k);
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
}