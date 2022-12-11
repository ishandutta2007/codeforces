#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int alp=26;

int n,m;
string s;
vector <int> v[alp];
int ans[alp];
int h[N];

bool checkleast(int use){
    int clen=0,last=0;
    for(int i=1;i<=n;i++) if (!h[i]){
        clen++;
        if (s[i-1]-'a'==use) last=i;
        if (clen>=m){
            if (i-last>=m) return 0;
            h[last]=1;
            clen=i-last;
        }
    }else clen=0;
    return 1;
}
void solve(){
    for(int i=1;i<=n;i++) v[s[i-1]-'a'].push_back(i);
    for(int use=0;use<alp;use++){
        if (checkleast(use)) break;
        for(auto i:v[use]) h[i]=1;
    }
    for(int i=1;i<=n;i++) if (h[i]) ans[s[i-1]-'a']++;
    for(int i=0;i<alp;i++)
        for(int j=0;j<ans[i];j++) printf("%c",'a'+i);
}
int main(){
    cin>>m>>s;
    n=s.length();
    solve();
}