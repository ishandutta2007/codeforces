#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
        cin>>c[i],c[i]--;
    vector<int> a[n];
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++)
            cin>>a[i][j],a[i][j]--;
    }
    int ans[3];
    for(int i=0;i<3;i++)
    {
        bool u[n]={};
        int t=i,res=0,k=0;
        while(true)
        {
            bool OK=false;
            for(int j=0;j<n;j++)
            {
                if(c[j]!=t||u[j])
                    continue;
                bool ok=true;
                for(int z:a[j])
                    if(!u[z])
                    {
                        ok=false;
                        break;
                    }
                if(ok)
                {
                    u[j]=true;
                    k++;
                    OK=true;
                    break;
                }
            }
            if(k==n)
                break;
            if(!OK)
                t=(t+1)%3,res++;
        }
        ans[i]=res+n;
    }
    cout<<*min_element(ans,ans+3);
}