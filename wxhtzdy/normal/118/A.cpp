#include<bits/stdc++.h>
using namespace std;
#define pb push_back
string s,v="aoyeui";
int main(){
    cin>>s;
    int n=(int)s.length();
    for(int i=0;i<n;i++)if(s[i]<'a')s[i]+='a'-'A';
    for(int i=0;i<n;i++){
        bool ok=1;
        for(int j=0;j<(int)v.length();j++)if(s[i]==v[j])ok=0;
        if(!ok)continue;
        cout<<'.'<<s[i];
    }
}