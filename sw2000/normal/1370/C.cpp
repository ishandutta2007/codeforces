#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1010;

int arr[maxn<<1];
bool solve()
{
    int n;scanf("%d",&n);
    if(n==1)return 0;
    else if(n==2)return 1;
    else if(n&1)return 1;
    else
    {
        bool f=0;
        int cnt=0;
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                cnt++;
                if(i&1)f=1;
                n/=i;
            }
        }
        if(n!=1)
        {
            cnt++;
            if(n&1)f=1;
        }

        if(f&&cnt>=3)return 1;
        else return 0;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("Ashishgup");
        else puts("FastestFinger");
    }
    return 0;
}