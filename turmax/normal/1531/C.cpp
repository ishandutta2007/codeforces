#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n==2) {cout<<(-1);return 0;}
    for(int sz=1;;++sz)
    {
        if(sz*sz>=n && sz*sz!=(n+2))
        {
            int res[sz][sz];
            for(int i=0;i<sz;++i) for(int j=0;j<sz;++j) res[i][j]=1;
            if(n==sz*sz)
            {
            }
            else if((sz*sz)%2!=(n%2))
            {
                if(n>=(sz-1)*(sz-1))
                {
                     res[sz-1][sz-1]=0;
                     int h=(sz*sz-n-1)/2;
                     for(int i=(sz-2);i>(sz-2-h);--i) res[sz-1][i]=0;
                     for(int i=(sz-2);i>(sz-2-h);--i) res[i][sz-1]=0;
                }
                else
                {
                    for(int i=(sz-3);i<sz;++i)
                    {
                        for(int j=(sz-3);j<sz;++j)
                        {
                            res[i][j]=0;
                        }
                    }
                    int h=(sz*sz-n-9)/2;
                    for(int i=(sz-4);i>(sz-4-h);--i) res[sz-1][i]=0;
                    for(int i=(sz-4);i>(sz-4-h);--i) res[i][sz-1]=0;
                }
            }
            else if((sz*sz)%2==(n%2))
            {
                {
                     for(int i=(sz-2);i<sz;++i)
                     {
                         for(int j=(sz-2);j<sz;++j)
                         {
                             res[i][j]=0;
                         }
                     }
                     int h=(sz*sz-n-4)/2;
                     for(int i=(sz-3);i>(sz-3-h);--i) res[sz-1][i]=0;
                     for(int i=(sz-3);i>(sz-3-h);--i) res[i][sz-1]=0;
                }
            }
            cout<<sz<<endl;
            for(int i=0;i<sz;++i) {for(int j=0;j<sz;++j)
            {
                if(res[sz-i-1][j]==1) cout<<'o';
                else cout<<'.';
            }
            cout<<endl;
            }
            return 0;
        }
    }
    return 0;
}