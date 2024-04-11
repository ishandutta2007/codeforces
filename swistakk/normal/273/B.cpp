#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define N 200007
#define M 1000000007
#define uint long long int
using namespace std;
uint fact[N];
uint pot[N];
pair<int, int> pkt[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    fact[0]=1;
    pot[0]=1;
    int a;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        pkt[i]=make_pair(a, i);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        pkt[i+n]=make_pair(a, i);
    }
    int m;
    cin>>m;
    for(int i=1; i<=2*n; i++)
    {
        pot[i]=2*pot[i-1]%m;
        if(i%2==0)
        {
            fact[i]=(i/2)*fact[i-1]%m;
        }
        else
        {
            fact[i]=i*fact[i-1]%m;
        }
    }
    sort(pkt+1, pkt+1+2*n);
    
    uint odp=1;
    int wsk1=1;
    int wsk2=1;
    int tsame;
    while(wsk1<=2*n)
    {
        tsame=0;
        wsk2=wsk1;
        while(wsk2<2*n && pkt[wsk1].first==pkt[wsk2+1].first)
        {
            if(pkt[wsk2].second==pkt[wsk2+1].second)
            {
                tsame++;
            }
            wsk2++;
        }
        odp*=fact[wsk2-wsk1+1]%m*pot[(wsk2-wsk1+1)/2-tsame]%m;
        odp%=m;
        wsk1=wsk2+1;
    }
    cout<<odp<<endl;
    return 0;
}