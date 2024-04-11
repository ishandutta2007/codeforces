#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vint;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvint;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n,m;
  double x;
  cin >> x;
  double eps=0.0001;
  for(int a=1; a<=10; a++)
      for(int h=1;h<=10;h++){
          if(abs(double(a*h)-x*sqrt((double)(a*a+4*h*h)))<eps){
              cout<<a<<" "<<h;
              return 0;

          }

      }




}