#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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

    cout<<"? ";
    for(int i=1;i<=100;i++)
        cout<<i<<" ";
    cout<<endl;
    int x;
    cin>>x;

    cout<<"? ";
    for(int i=1;i<=100;i++)
        cout<<(i<<7)<<" ";
    cout<<endl;
    int y;
    cin>>y;

    cout<<"! "<<((x&(((1<<7)-1)<<7))|(y&((1<<7)-1)));
}