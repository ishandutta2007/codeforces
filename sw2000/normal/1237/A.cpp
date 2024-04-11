#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a%2==0)
            cout<<a/2<<endl;
        else
        {
            if(cnt==0)
            {
                cout<<a/2<<endl;
                if(a>0)cnt=-1;
                else cnt=1;
            }
            else
            {
                if(cnt==1)
                {
                    if(a>0)cout<<a/2<<endl;
                    else cout<<a/2-1<<endl;
                }
                else
                {
                    if(a>0)cout<<a/2+1<<endl;
                    else cout<<a/2<<endl;
                }
                cnt=0;
            }
        }
    }

    return 0;
}