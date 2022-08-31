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

  int a,b;
  cin>>a>>b;
  for(int i=1; i<a; i++){
      for(int x=i;x<a;x++){
      if((i*i+x*x)==a*a){
          if(((i*b)%a)!=0) continue;
          if(((x*b)%a)!=0) continue;
          int x1=(i*b)/a;
          int i1=(x*b)/a;
          if(x1!=x){
              cout<<"YES"<<endl;
              cout<<0<<" "<<0<<endl;
              cout<<i<<" "<<-x<<endl;
              cout<<i+i1<<" "<<x1-x<<endl;
              return 0;
          }
          if(i1!=i){
              cout<<"YES"<<endl;
              cout<<0<<" "<<0<<endl;
              cout<<i<<" "<<-x<<endl;
              cout<<i-i1<<" "<<-x1-x<<endl;
              return 0;
          }

      }
  }
  }
  cout<<"NO";
//std::vector<int> a;

  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}