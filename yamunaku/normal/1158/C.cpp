#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int t;
  cin >> t;
  rep(q,t){
    int n;
    scanf("%d",&n);
    vector<vector<int>> pre(n+1);
    int xx;
    rep(i,n){
      scanf("%d",&xx);
      xx--;
      if(xx!=-2) pre[xx].push_back(i);
    }
    bool ok=true;
    stack<int> st;
    vector<int> ans;
    vector<bool> usd(n+1,false);
    ans.reserve(n+1);
    per(i,n+1){
      if(!st.empty()){
        if(st.top()==i){
          st.pop();
        }
      }
      if(!pre[i].empty()){
        if(!st.empty()){
          if(pre[i].front()<st.top()){
            ok=false;
            goto next;
          }
        }
        if(!usd[i]) ans.push_back(i);
        usd[i]=true;
        rep(k,pre[i].size()){
          st.push(pre[i][k]);
          ans.push_back(pre[i][k]);
          usd[pre[i][k]]=true;
        }
      }
    }
    rep(i,n+1){
      if(!usd[i]){
        ans.push_back(i);
      }
    }
    next:;
    if(ok){
      int now=n;
      vector<int> aaa(n);
      rep(i,n+1){
        if(ans[i]!=n) aaa[ans[i]]=now,now--;
      }
      rep(i,n) printf("%d ",aaa[i]);
      printf("\n");
    }else{
      printf("-1\n");
    }
  }
  return 0;
}