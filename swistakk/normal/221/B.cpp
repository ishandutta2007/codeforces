#include <iostream>
#include <vector>
#define uint long long int
using namespace std;
int dig[15];
vector<int> dz;
int wsp(int n)
{
    while(n)
    {
        if(dig[n%10]==1)
        {
            return 1;
        }
        n/=10;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int x;
    cin>>x;
    int tmp=x;
    while(tmp)
    {
        dig[tmp%10]=1;
        tmp/=10;
    }
    int wynik=0;
    for(int i=1; i*i<=x; i++)
    {
        if(x%i==0)
        {
            if(wsp(i))
            {
                wynik++;
            }
            if(i*i<x)
            {
                dz.push_back(x/i);
            }
        }
    }
    for(int i=0; i<dz.size(); i++)
    {
        wynik+=wsp(dz[i]);
    }
    cout<<wynik<<endl;
    // system("pause");
    return 0;
}