#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> count(26);
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            count[c-'a']++;
        }
        for(int i=n;i>=1;i--)
        {
            int g=__gcd(i, k);
            int m=i / g;
            int c=0;
            for(int j=0;j<26;j++)
                c+=m*(count[j]/m);
            if(c>=i)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
}