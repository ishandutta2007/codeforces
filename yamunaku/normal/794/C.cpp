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
  string s,t;
  cin >> s >> t;
  int n=s.length();
  vector<int> a(n),b(n),ans(n);
  for(int i=0;i<n;i++){
    a[i]=s[i]-'a';
    b[i]=t[i]-'a';
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end(),greater<int>());
  int na=0,nb=0,nna,nnb;
  for(int i=0;i<n;i++){
    if(i%2==0){
      if(a[na]>=b[nb]){
        nna=(n-na-nb+1)/2+na;
        nnb=(n-na-nb)/2+nb;
        na=nb=0;
        for(int j=n-1;j>=i;j--){
          if((n-1-j)%2==0){
            ans[j]=a[nna-na-1];
            na++;
          }else{
            ans[j]=b[nnb-nb-1];
            nb++;
          }
        }
        break;
      }else{
        ans[i]=a[na];
        na++;
      }
    }else{
      if(a[na]>=b[nb]){
        nna=(n-na-nb)/2+na;
        nnb=(n-na-nb+1)/2+nb;
        na=nb=0;
        for(int j=n-1;j>=i;j--){
          if((n-1-j)%2==1){
            ans[j]=a[nna-na-1];
            na++;
          }else{
            ans[j]=b[nnb-nb-1];
            nb++;
          }
        }
        break;
      }else{
        ans[i]=b[nb];
        nb++;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << (char)('a'+ans[i]);
  }
  cout << endl;
  return 0;
}