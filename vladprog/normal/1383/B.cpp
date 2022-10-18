#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

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
        int x=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            x^=a[i];
        if(x==0)
        {
            cout<<"DRAW\n";
            continue;
        }
        int bit=0;
        for(int i=1;i<=x;i<<=1)
            if(x&i)
                bit=i;
        int one=0,zero=0;
        for(int i=1;i<=n;i++)
            if(a[i]&bit)
                one++;
            else
                zero++;
        if(one%4==1||zero%2==1)
            cout<<"WIN\n";
        else
            cout<<"LOSE\n";
    }
}