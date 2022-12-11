#include <bits/stdc++.h>

using namespace std;

const int alp=40;
int n,m;
string s[105];
int h[105];
int f[alp];

int convert(char ch){
    if (ch>='a'&&ch<='z') return ch-'a';
    if (ch>='0'&&ch<='9') return ch-'0'+26;
    return 36;
}
bool match(string s,string dict){
    int n1=s.length();
    if (n1!=dict.length()) return 0;
    for(int i=0;i<n1;i++) if (dict[i]!='?'&&s[i]!=dict[i]) return 0;
    return 1;
}
void solve(){
    string ans;
    int st=1;
    while (!h[st]) st++;
    for(int i=1;i<=n;i++) if (h[i]){
        if (s[i].length()!=s[st].length()){
            printf("No");
            return;
        }
    }
    for(int pos=0;pos<s[st].length();pos++){
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++) if (h[i])
            f[convert(s[i][pos])]=1;
        int n1=count(f,f+alp,1);
//        cout<<n1<<'\n';
        if (n1==1) ans.push_back(s[st][pos]);
        else ans.push_back('?');
    }
    for(int i=1;i<=n;i++) if (!h[i]&&match(s[i],ans)){
        printf("No");
        return;
    }
    printf("Yes\n");
    cout<<ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    while (m--){
        int val;
        cin>>val;
        h[val]=1;
    }
    solve();
}