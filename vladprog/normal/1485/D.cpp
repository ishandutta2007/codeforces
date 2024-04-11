#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int X=720720;
const int Y[17]={0, 720719, 720704, 720639, 720704, 720095, 719424, 718319, 720704, 720639, 710720, 706079, 719424, 692159, 682304, 670095, 720704};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=m;j++)
        {
            int a;
            cin>>a;
            if((i+j)%2)
                cout<<X<<" ";
            else
                cout<<Y[a]<<" ";
        }
}