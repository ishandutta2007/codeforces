#include<bits/stdc++.h>
#include<random>
#include<chrono>
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

ll n,k;

bool guess(ll l,ll r){
    cout<<l<<" "<<r<<endl;
    string s;
    cin>>s;
    if (s[0]=='Y') return 1;
    return 0;
}

void rg(ll l,ll r){
    ll gp=r-l+1;
    ll rd=rng()%gp+l;
    if (guess(rd,rd)){
        exit(0);
    }
}

void mid_search(ll l,ll r,ll th){
    if (r-l<th){
        rg(l,r);
        mid_search(max(1LL,l-k),min(r+k,n),th);
    }
    ll md=(l+r)>>1;
    if (guess(l,md)){
        mid_search(max(1LL,l-k),min(md+k,n),th);
    }
    else{
        mid_search(max(1LL,md+1-k),min(r+k,n),th);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    mid_search(1,n,40);
    return 0;
}