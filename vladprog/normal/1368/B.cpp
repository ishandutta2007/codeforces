#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const string s="codeforces";

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>k;
    for(int x=1;x<=40;x++)
    {
        int res=1;
        for(int _=1;_<=10;_++)
            res*=x;
        if(res<k)
            continue;
        for(int y=1;y<=10;y++)
        {
            int res=1;
            for(int _=1;_<=y;_++)
                res*=x;
            for(int _=1;_<=10-y;_++)
                res*=x-1;
            if(res<k)
                continue;
            for(int i=0;i<y;i++)
                cout<<string(x,s[i]);
            for(int i=y;i<10;i++)
                cout<<string(x-1,s[i]);
            exit(0);
        }
    }

}