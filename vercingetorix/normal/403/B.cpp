#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back


std::vector<std::vector<int>> praz(32001);
std::vector<bool> isp(32001,false);
std::vector<int> isbp(32001,1);

std::vector<int> p;
vi a;
std::set<int> b;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif


for(int i=2; i<=32000; i++){
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
  int n,m,k;
//int ans=0;
  //cin >> a >> k;
  k=0;
cin>>n>>m;
int beauty=0;
vvi araz(5001);
vi fa(5001);
vi nodf;
int currnod=0;
//nodf.pb(0);
for(int i=0;i<n;i++){
    int x;
    cin>>x;

    a.pb(x);
}

for(int i=0;i<m;i++){
    int x;
    cin>>x;
    if(x<32000) isbp[x]=-1;
    else b.insert(x);
}

for(int i=0;i<n;i++){
    int cura=a[i];
    int cnt=0;
    int bal=0;
    vi razl;
    while((cnt<p.size())&&(cura>32000)){
        if(cura%p[cnt]==0){
            cura/=p[cnt];
            bal+=isbp[p[cnt]];
        }
        else cnt++;
    }
    if(cura<=32000){
        for(int j=0;j<praz[cura].size();j++) bal+=isbp[praz[cura][j]];
    }
    else{
        if(b.find(cura)!=b.end()) bal--;
        else bal++;
    }
    fa[i]=bal;
    beauty+=bal;
}
int cnb=0;
for(int i=0;i<n;i++){
    int newnod=gcd(currnod,a[i]);
    //nodf.pb(newnod);

    int cura=currnod/newnod;
    if(i==0) cura=newnod;
    int cnt=0;
    int bal=0;
    vi razl;
    while((cnt<p.size())&&(cura>32000)){
        if(cura%p[cnt]==0){
            cura/=p[cnt];
            bal+=isbp[p[cnt]];
        }
        else cnt++;
    }
    if(cura<=32000){
        for(int j=0;j<praz[cura].size();j++) bal+=isbp[praz[cura][j]];
    }
    else{
        if(b.find(cura)!=b.end()) bal--;
        else bal++;
    }
    cnb-=bal;
    if(i==0) cnb=bal;
    nodf.pb(cnb);
    currnod=newnod;

}

int bm=0;
for(int i=n-1; i>=0; i--){
    if(nodf[i]<bm){
        beauty-=(nodf[i]-bm)*(i+1);
        bm=nodf[i];
      
    }
}
cout<<beauty;
  return 0;
}