#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;
const ll mod= 1e9+7;
const int inf=1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<"40 50"<<endl;
  rep(j,5){
    rep(i,50)cout<<"A";
    cout<<endl;
    rep(i,50){
      if(i%2==0&&b>1){
        cout<<"B";
        b--;
        }
      else cout<<"A";
      }
    cout<<endl;
    }
    rep(j,5){
    rep(i,50)cout<<"C";
    cout<<endl;
    rep(i,50){
      if(i%2==0&&d>1){
        cout<<"D";
        d--;
        }
      else cout<<"C";
      }
    cout<<endl;
    }
  rep(j,5){
    rep(i,50)cout<<"B";
    cout<<endl;
    rep(i,50){
      if(i%2==0&&a>1){
        cout<<"A";
        a--;
        }
      else cout<<"B";
      }
    cout<<endl;
    }
  rep(j,5){
    rep(i,50)cout<<"D";
    cout<<endl;
    rep(i,50){
      if(i%2==0&&c>1){
        cout<<"C";
        c--;
        }
      else cout<<"D";
      }
    cout<<endl;
    }
  return 0;
  }