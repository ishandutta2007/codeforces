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
        int d,k;
        cin>>d>>k;
        int x=d/sqrt(2)/k;
        while((x+1)*(x+1)*k*k*2<d*d)
            x++;
        if(x*x*k*k+(x+1)*(x+1)*k*k<=d*d)
            cout<<"Ashish\n";
        else
            cout<<"Utkarsh\n";
    }
}