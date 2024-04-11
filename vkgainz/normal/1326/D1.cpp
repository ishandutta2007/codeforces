#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll hash, mod = 998244353;
ll mult = 203;
void solve(){
    string s; cin >> s;
    int l = 0;
    int r = s.length()-1;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            break;
        }
    }
    if(l>=r){
        cout << s << endl;
        return;
    }
    ll p[] = {23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    ll hash1 = 0;
    ll hash2 = 0;
    int best = 0;
    ll next= 1;
    bool startLeft = true;
    for(int i=l;i<=r;i++){
        hash2 = (hash2*mult+p[s[i]-'a'])%mod;
        hash1 = (hash1+next*p[s[i]-'a'])%mod;
        if(hash1<0) hash1+=mod;
        if(hash2<0) hash2+=mod;
        next*=mult;
        next%=mod;
        if(hash1==hash2){
            best = max(best,i-l+1);
        }
    }
    hash1 = 0;
    hash2 = 0;
    next = 1;
    for(int i=r;i>=l;i--){
        hash2 = (hash2*mult+p[s[i]-'a'])%mod;
        hash1 = (hash1+next*p[s[i]-'a'])%mod;
        if(hash1<0) hash1+=mod;
        if(hash2<0) hash2+=mod;
        next*=mult;
        next%=mod;
        if(hash1==hash2){
            if(r-i+1>best){
                best = r-i+1;
                startLeft = false;
            }
        }

    }
    string mid = "";
    if(startLeft){
        mid = s.substr(l,best);
    }
    else{
        mid = s.substr(r-best+1,best);
    }
    cout << s.substr(0,l)+mid+s.substr(r+1,s.length()-r) << endl;
    
    
    
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}