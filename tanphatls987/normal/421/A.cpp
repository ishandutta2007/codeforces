#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,a,b,i,h[101]={0},tmp;
    cin>>n>>a>>b;
    for(i=0;i<a;i++)
    {
        cin>>tmp;
        h[tmp]=1;
    }
    for(i=0;i<b;i++)
    {
        cin>>tmp;
        h[tmp]=2;
    }
    for(i=1;i<=n;i++) cout<<h[i]<<" ";
}