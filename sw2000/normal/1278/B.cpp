#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;
int arr[maxn];

int sv(int a)
{
    for(int i=0;;i++)
    {
        if(a<=arr[i])
        {
            if((a&1)&&(arr[i]&1))return i;
            if(!(a&1)&&!(arr[i]&1))return i;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    for(int i=1;i<maxn;i++)
    {
        arr[i]=arr[i-1]+i;
    }
    int t;
    for(scanf("%d",&t);t--;)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",sv(abs(a-b)));
    }
    return 0;
}