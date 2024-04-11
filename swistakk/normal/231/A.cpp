#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int sum, wynik=0, k;
    for(int i=1; i<=n; i++)
    {
        sum=0;
        for(int j=1; j<=3; j++)
        {            cin>>k;
            sum+=k;
        }
        if(sum>=2)
        {
            wynik++;
        }
    }
    cout<<wynik<<endl;
        
    
    
    
    
    
    
    // system("pause");
    return 0;
}