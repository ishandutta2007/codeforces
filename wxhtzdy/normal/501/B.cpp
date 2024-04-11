#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<string,string> mp;
    map<string,string> p;
    map<string,int> was;
    vector<string> all;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(!was[a])all.push_back(a),mp[a]=b,p[b]=a;
        else p[b]=p[a],mp[p[a]]=b;
        was[a]=0,was[b]=1;
    }
    cout << all.size() << '\n';
    for(auto c:all)cout << c << " " << mp[c] << '\n';
    return 0;
}