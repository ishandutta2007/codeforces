#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

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
  std::string s;
  std::string pre;
  std::string suf;
  
  int n,m,k;
  m=0;
 int ans=200000000;
 int thres=10000;
 //cin >> n>> m >> k;
 cin>>n;
 long long sum=0;
 std::vector<long long> csum;
 for(int i=0; i<n; i++){
     long long x;
     cin>>x;
     sum+=x;
     csum.push_back(sum);
     
     int st=min(i,thres);
     for(int j=1; j<=st; j++){
         int a=abs(sum-csum[i-j]);
         if(a>thres) continue;
         int b=a*a+j*j;
         if(ans>b) {
             ans=b;
             thres=(int)floor(sqrt((double)ans));
         }

     }
 }

cout<<ans;
  return 0;
}