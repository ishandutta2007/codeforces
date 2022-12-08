#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<29;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n;
  cin>>n;
  int a[n];
  string b;
  rep(i,n)cin>>a[i];
  cin>>b;
  vector<int> v;
  v.push_back(a[0]);
  rep(i,n-1){
    if(b[i]=='1'){
      v.push_back(a[i+1]);
      continue;
      }
    if(b[i]=='0'){
      sort(v.begin(),v.end());
      int m=v.size();
      rep(j,m){
        if(v[j]!=2+i-m+j){
          cout<<"NO"<<endl;
          return 0;
          }
        }
      v.clear();
      v.push_back(a[i+1]);
      }
    }
    cout<<"YES"<<endl;
    return 0;
  }