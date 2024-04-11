#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

void print(int num,int cnt)
{
    if(cnt<=0)
        return;
    while(cnt--)
        cout<<num<<" ";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int k1=0,k2=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
            k1++;
        else
            k2++;
    }
    if(k2) print(2,1);
    if(k1) print(1,1);
    print(2,k2-1);
    print(1,k1-1);
}