#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int PR[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt=0;
    for(int p:PR)
    {
        cout<<p<<endl;
        string resp;
        cin>>resp;
        if(resp=="yes")
        {
            cnt++;
            if(cnt==2)
                cout<<"composite"<<endl,exit(0);
            if(p*p<=100)
            {
                cout<<p*p<<endl;
                cin>>resp;
                if(resp=="yes")
                    cout<<"composite"<<endl,exit(0);
            }
        }
    }
    cout<<"prime"<<endl;
}