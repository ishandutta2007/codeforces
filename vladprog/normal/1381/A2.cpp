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
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int> ans;
        int fir=0,las=n-1;
        bool inv=false;
        while(true)
        {
            if((a[las]!=b[abs(las-fir)])^inv)
            {
                if(a[fir]!=a[las])
                {
                    ans.push_back(1);
                    a[fir]='1'-a[fir]+'0';
                }
                ans.push_back(abs(las-fir)+1);
                swap(fir,las);
                inv=!inv;
            }
            if(las>fir)
                las--;
            else if(las<fir)
                las++;
            else
                break;
        }
        cout<<ans.size()<<"\n";
        for(int p:ans)
            cout<<p<<" ";
        cout<<"\n";
    }
}