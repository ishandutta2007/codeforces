#include <iostream>
#include <vector>
#include <algorithm>
#define uint long long int
#define N 1000007
using namespace std;
int a[N];
int t[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, h;
    cin>>n>>h;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        t[i]=a[i];
       // cin>>t[i];
    }
    sort(t+1, t+1+n);
    int ktory=0;
    int f1=t[n]+t[n-1]-(t[1]+t[2]);
    int maxi=max(t[n]+t[1]+h, t[n]+t[n-1]);
    int mini=min(t[2]+t[3], t[1]+t[2]+h);
    int najm=0;
    a[0]=1001*1001*1001;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<a[najm])
        {
            najm=i;
        }
    }
    if(f1>maxi-mini && n>2)
    {
        cout<<maxi-mini<<endl;
        for(int i=1; i<=n; i++)
        {
            if(i==najm)
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"2 ";
            }
        }
        cout<<endl;
    }
    else
    {
        cout<<f1<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<"1 ";
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}
/*
3 2
2 1 3
*/