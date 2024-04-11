#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;
const ll mod= 1e9+7;
const int inf=1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int cnt,a[1010101];
void dfs(int k){
  if(a[k]==k)return;
  swap(a[k],a[a[k]]);
  cnt++;
  dfs(k);
  }

int main(){
  int n;
  cin>>n;
  rep(i,n){
    scanf("%d",&a[i]);
    a[i]--;
    }
  rep(i,n)dfs(i);
  if((cnt+n)%2==0)cout<<"Petr"<<endl;
  else cout<<"Um_nik"<<endl;
  return 0;
  }