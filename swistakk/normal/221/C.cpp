#include <iostream>
#include <vector>
#include <algorithm>
#define uint long long int
using namespace std;
int t[1001*101];
int s[1001*101];
int bla[1001*101];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    int swaps=0;
    for(int i=1; i<=n-1; i++)
    {
        if(t[i]>t[i+1])
        {
            swaps++;
            s[swaps]=i;
        }
    }
    // cout<<swaps<<endl;
    if(swaps>=3)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(swaps==2)
    {
        for(int k=-1; k<=1; k++)
        {
            for(int l=-1; l<=1; l++)
            {
                for(int i=1; i<=n; i++)
                {
                    bla[i]=t[i];
                }
                swap(bla[s[1]+k], bla[s[2]+l]);
                for(int i=1; i<=n-1; i++)
                {
                    if(bla[i]>bla[i+1])
                    {
                        goto A;
                    }
                }
                cout<<"YES"<<endl;
                return 0;
                A: ;
            }
        }
        cout<<"NO"<<endl;
        return 0;
    }
    if(swaps==1)
    {
        for(int i=1; i<=n; i++)
        {
            swap(t[s[1]], t[i]);
            if( (s[1]==1 || t[s[1]-1]<=t[s[1]]) && t[s[1]]<=t[s[1]+1] && t[i]>=t[i-1] && (i==n || t[i]<=t[i+1]))
            {
                cout<<"YES"<<endl;
                return 0;
            }
            swap(t[s[1]], t[i]);
        }
        for(int i=1; i<=n; i++)
        {
            swap(t[s[1]+1], t[i]);
            /* if(i==2)
            {
                for(int j=1; j<=n; j++)
                {
                    cout<<t[j]<<" ";
                }
                cout<<endl;
            }
            cout<<s[1]+1<<endl; */
            if(  t[s[1]]<=t[s[1]+1] && (t[s[1]+1]<=t[s[1]+2] || s[1]+1==n) &&  (i==1 || t[i]>=t[i-1]) && (i==n || t[i]<=t[i+1]))
            {
                cout<<"YES"<<endl;
                return 0;
            }
            swap(t[s[1]+1], t[i]);
        }
        // system("pause");
        cout<<"NO"<<endl;
        return 0;
    }
    if(swaps==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
}
/*
6
1 2 5 3 4 6
*/
/*
6
1 2 5 4 3 6
*/
/*
6
1 2 5 3 4 6
*/
/*
5
1 2 2 2 1
*/