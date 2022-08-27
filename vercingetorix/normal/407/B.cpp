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

long long a_n_k(int k, int deg){
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

  int n,m,k;
//int ans=0;
  //cin >> a >> k;

cin>>n;
std::vector<int> a(n+1);
std::vector<std::vector<long long>> d(n+1);
for(int i=1;i<=n;i++){
    cin>>a[i];
}
d[1].push_back(1);
d[1].push_back(2);
for(int i=2; i<=n; i++){
    if(a[i]!=i) d[i].push_back((1+d[a[i]][i-a[i]])%mod);
    else d[i].push_back(1);
    if(a[i]!=i) d[i].push_back((2+d[a[i]][i-a[i]])%mod);
    else d[i].push_back(2);
    for(int j=1; j<i;j++){
        if(a[i]!=i) d[j].push_back((d[j][i-j]+d[a[i]][i-a[i]]+2)%mod);
        else d[j].push_back((d[j][i-j]+2)%mod);
    }
}
cout<<d[1][n];
long long ans=1;
//std::string s;
//long long ans=1;
/*for (int i=1; i<=100; i++) cout<<i<<" ";
cout<<endl;
for (int i=1; i<=100; i++) cout<<101-i<<" ";
cout<<endl;
for (int i=1; i<=100; i++) cout<<1<<" ";*/
 // cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}