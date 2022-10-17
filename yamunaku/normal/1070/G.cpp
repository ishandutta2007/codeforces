#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,pair<int,int>>> he(m);
  for(int i=0;i<m;i++){
    cin >> he[i].first >> he[i].second.first;
    he[i].first--;
    he[i].second.second=i;
  }
  sort(he.begin(),he.end());
  // for(int i=0;i<m;i++) cout << he[i].first << " ";
  // cout << endl;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<int> ansl(m),ansr(m);
  vector<int> ans(m);
  int idx=0;
  vector<bool> used(m);
  int mid;
  pair<int,pair<int,int>> p;
  int aidl,aidr;
  int li;
  bool ngflag;
  for(int i=0;i<n;i++){
    p={i,{-1,-1}};
    mid=distance(he.begin(),lower_bound(he.begin(),he.end(),p));
    aidl=aidr=0;
    for(int j=0;j<n;j++) b[j]=a[j];
    for(int j=0;j<m;j++) used[j]=false;
    ngflag=false;
    for(int j=mid-1;j>=0;j--){
      li=he[j].second.first;
      ngflag=false;
      for(int k=he[j].first;k<=i;k++){
        li+=b[k];
        if(li<0){
          ngflag=true;
          break;
        }
      }
      if(!ngflag){
        for(int k=he[j].first;k<=i;k++){
          b[k]=0;
        }
        ansl[aidl]=j;
        aidl++;
        used[j]=true;
      }else{
        if(j==0){
          ngflag=true;
          break;
        }
      }
    }
    if(!ngflag){
      ngflag=false;
      for(int j=mid;j<m;j++){
        li=he[j].second.first;
        ngflag=false;
        for(int k=he[j].first;k>=i;k--){
          li+=b[k];
          if(li<0){
            ngflag=true;
            break;
          }
        }
        if(!ngflag){
          for(int k=he[j].first;k>=i;k--){
            b[k]=0;
          }
          ansr[aidr]=j;
          aidr++;
          used[j]=true;
        }else{
          if(j==m-1){
            ngflag=true;
            break;
          }
        }
      }
      if(!ngflag){
        cout << i+1 << endl;
        idx=0;
        for(int j=0;j<aidl;j++){
          ans[idx]=he[ansl[j]].second.second+1;
          idx++;
        }
        for(int j=0;j<aidr;j++){
          ans[idx]=he[ansr[j]].second.second+1;
          idx++;
        }
        for(int j=0;j<m;j++){
          if(!used[j]){
            ans[idx]=he[j].second.second+1;
            idx++;
          }
        }
        for(int i=0;i<m-1;i++){
          cout << ans[i] << " ";
        }
        cout << ans[m-1] << endl;
        return 0;
      }
    }
    aidl=aidr=0;
    for(int j=0;j<n;j++) b[j]=a[j];
    for(int j=0;j<m;j++) used[j]=false;
    ngflag=false;
    for(int j=mid-1;j>=0;j--){
      li=he[j].second.first;
      ngflag=false;
      for(int k=he[j].first;k<i;k++){
        li+=b[k];
        if(li<0){
          ngflag=true;
          break;
        }
      }
      if(!ngflag){
        for(int k=he[j].first;k<i;k++){
          b[k]=0;
        }
        ansl[aidl]=j;
        aidl++;
        used[j]=true;
      }else{
        if(j==0){
          ngflag=true;
          break;
        }
      }
    }
    if(!ngflag){
      ngflag=false;
      for(int j=mid;j<m;j++){
        li=he[j].second.first;
        ngflag=false;
        for(int k=he[j].first;k>=i;k--){
          li+=b[k];
          if(li<0){
            ngflag=true;
            break;
          }
        }
        if(!ngflag){
          for(int k=he[j].first;k>=i;k--){
            b[k]=0;
          }
          ansr[aidr]=j;
          aidr++;
          used[j]=true;
        }else{
          if(j==m-1){
            ngflag=true;
            break;
          }
        }
      }
      if(!ngflag){
        cout << i+1 << endl;
        idx=0;
        for(int j=0;j<aidr;j++){
          ans[idx]=he[ansr[j]].second.second+1;
          idx++;
        }
        for(int j=0;j<aidl;j++){
          ans[idx]=he[ansl[j]].second.second+1;
          idx++;
        }
        for(int j=0;j<m;j++){
          if(!used[j]){
            ans[idx]=he[j].second.second+1;
            idx++;
          }
        }
        for(int i=0;i<m-1;i++){
          cout << ans[i] << " ";
        }
        cout << ans[m-1] << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}