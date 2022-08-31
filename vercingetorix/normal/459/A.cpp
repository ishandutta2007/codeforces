#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int x1,x2,y1,y2;
cin>>x1>>y1>>x2>>y2;
if(x1>x2){
    int a;
    a=x2;
    x2=x1;
    x1=a;
    a=y2;
    y2=y1;
    y1=a;
}
if(x1==x2){
    cout<<x1+y2-y1<<" "<<y1<<" "<<x1+y2-y1<<" "<<y2;
    return 0;
}
if(y1==y2){
    cout<<x1<<" "<<y1+x2-x1<<" "<<x2<<" "<<y2+x2-x1;
    return 0;
}
if((x2-x1)!=abs(y2-y1)){
    cout<<-1;
    return 0;
}
cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;

  return 0;
}