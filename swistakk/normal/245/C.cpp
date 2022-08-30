#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#define uint long long int
using namespace std;
int ile[105];
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(n%2==0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>ile[i];
    }
    int suma=0;
    for(int i=n; i>=2; i--)
    {
        if(ile[i]>0)
        {
            if(i%2==1)
            {
                suma+=ile[i];
                ile[i-1]-=ile[i];
                ile[i/2]-=ile[i];
            }
            if(i%2==0)
            {
                suma+=ile[i];
                ile[i/2]-=ile[i];
            }
        }
    }
                
            
            
    cout<<suma+max(ile[1], 0)<<endl;
    // system("pause");
    return 0;
}