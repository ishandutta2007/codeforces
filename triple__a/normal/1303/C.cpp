#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
const int st=30;
int t,l,r;
string s;
int a[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        cin>>s;
        int cnt=0;
        for (auto c:s){
            if (vis[c-'a']){
                if (a[cnt+1+st]==c+1-'a'){
                    cnt++;
                }
                else{
                    if (a[cnt-1+st]==c+1-'a'){
                        cnt--;      
                    }
                    else{
                        cout<<"NO"<<endl;
                        goto cont;
                    }
                }
            }
            else{
                vis[c-'a']=1;
                if (a[cnt+1+st]){
                    if (a[cnt-1+st]){
                        cout<<"NO"<<endl;
                        goto cont;
                    }
                    else{
                        a[cnt-1+st]=c-'a'+1; cnt--;
                    }
                }
                else{
                    a[cnt+1+st]=c-'a'+1; cnt++;
                }
            }
        }
        cout<<"YES"<<endl;
        for (int i=0;i<107;++i){
            if (a[i]) cout<<(char)(a[i]+'a'-1);
        }
        for (int i=0;i<26;++i){
            if (!vis[i]) cout<<(char)(i+'a');
        }
        cout<<endl;
        cont:;
    }    
}