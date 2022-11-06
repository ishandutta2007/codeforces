#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int x, sum = 0;
    for(int i=0; i<5; ++i)
    {
        cin>>x; sum+=x;
    }
    if(sum%5==0 && sum>0)
        cout<<sum/5<<"\n";
    else
        cout<<"-1\n";
    return 0;
}