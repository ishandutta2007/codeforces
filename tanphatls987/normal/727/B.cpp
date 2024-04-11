#include <bits/stdc++.h>

using namespace std;


int price(char ch){
    if (ch=='.') return 1;
    if (ch>='0'&&ch<='9') return 1;
    return 0;
}
int main(){
    long long ans=0;
    string s;
    cin>>s;
    int n=s.length();
    for(int en=0;en<n;en++) if (price(s[en])){
        long long cur=0,st=en;
        while (en<n&&price(s[en])){
            if (s[en]!='.') cur=10*cur+s[en]-'0';
            en++;
        }
        if (en-3<st||s[en-3]!='.') cur*=100;
        ans+=cur;
    }
//    cout<<ans<<'\n';
    string sans;
    if (ans%100){
        for(int i=0;i<=1;i++) {
            sans.push_back(ans%10+'0');
            ans/=10;
        }
        sans.push_back('.');
    }else ans/=100;
    for(int i=1;;i++){
        sans.push_back(ans%10+'0');
        if (i%3==0) sans.push_back('.');
        ans/=10;
        if (ans==0) break;
    }
    if (sans[sans.length()-1]=='.') sans.pop_back();

    reverse(sans.begin(),sans.end());
    cout<<sans;
}