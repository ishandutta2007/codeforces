#include <bits/stdc++.h>

using namespace std;


int main(){
    string s,patt;
    int m;
    cin>>m;
    cin>>patt;
    int key=0;
    for(auto ch:patt) if (ch!='*') key|=1<<(ch-'a');
    int n;
    cin>>n;
    int cur=-1;
    for(int i=1;i<=n;i++){
        int tmp=0;
        cin>>s;
        bool okay=1;
        for(int j=0;j<m;j++){
            int use=s[j]-'a';
            if (patt[j]=='*'){
                if (key&(1<<use)) okay=0;
                else tmp|=1<<use;
            }else if (use!=patt[j]-'a') okay=0;
        }
        if (okay) {
            if (cur==-1) cur=tmp;
            else cur&=tmp;
        }
    }
    if (cur==-1) cout<<"0";
    else cout<<__builtin_popcount(cur);
}