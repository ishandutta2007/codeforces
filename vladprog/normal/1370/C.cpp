#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool prime(int x)
{
    if(x==1)
        return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}

bool powtwo(int x)
{
    return !(x&(x-1));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
            cout<<"FastestFinger\n";
        else if(n%2||n==2)
            cout<<"Ashishgup\n";
        else if(prime(n/2)||powtwo(n))
            cout<<"FastestFinger\n";
        else
            cout<<"Ashishgup\n";
    }
}