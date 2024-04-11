#include <bits/stdc++.h>

using namespace std;

const string wowel="AEIOUY";

bool iswowel(char ch){
    for(auto i:wowel) if (ch==i) return 1;
    return 0;
}
int main(){
    string s;
    cin>>s;
    s.push_back('A');
    int last=0,ans=0;
    for(int i=1;i<=s.length();i++) if (iswowel(s[i-1])){
        ans=max(ans,i-last);
        last=i;
    }
    cout<<ans;
}