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

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string x;
        cin>>n>>x;
        string a,b;
        bool eq=true;
        for(char c:x)
            if(eq)
            {
                if(c=='2')
                    a+='1',b+='1';
                else if(c=='1')
                    a+='0',b+='1',
                    eq=false;
                else
                    a+='0',b+='0';
            }
            else
            {
                if(c=='2')
                    a+='2',b+='0';
                else if(c=='1')
                    a+='1',b+='0';
                else
                    a+='0',b+='0';
            }
        cout<<a<<"\n"<<b<<"\n";
    }
}