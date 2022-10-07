#include <iostream>
using namespace std;
int n,ans;
void f(int x)
{
    if(x>n)   
return ;
    ans++;
    f(10*x);  
f(10*x+1);
}
int main()
{
    cin>>n;
    f(1);
    cout<<ans;
}