#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int a[20];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int k;
        scanf("%d", &k);
        int sum=0;
        for(int i=1; i<=7; i++)
        {
            scanf("%d", &a[i]);
            sum+=a[i];
            a[i+7]=a[i];
        }
        ll mn=1e15;
        for(int i=1; i<=7; i++)
        {
            ll cnt=max((k/sum)-1, 0);
            ll res=cnt*7;
            ll lst=k-cnt*sum;
            int j=i;
            while(lst)
            {
                j++;
                if(a[(j-1)%7+1])
                {
                    lst--;
                }
                res++;
            }
            mn=min(res, mn);
        }
        printf("%lld\n", mn);
    }
}