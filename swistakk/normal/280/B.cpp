#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001*100];
vector<int> stos;
void odwroc(int n)
{
    for(int i=1; 2*i<=n; i++)
    {
        swap(a[i], a[n-i+1]);
    }
}

int rozw(int n)
{
    int maxi=0;
    stos.clear();
    for(int i=1; i<=n; i++)
    {
        while(!stos.empty() && stos.back()<a[i])
        {
            maxi=max(maxi, stos.back()^a[i]);
            stos.pop_back();
        }
        stos.push_back(a[i]);
    }
    return maxi;
}
        
        
        
        
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    int wynik=rozw(n);
    odwroc(n);
    wynik=max(wynik, rozw(n));
    cout<<wynik<<endl;
    return 0;
}