#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
struct pp{
  string a;
  bool operator<(const pp& cp)const{
    string mn=a+cp.a;
    string ot=cp.a+a;
    return mn<ot;
  }
};
vector<pp> s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  s.resize(n);
  forn(i,n){
    cin>>s[i].a;
  }
  sort(all(s));
  forn(i,n)
    cout<<s[i].a;
  cout<<endl;
  return 0;
}