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
 
  long long a,k;
long long ans=0;
  cin >> a >> k;
  std::vector<int> d;
  long long b=a;
  while(b>0){
      d.push_back(b%10);
      b/=10;
  }
  std::reverse(d.begin(),d.end());
  int i=0;
  int l=d.size();
  while((k>0)&&(i<l)){
      int topmax=d[i];
      int imax=i;
      int m=l;
      if(m>i+k+1) m=i+k+1;
      for(int j=i; j<m;j++){
          if(d[j]>topmax){
              topmax=d[j];
              imax=j;
          }
      }
      if(imax>i){
          for(int j=imax;j>i;j--){
              d[j]=d[j-1];
          }
          d[i]=topmax;
          k-=(imax-i);
      }
     i++;

  }
  for(int i=0; i <l;i++) cout<<d[i];
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}