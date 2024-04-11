#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<int> primes={2,3,5,7,11,13,17,19,23,29,31};
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        int m=0;
        vector<int> color(n);
        vector<int> div;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(int j=0;j<n;j++)
        {
            int f=0;
            for(int k=0;k<m;k++)
            {
                //cout<<"hi"<<j<<"\n";
                if(a[j]%div[k]==0)
                {
                    color[j]=k+1;
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int k=0;k<11;k++)
                {
                    if(a[j]%primes[k]==0)
                    {
                        div.push_back(primes[k]);
                        m++;
                        color[j] = m;
                        break;
                    }
                }
            }
        }
        cout<<m<<endl;
        for(int j=0;j<n;j++) cout<<color[j]<<" ";
    }
}