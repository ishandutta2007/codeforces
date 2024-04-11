#include<bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa <<" "<<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
using ll=long long;
template<typename T1,typename T2>
bool chmin(T1 &a,T2 b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}
template<typename T1,typename T2>
bool chmax(T1 &a,T2 b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>p(n),q(n);
        rep(i,0,n){
            cin>>p[i];
            q[p[i]]=i;
        }
        ll l=q[0],r=q[0];
        ll ret=0;
        rep(i,0,n){
            ll nxt=-1;
            if(i!=n-1)nxt=q[i+1];
            if(l>nxt||r<nxt){
                ll nl=l-(nxt>r?-1:nxt)-1;
                ll nr=(nxt<l?n:nxt)-r-1;
                ll m=i+1-(r-l+1-(i+1));
                //lv+rv<=m
                if(nxt>r)swap(nl,nr);
                rep(lv,0,nl+1){
                    ret+=max(0LL,min(nr,m-lv)+1);
                }
            }
            chmin(l,nxt);
            chmax(r,nxt);
        }
        cout<<ret<<endl;
    }
}