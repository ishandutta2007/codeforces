#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
std::vector<std::vector<int>> praz(100001);

bool isprim(int u, int n){
  int s=praz[n-1].size();
  for(int i=0;i<s;i++){
    if(i>0) if(praz[n-1][i]==praz[n-1][i-1]) continue;
    int deg=(n-1)/praz[n-1][i];
    vb f(20,false);
    int j=0;
    while(deg>0){
      if(deg%2==1) f[j]=true;
      j++;
      deg/=2;
    }
    ll st=u;
    ll pr=1;
    for(int k=0;k<j; k++){
      if(f[k]) pr=(pr*st)%n;
      st=(st*st)%n;
    }
    if(pr==1) return false;
  }
  return true;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

std::vector<bool> isp(100001,false);

std::vector<int> p;
for(int i=2; i<=100000; i++){
    bool f=false;
    for(int j=0; j<p.size();j++) if(i%p[j]==0){
        f=true;
       
        for(int k=0; k<praz[i/p[j]].size();k++) praz[i].push_back(praz[i/p[j]][k]);
        praz[i].push_back(p[j]);
        break;
    }
    if(f) continue;
    p.push_back(i);
    isp[i]=true;
    praz[i].push_back(i);
}

int ans=0;
int n;
cin >> n;
if(n==1){
  cout<<"YES"<<endl<<1;
  return 0;
}
if(n==2){
  cout<<"YES"<<endl<<1<<endl<<2;
  return 0;
}
if(n==4){
  cout<<"YES"<<endl<<1<<endl<<3<<endl<<2<<endl<<4;
  return 0;
}
if(!isp[n]){
  cout<<"NO";
  return 0;
}
sort(praz[n-1].begin(), praz[n-1].end());

ll prim;
for(int i= 2; i<=n-1;i++){
  
  if(isprim(i,n)) {
    prim=i;
    break;
  }
}

vi primdeg(n);
vi primlog(n);
ll pr=prim;
primdeg[0]=1;
primlog[0]=0;
for(int i=1; i<n;i++){
  primdeg[i]=pr;
  primlog[pr]=i;
  pr=(pr*prim)%n;
}
vi v(n);
cout<<"YES"<<endl;
int m=n-1;
    int x=1;
    v[0]=0;
    for(int i=1;i<m/2;i++){
      x*=-1;
      int a=i;
      if (x<0) a=m-i;
      v[i]=a;
    }
    v[m/2]=m/2;
    for(int i=1;i<m/2;i++) v[i+m/2]=m-v[m/2-i];
for(int i=0;i<n-1;i++){
  cout<<primdeg[v[i]]<<endl;
}
cout<<n;
return 0;


}