#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#define uint long long int
using namespace std;
int n, m;
uint spot(uint a, uint pot)
{
    uint tmp=a;
    uint akt=1;
    while(pot)
    {
        if(pot%2==1)
        {
            akt*=tmp;
            akt%=m;
        }
        tmp*=tmp;
        tmp%=m;
        pot/=2;
    }
    return akt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    // int n, m;
    cin>>n>>m;
    cout<<(spot(3, n)+m-1)%m<<endl;
    
    
    
    
    
    
    
    return 0;
}