#include<bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int N=4e5+100;

int p[N];

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
        for(int i=1;i<=n;i++)
            cin>>p[i];
        int g=0;
        for(int i=1;i<=n;i++)
            if(p[i]==p[1])
                g++;
            else
                break;
        int s=0;
        for(int i=g+1;i<=n;i++)
            if(s<=g||p[i]==p[i-1])
                s++;
            else
                break;
        int b=0;
        for(int i=g+s+1;i<=n;i++)
            if(p[i]>p[(n+2)/2])
                b++;
            else
                break;
        if(g>0&&s>0&&b>0&&g<s&&g<b&&g+s+b<=n/2)
            cout<<g<<" "<<s<<" "<<b<<"\n";
        else
            cout<<"0 0 0\n";
    }
}