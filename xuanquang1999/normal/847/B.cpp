#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn=2e5+7;

int st[maxn],n1,n,a[maxn];
vector <int> rres[maxn];

int cnp(int x)
{
    int l=1, r=n1;
    int res=0;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (st[mid]>=x) l=mid+1;
        else res=mid, r=mid-1;
    }
    if (x<=st[n1]) res=n1+1, n1++;
    return res;
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    n1=1;
    rres[1].push_back(a[1]);
    st[1]=a[1];
    for (int i=2; i<=n; ++i)
    {
        int vt=cnp(a[i]);
        st[vt]=a[i];
        rres[vt].push_back(a[i]);
    }
    for (int i=1; i<=n1; ++i)
    {
        for (int j=0; j<rres[i].size(); ++j) printf("%d ",rres[i][j]);
        printf("\n");
    }
}