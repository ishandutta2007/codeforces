#include<bits/stdc++.h>
#define maxn 200001
using namespace std;
string s,t;
int pre[maxn];
int suf[maxn];
int main(){
    cin>>s>>t;
    int slen=s.length(),tlen=t.length();
    for(int i=0,j=0;i<slen;++i){
        if(j<tlen&&s[i]==t[j]) ++j;
        pre[i]=j;
    }
    for(int i=slen-1,j=tlen-1;i>=0;--i){
        if(j>=0&&s[i]==t[j]) --j;
        suf[i]=j;
    }
    suf[slen]=tlen-1;
    int ans=0;
    for(int i=0,j=0,tmp=0;i<=slen;++i){
        while(j<=slen&&tmp>=suf[j]+1) ++j;
        ans=max(ans,j-i-1);
        tmp=pre[i];
    }
    cout<<ans<<endl;
    return 0;
}