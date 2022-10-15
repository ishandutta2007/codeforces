#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
int t,n;
bool vis[maxn];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>s;
        n=s.size();
        int ans=0;
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;++i){
            if (s[i]=='1') break;
            vis[i]=1;
        }
        for (int i=n-1;i>-1;--i){
            if (s[i]=='1') break;
            vis[i]=1;
        }
        for (int i=0;i<n;++i){
            if (s[i]=='0'&&!vis[i]) ans++; 
        }
        cout<<ans<<endl;
    }
}