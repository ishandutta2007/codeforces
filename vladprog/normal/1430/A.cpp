#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

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
        if(n%3==0)
            cout<<n/3<<" "<<0<<" "<<0<<"\n";
        else if(n%3==1)
            if(n<7)
                cout<<-1<<"\n";
            else
                cout<<(n-7)/3<<" "<<0<<" "<<1<<"\n";
        else
            if(n<5)
                cout<<-1<<"\n";
            else
                cout<<(n-5)/3<<" "<<1<<" "<<0<<"\n";
    }
}