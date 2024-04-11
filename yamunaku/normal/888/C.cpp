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
  string s;
  cin >> s;
  int n=s.length();
  int l=0,r=n,mid;
  while(r-l>1){
    mid=(l+r)/2;
    vector<int> ok(26,1),count(26,0);
    // cout << mid << endl;
    for(int i=0;i<mid;i++){
      count[s[i]-'a']++;
    }
    for(int i=mid;i<n;i++){
      for(int i=0;i<26;i++){
        if(count[i]==0) ok[i]=0;
      }
      count[s[i]-'a']++;
      count[s[i-mid]-'a']--;
    }
    for(int i=0;i<26;i++){
      if(count[i]==0) ok[i]=0;
    }
    // for(int i=0;i<26;i++) cout << ok[i] << endl;
    bool okflag=false;
    for(int i=0;i<26;i++) okflag|=ok[i];
    if(okflag) r=mid;
    else l=mid;
  }
  cout << r << endl;
  return 0;
}