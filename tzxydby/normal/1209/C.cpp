#include<bits/stdc++.h>
using namespace std;
int n;
string s,ss,ans;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        ss=s;ans=s;
        sort(ss.begin(),ss.end());
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==ss[k])
            {
                s[i]=1;
                ans[i]='1';
                k++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==ss[k])
            {
                s[i]=1;
                ans[i]='2';
                k++;
            }
        }
        cout<<(k==n?ans:"-")<<endl;
    }
    return 0;
}