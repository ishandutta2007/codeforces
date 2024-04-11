#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    string s;
    cin>>s;
    int cnt=1,mx=1;
    for(int i=1;i<(int)s.length();i++){
        if(s[i]==s[i-1])cnt++,mx=max(mx,cnt);
        else cnt=1;
    }
    if(mx<7)cout<<"NO";
    else cout<<"YES";
}