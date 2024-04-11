#include <bits/stdc++.h>

using namespace std;


const int N=8e3+10;
const int inf=1e9+10;


int f[N],pre[N][N];
int nlen[N];
int h[N];
string s;
int main(){
    cin>>s;
    int n=s.length();
    for(int en=1;en<=n;en++)
        for(int st=1;st<=n;st++)
            if (s[st-1]==s[en-1]) pre[st][en]=pre[st-1][en-1]+1;
            else pre[st][en]=0;
    for(int i=1;i<=n;i++) nlen[i]=nlen[i/10]+1;


    for(int en=1;en<=n;en++){

        f[en]=inf;
        for(int len=1;len<=en;len++) f[en]=min(f[en],f[en-len]+len+1);

        memset(h,0,sizeof(h));
        for(int len=1;len<=en;len++){
            for(int st=en-len;st>=len;st-=len) {
                if (pre[st][en]<len) break;
                if (h[st-len]) break;
                h[st-len]=1;
                f[en]=min(f[en],f[st-len]+len+nlen[(en-st)/len+1]);
            }
        }
//        cout<<en<<" "<<f[en]<<'\n';
    }
    cout<<f[n];
}