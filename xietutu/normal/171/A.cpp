#include <iostream>
#include <cstdlib>
using namespace std;
int x,y,s;
int main() {
    cin>>x>>y;
    while (y){
      s=s*10+y%10;
      y/=10;  
    }
    cout<<x+s;
}