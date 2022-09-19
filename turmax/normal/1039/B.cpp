#include <bits/stdc++.h>

using namespace std;
#define int long long
int myrand()
{
    return rand()+((int) rand())*32768+((int) rand())*32768*32768+((int) rand())*32768*32768*32768;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(getpid());
    int n,k;
    cin>>n>>k;
    int l=0;int r=(n-1);
    while(true)
    {
        if((r-l)<=50)
        {
            int x=rand()%(r-l+1)+l;
            cout<<x+1<<" "<<x+1<<endl;
            string s;
            cin>>s;
            if(s=="Yes")
            {
                exit(0);
            }
            if(s=="No")
            {
                l=max(l-k,0LL);r=min(r+k,(n-1));
            }
        }
        else
        {
            int m=(l+r)/2;
            cout<<l+1<<" "<<m+1<<endl;
            string s;
            cin>>s;
            if(s=="Yes")
            {
                r=m;
            }
            else
            {
                l=m;
            }
            l=max(l-k,0LL);r=min(r+k,(n-1));
        }
    }
    return 0;
}