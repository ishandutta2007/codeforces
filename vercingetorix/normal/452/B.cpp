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
/*
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
}*/

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
/*   std::vector<std::vector<int>> praz(2001);
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
}*/
  int n,m,k;
//int ans=0;
  cin >> n >> m;
  if(n==0){
	  cout<<0<<" "<<1<<endl;
	  cout<<0<<" "<<m<<endl;
	  cout<<0<<" "<<0<<endl;
	  cout<<0<<" "<<m-1<<endl;
	  return 0;
  }
  if(m==0){
	  cout<<1<<" "<<0<<endl;
	  cout<<n<<" "<<0<<endl;
      cout<<0<<" "<<0<<endl;
	  cout<<n-1<<" "<<0<<endl;
	  return 0;
  }
  if(n>m){
	  double x=std::sqrt((double)(n*n+m*m))+n;
	  double y=2.*std::sqrt((double)(n*n+(m-1)*(m-1)));
	  if(x>y){
		  cout<<0<<" "<<m<<endl;
		  cout<<n<<" "<<0<<endl;
		  cout<<0<<" "<<0<<endl;
		  cout<<n<<" "<<m<<endl;
		  return 0;
	  }
		  cout<<0<<" "<<1<<endl;
		  cout<<n<<" "<<m<<endl;
		  cout<<0<<" "<<0<<endl;
		  cout<<n<<" "<<m-1<<endl;
		  return 0;

  }
  else{
	  double x=std::sqrt((double)(n*n+m*m))+m;
	  double y=2.*std::sqrt((double)(m*m+(n-1)*(n-1)));
	  if(x>y){
		  cout<<0<<" "<<m<<endl;
		  cout<<n<<" "<<0<<endl;
		  cout<<n<<" "<<m<<endl;
		  cout<<0<<" "<<0<<endl;
		  return 0;
	  }
		  cout<<1<<" "<<0<<endl;
		  cout<<n<<" "<<m<<endl;
		  cout<<0<<" "<<0<<endl;
		  cout<<n-1<<" "<<m<<endl;
		  return 0;

  }
//cin>>n>>k;
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