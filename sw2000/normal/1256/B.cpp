#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+10;
const int inf=0x3f3f3f3f;

int arr[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int l=0;
        while(1)
        {
            int mi=inf,id=-1;
            for(int i=l;i<n;i++)
            {
                if(mi>arr[i])
                {
                    mi=arr[i];
                    id=i;
                }
            }
            if(id==-1)break;
            for(int i=id;i!=l;i--)
            {
                swap(arr[i],arr[i-1]);
            }
            if(id==l)l++;
            else l=id;
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' ';
        cout<<endl;
    }
    return 0;
}