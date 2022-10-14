#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000001];
int c[1000001];
int p[1000001];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++)
    {
        memset(c,0,sizeof(c));
        int j=0;
        do
        {
            c[a[i+j]]++;
            j++;
        }while(c[a[i+j-1]]<=p[a[i+j-1]]);
        c[a[i+j-1]]--;
        for(int k=1;k<=m;k++)
        {
            //cout<<i<<" "<<k<<" "<<c[k]<<" "<<p[k]<<endl;
            if(c[k]<p[k])
                break;
            else if(k==m&&c[k]==p[k])
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}