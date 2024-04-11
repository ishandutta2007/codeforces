#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const long long mod = 1000000007;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);

}

long long go(int k, int deg){
    long long ans=1;
    long long denom=1;
    for(int i=1; i<=deg; i++) denom*=i;
    for(long long j=k;j<=(k+deg-1);j++){
        long long c=gcd(j,denom);
        denom/=c;
        ans=(ans*(j/c))%mod;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
   std::vector<std::vector<int>> praz(2001);
std::vector<bool> isp(2001,false);
std::vector<int> p;
for(int i=2; i<=2000; i++){
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

cin>>n>>k;
long long ans=1;
for(int i=2;i<=n;i++){
    std::sort(praz[i].begin(),praz[i].end());
    int ptr=0;
    std::vector<int> degs;
    int s=praz[i].size();
    while(ptr<s){
        int curp=praz[i][ptr];
        int deg=0;
        while((ptr<s)&&(praz[i][ptr]==curp)){
            deg++;
            ptr++;
        }
        degs.push_back(deg);
    }
    long long curans=1;
    for(int j=0; j<degs.size();j++){
        
        int deg=degs[j];
        long long curdegans=go(k,deg);
        curans=(curans*curdegans)%mod;

    }
    ans=(ans+curans)%mod;

}
//std::string s;
//long long ans=1;
/*for (int i=1; i<=100; i++) cout<<i<<" ";
cout<<endl;
for (int i=1; i<=100; i++) cout<<101-i<<" ";
cout<<endl;
for (int i=1; i<=100; i++) cout<<1<<" ";*/
  cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}