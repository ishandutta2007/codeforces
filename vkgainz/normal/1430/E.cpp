#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int seg[400005];
int n;
void upd(int i){
    seg[i+=n]++;
    while(i>1) {
        i/=2;
        seg[i] = seg[2*i]+seg[2*i+1];
    }
}
int query(int l,int r) {
    l+=n, r+=n;
    int res = 0;
    while(l<r) {
        if(l%2) res+=seg[l++];
        if(r%2) res+=seg[--r];
        l/=2, r/=2;
    }
    return res;
}

int main(){ 
    cin >> n;
    string s; cin >> s;
    string t = s;
    reverse(t.begin(),t.end());
    int posEnd[n];
    vector<int> posCurr[26];
    for(int i=0;i<n;i++) {
        posCurr[t[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++) reverse(posCurr[i].begin(),posCurr[i].end());
    for(int i=0;i<n;i++) {
        posEnd[i] = posCurr[s[i]-'a'][posCurr[s[i]-'a'].size()-1];
        posCurr[s[i]-'a'].pop_back();
    }
    int ord[n];
    for(int i=0;i<n;i++) ord[posEnd[i]] = i;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        int effectivePos = ord[i]+query(ord[i],n);
        ans+=effectivePos-i;
        upd(ord[i]);
    }
    cout << ans << endl;
}