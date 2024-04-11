#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

struct A
{
    int a[3];
}arr[maxn];

vector<int>v[maxn];
int cnt[maxn];
bool vis[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&arr[i].a[j]);
            v[arr[i].a[j]].push_back(i);
        }
    }
    int st;
    for(int i=1;i<=n;i++)
    {
        cnt[i]=v[i].size();
        if(cnt[i]==1)
        {
            st=i;
        }
    }
    for(int i=0;i<n-2;i++)
    {
        if(arr[i].a[0]==st||arr[i].a[1]==st||arr[i].a[2]==st)
        {
            st=i;
            break;
        }
    }

    for(int i=0;i<n-3;i++)
    {
//        for(int j=0;j<3;j++)
//        {
//            cout<<arr[st].a[j]<<' '<<v[arr[st].a[j]].size()<<endl;
//        }
//        cout<<endl;

        for(int j=0;j<3;j++)
        {
            if(v[arr[st].a[j]].size()==1)
            {
                printf("%d ",arr[st].a[j]);
                break;
            }
        }

        for(int j=0;j<3;j++)
        {
            for(int k=0;k<v[arr[st].a[j]].size();k++)
            {
                if(v[arr[st].a[j]][k]==st)
                {
                    v[arr[st].a[j]].erase(v[arr[st].a[j]].begin()+k);
                    break;
                }
            }
        }

        for(int j=0;j<3;j++)
        {
            if(v[arr[st].a[j]].size()==1)
            {
                st=v[arr[st].a[j]][0];
                break;
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        if(cnt[arr[st].a[i]]==3)
        {
            printf("%d ",arr[st].a[i]);
        }
    }
    for(int i=0;i<3;i++)
    {
        if(cnt[arr[st].a[i]]==2)
        {
            printf("%d ",arr[st].a[i]);
        }
    }
    for(int i=0;i<3;i++)
    {
        if(cnt[arr[st].a[i]]==1)
        {
            printf("%d ",arr[st].a[i]);
        }
    }


    return 0;
}