#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
typedef long long ll;
const ll mod=1000000007;
int g[1000001];

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int numa,numb;
  bool ok=false;
  for(int i=0;i*a<=n;i++){
    if((n-i*a)%b==0){
      ok=true;
      numa=i;numb=(n-i*a)/b;
      break;
      }
    }
  if(!ok){
    cout<<-1<<endl;
    return 0;  
    }
  int now=1;
  rep(i,numa){
    rep(j,a-1){
      cout<<now+j+1<<" ";
      }
    cout<<now<<" ";
    now+=a;
    }
 rep(i,numb){
    rep(j,b-1){
      cout<<now+j+1<<" ";
      }
    cout<<now<<" ";
    now+=b;
    } 
  cout<<endl;
  return 0;    
  }