#include <iostream>
#include <algorithm>
using namespace std;
long long a,b,x,y;
int main(){
    cin>>a>>b>>x>>y;
    long long ans=__gcd(x,y);
    cout<<min(a/(x/ans),b/(y/ans));
    return 0;
}