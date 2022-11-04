#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int a[200010],c[200010];
char b[200010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int t=0;
    int l=0,r=n-1;
    int sc=0;
    int fl=0,fr=0;
    while(t<n&&l<=r&&(fl==0||fr==0))
    {
        if(a[l]<a[r]&&fl==0)
        {
            if(a[l]<sc)
            {
                fl=1;
                if(a[r]<sc)
                {
                    break;
                }
                b[t++]='R';
                sc=a[r];
                r--;
                continue;
            }
            b[t]='L';
            sc=a[l];
            l++;
            t++;
        }
        else
        {
            if(a[r]<sc)
            {
                fr=1;
                if(a[l]<sc)
                {
                    break;
                }
                b[t++]='L';
                sc=a[l];
                l++;
                continue;
            }
            b[t++]='R';
            sc=a[r];
            r--;
        }
    }
    cout<<t<<endl;
    for(int i=0;i<t;i++)
        cout<<b[i];
    cout<<endl;
    return 0;
}