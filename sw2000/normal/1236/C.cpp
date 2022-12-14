#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

vector<int>ans[maxn];
int arr[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        if(i&1)
        {
            for(int i=0;i<n;i++)
                arr[i]=i+1;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                arr[i]=n-i;
            }
        }
        for(int j=1;j<=n;j++)
        {
            ans[arr[j-1]-1].push_back(i*n+j);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}