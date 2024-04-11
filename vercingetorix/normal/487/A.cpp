#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
int am,hm,dm,ay,hy,dy;
int dmg;
int h,a,d;
ll go(int hit){
 
  ll ans3=-1;
  ll sum2=0;
  int dmg2=dmg;
  while(dmg2>0){
    ll hp;
    int mdead = (hm-1)/hit + 1;
    int ydead = (hy-1)/dmg2 +1;
    if(ydead>mdead)  hp=0;
    else hp=(mdead*dmg2+1-hy)*h;
    if((ans3==-1)||((sum2+hp)<ans3)) ans3=sum2+hp;
    dmg2--;
    sum2+=d;
  }
  if(sum2<ans3) ans3=sum2;
  return ans3;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int m,n,t,p;
  

  cin>>hy>>ay>>dy;
  cin>>hm>>am>>dm;
  cin>>h>>a>>d;
  int hit = ay-dm;
  dmg = am-dy;
  ll sum =0;
  while(hit<1){
    hit++;
    sum+=a;
  }
  if(dmg<1){
    cout<<sum;
    return 0;
  }
  
  ll ans = -1;
  while(hit<=hm){
    ll ans2=go(hit);
    if(((sum+ans2)<ans)||ans==-1) ans=sum+ans2;
    
    sum+=a;
    hit++;
  }
  cout<<ans;
  //std::string s1,s2;
  //cin>>n;
  
  return 0;
}