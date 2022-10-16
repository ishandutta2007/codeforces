#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> count(20,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int j=0;
        while(a!=0)
        {
            if(a%2==1) count[j]++;
            j++;
            a/=2;
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        long long val=0;
        for(int j=0;j<20;j++) if(count[j]){val+=1<<j;count[j]--;}
        ans+=val*val;
    }
    cout<<ans<<'\n';
   
    
}