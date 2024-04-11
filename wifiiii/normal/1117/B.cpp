#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll M1=0,M2=0;
    for(int i=1;i<=n;++i)
    {
        int temp;cin>>temp;
        if(temp>M1) M2=M1,M1=temp;
        else if(temp>M2) M2=temp;
    }
    ll ans = m/(k+1)*(k*M1+M2) + m%(k+1)*M1;
    cout << ans << endl;
}