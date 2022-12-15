#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll MN = 5005;
ll n, i, j, ans;
pll pre[MN], suf[MN], tmp;
string s;

int main(){
    cin >> s; n = s.size();
    for(i=0;i+1<n;i+=2){
        if(i) pre[i]=pre[i-2];
        pre[i].second *= (s[i]-'0');
        if(s[i+1]=='+'){
            pre[i].first += pre[i].second;
            if(!pre[i].second) pre[i].first += (s[i]-'0');
            pre[i].second = 0;
        }
        else if(pre[i].second==0) pre[i].second=s[i]-'0';
    }
    pre[n-1].first += pre[n-1].second;
    if(!pre[n-1].second) pre[n-1].first += s[n-1]-'0';
    pre[n-1].second = 0;
    for(i=n-1;i-1>=0;i-=2){
        suf[i]=suf[i+2];
        suf[i].second *= (s[i]-'0');
        if(s[i-1]=='+'){
            suf[i].first += suf[i].second;
            if(!suf[i].second) suf[i].first += s[i]-'0';
            suf[i].second = 0;
        }
        else if(suf[i].second==0) suf[i].second=s[i]-'0';
    }
    suf[0].first += suf[0].second;
    if(!suf[0].second) suf[0].first += s[0]-'0';
    suf[0].second = 0;
    ans = pre[n-1].first+pre[n-1].second;
    for(i=0;i+1<n;i+=2){
        tmp = {0, 0};
        pll tt;
        for(j=i;j<n;j+=2){
            tt = tmp;
            if(tt.second) tt.second *= (s[j]-'0');
            else tt.first += s[j]-'0';
            ll t = 0, g = tt.first+tt.second;
            if(i){
                t += pre[i-2].first;
                if(pre[i-2].second) g *= pre[i-2].second;
            }
            if(j+1<n){
                t += suf[j+2].first;
                if(suf[j+2].second) g *= suf[j+2].second;
            }
            ans = max(ans, t+g);
            if(j+1<n){
                tmp.second *= (s[j]-'0');
                if(s[j+1]=='+'){
                    tmp.first += tmp.second;
                    if(!tmp.second) tmp.first += s[j]-'0';
                    tmp.second = 0;
                }
                else if(tmp.second==0) tmp.second = s[j]-'0';
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}