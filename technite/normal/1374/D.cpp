#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        map<long long,long long> m;
        long long mx=0;
        long long index=0;
        for(long long i=0;i<n;i++)
        {
            long long a;
            cin>>a;
            long long rem=a%k;
            if(rem!=0)
            {
                long long b=k-rem;
                m[b]++;
                if(m[b]==mx)index=max(index,b);
                else if(m[b]>mx)
                {
                    index=b;
                    mx=m[b];
                }
                
            }
        }
        if(mx==0) cout<<0<<'\n';
        else
        cout<<(mx-1)*k+index+1<<'\n';
    }

}