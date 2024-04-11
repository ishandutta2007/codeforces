#include <bits/stdc++.h>

using namespace std;
 
#define ll long long
#define ar array
 
#define fi first
#define se second

const int maxn = 1e5 + 7;

int a[maxn];
int cnt[maxn];
bool prime[maxn];
vector <int> val[maxn];
int arr[maxn];

void gao(int x){
  int lim = (1<<val[x].size());
  for (int mask=0;mask<lim;mask++){
    int ret=1;
    for (int i=0;i<val[x].size();i++){
      if ((mask>>i)&1) {
        ret*=val[x][i];
      }
    }
    arr[ret]++;
  }
}

void ungao(int x){
  int lim = (1<<val[x].size());
  for (int mask=0;mask<lim;mask++){
    int ret=1;
    for (int i=0;i<val[x].size();i++){
      if ((mask>>i)&1) {
        ret*=val[x][i];
      }
    }
    arr[ret]--;
  }
}

int check(int x){
  int ans = 0;
  int lim = (1<<val[x].size());
  for (int mask=0;mask<lim;mask++) {
    int ret = 1;
    for (int i = 0; i < val[x].size(); i++) {
      if((mask>>i)&1) {
        ret*=val[x][i];
      }
    }
    ans+=arr[ret]*(__builtin_popcount(mask) % 2 ? -1 : 1);
  }
  return ans;
}

ll func(vector <int> a){
  sort(a.rbegin(),a.rend());
  ll ret = 0;
  int j = -1;
  for (int i = 0;i<a.size();i++){
    int x = a[i];
    if (j == -1 && i){
      if (check(x)){
        j = i - 1;
      }
    }
    if (j!=-1){
      while (j-1>=0){
        ungao(a[j]);
        if(check(x)){
          j--;
        }else{
          gao(a[j]);
          break;
        }
      }
      ret=max(ret,a[j]*(ll)a[i]);
    }
    if(j == -1){
      gao(x);
    }
  }
  if(j==-1)j=(int)a.size()-1;
  for(int i=0;i<=j;i++){
    ungao(a[i]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i=2;i<maxn;i++){
    prime[i] = true;
  }
  for (int i=2;i<maxn;i++){
    if (prime[i]){
      for(int j=i;j<maxn;j+=i){
        prime[j]=false;
        val[j].push_back(i);
      }
    }
  }
  int n;
  cin>>n;
  for (int i = 0; i < n;i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i < maxn; i++){
    cnt[i]=min(cnt[i],2);
  }
  ll ans = 0;
  for (int i = 1;i<maxn;i++){
    vector <int> piu;
    for (int j = i; j<maxn; j += i){
      for (int t = 0; t < cnt[j]; t++){
        piu.push_back(j / i);
      }
    }
    ans = max(ans,func(piu)*(ll)i);
  }
  cout << ans << endl;
}