#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#define uint long long int
#define N 1000005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int a, b, n;
    cin>>a>>b>>n;
    int git=-1;
    for(int i=0; i<10; i++)
    {
        if((10*a+i)%b==0)
        {
            git=10*a+i;
        }
    }
    if(git==-1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<git;
    for(int i=1; i<=n-1; i++)
    {
        cout<<"0";
    }
    cout<<endl;

    return 0;
}