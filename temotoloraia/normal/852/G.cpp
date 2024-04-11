#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define N 100
#define mod 1000000007
using namespace std;
const LL mo=29;
LL n, m, i, j, k, l, r, t, a[5], ans, fix[N], c[5], k1;
map<pair<LL,LL>,LL>mp, mp1;
string s;
void pas(LL c[5]){
    string s1="";
    LL m=s.size(), i, j, k, k1;
    for(i=0;i<m;i++){
        if(s[i]=='?'){
            if(c[fix[i]]==5)continue;
            s1+=(char)(c[fix[i]]+'a');
        }
        else s1+=s[i];
    }
    k=0;k1=0;
    m=s1.size();
    for(j=0;j<m;j++){
        k*=mo;
        k+=s1[j]-'a'+1;
        k1+=k/mod;
        k1%=mod;
        k%=mod;
    }
    //if(mp[k]){cout<<k<<" "<<mp[k]<<endl;}
    if(!mp1[MP(k1,k)])ans+=mp[MP(k1,k)];
    mp1[MP(k1,k)]=1;
}
void go(LL t, LL n, LL c[5]){
    if(t==n){pas(c);return;}
    t++;
    for(LL i=0;i<6;i++){
        c[t-1]=i;
        go(t,n,c);
    }
}
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>s;
        k=0;
        k1=0;
        for(j=0;j<s.size();j++){
            k*=mo;
            k+=(s[j]-'a'+1);
            k1+=k/mod;
            k%=mod;
            k1%=mod;
        }
        mp[MP(k1,k)]++;
        //cout<<k<<endl;
    }
    //cout<<endl;
    while(m--){
        cin>>s;
        t=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='?'){
                fix[i]=t;
                a[t]=i;t++;
            }
            else fix[i]=-1;
        }
        ans=0;
        mp1.clear();
        go(0,t,c);
        cout<<ans<<endl;
    }
    return 0;
}