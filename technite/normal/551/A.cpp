#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[n],b[2003]={0};
    map<long long,long long> m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i-1];
        b[a[i-1]]++;
        
    }
    int coun=1;
    for(int i=2000;i>0;i--)
    {
        if(b[i]!=0){
            m[i]=coun;
            coun+=b[i];
        }   
            
    }
    for(int i=0;i<n;i++)
    {
        cout<<m[a[i]]<<" ";
    }
}