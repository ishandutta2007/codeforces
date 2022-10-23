#include<bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
#define endl "\n"
#define MP make_pair
#define fi first
#define se second
using ll=long long;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll t;cin>>t;
  while(t--){
    ll n;cin>>n;
    vector<ll>ret(n,2e9);
    vector<ll>l(n),r(n),c(n);
    rep(i,0,n){
      cin>>l[i]>>r[i]>>c[i];

    }
    rep(_,0,2){
      vector<int>o1(n),o2(n);
      iota(ALL(o1),0);
      iota(ALL(o2),0);
      sort(ALL(o1),[&](int i,int j){return l[i]<l[j];});
      sort(ALL(o2),[&](int i,int j){return r[i]<r[j];});
      int idx=0;
      using P=pair<ll,ll>;
      pair<P,P>rmx(MP(-2e9,-1),MP(-2e9,-2));
      auto upd=[&](pair<P,P>&x,P y){
        if(x.fi.se==y.se)chmax(x.fi.fi,y.fi);
        else if(x.fi.fi<y.fi){
          x.se=x.fi;
          x.fi=y;
        }
        else{
          chmax(x.se,y);
        }
      };
      auto get=[&](int cc){
        if(cc==rmx.fi.se)return rmx.se.fi;
        return rmx.fi.fi;
      };
      for(auto i:o1){
        while(idx<n&&r[o2[idx]]<l[i]){
          int k=o2[idx];
          //cout<<"E" spa r.size() spa o2.size() spa idx spa k<<endl;
          chmin(ret[k],max(0LL,l[k]-get(c[k])));
          //cout<<"ok"<<endl;
          idx++;
        }
        upd(rmx,MP(r[i],c[i]));
        chmin(ret[i],max(0LL,l[i]-get(c[i])));
      }
      while(idx<n){
        int k=o2[idx];
        chmin(ret[k],max(0LL,l[k]-get(c[k])));
        idx++;
      }
      rep(i,0,n){
        l[i]*=-1;
        r[i]*=-1;
        swap(l[i],r[i]);

      }
    }
    rep(i,0,n){
      cout<<ret[i];
      if(i==n-1)cout<<endl;
      else cout<<" ";
    }
  }
  return 0;
}