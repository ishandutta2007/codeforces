#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  long long n,m,k;
  cin>>n>>m>>k;

//std::vector<int> a;
std::string s;
long long ans=0;
long long a;
if(k>(n+m-2)){
    cout<<-1;
    return 0;

}
long long x;
if(n>m){
    x=m;
    m=n;
    n=x;
}

/*long long r=m-n;
if((m-n)>=k){
    ans=(m-k)*n;
}
else if(((k-r)%2)==0){
    ans=(n-(k-r)/2)*(n-(k-r)/2);
}
else{
    ans=(n-(k-r)/2)*(n-(k-r)/2-1);
}*/
if(k>(m-1)){
    a=(m)/(k-n+2);
    if(a>ans) ans=a;
    a=(n)/(k-m+2);
    if(a>ans) ans=a;
    cout<<ans;
    return 0;
}
if(k>(n-1)){
    ans=n*(m/(k+1));
    cout<<ans;
    return 0;
}
a=m*(n/(k+1));
if(a>ans) ans=a;
a=n*(m/(k+1));
if(a>ans) ans=a;
cout<<ans;
return 0;
//long long k1=
//long long k2=

//char c;

cout<< ans;
  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}