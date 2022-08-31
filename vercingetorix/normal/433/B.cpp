#include <iostream>
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
 
  int n;
int ans=0;
  cin >> n;
  std::vector<long long> v;
  std::vector<long long> csum;
  std::vector<long long> csumsort;
  csum.push_back(0);
  csumsort.push_back(0);
  long long sum=0;
  for(int i=0; i<n; i++){
	  long x;
	  cin>> x;
	  sum+=x;
	  v.push_back(x);
	  csum.push_back(sum);

  }
  std::sort(v.begin(),v.end());
  sum=0;
  for(int i=0; i<n; i++){
	  sum+=v[i];
	  csumsort.push_back(sum);

  }
 
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
	  int t,l,r;
	  cin>>t>>l>>r;
	  if(t==1) cout<<(csum[r]-csum[l-1])<<endl;
	  else cout<<(csumsort[r]-csumsort[l-1])<<endl;

  }


  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}