#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

int arr[maxn],flag[maxn],plu[maxn];
int n;

void print()
{
    for(int i=0;i<n;i++)
    {
        if(plu[i]==-1&&arr[i]!=0)cout<<'-';
        cout<<arr[i]<<endl;
    }
}

int main()
{
    ll sum=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        string a;
        int j=0;
        plu[i]=1;
        cin>>a;
        if(a[0]=='-')
        {
            plu[i]=-1;
            j++;
        }
        while(a[j]!='.')
        {
            arr[i]*=10;
            arr[i]+=a[j]-'0';
            j++;
        }
        for(int k=1;k<6;k++)
        {
            if(a[k+j]!='0')
            {
                break;
            }
            if(k==5)flag[i]=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(plu[i]==1)sum+=arr[i];
        else sum-=arr[i];
    }

    if(sum==0)
    {
        print();
        return 0;
    }

    if(sum<0)
    {
        for(int i=0;i<n;i++)
        {
            if(plu[i]==1&&flag[i]==0)
            {
                arr[i]++;
                sum++;
            }
            if(sum==0)
            {
                print();
                return 0;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(plu[i]==-1&&flag[i]==0)
        {
            arr[i]++;
            sum--;
        }
        if(sum==0)
        {
            print();
            return 0;
        }
    }

    return 0;
}