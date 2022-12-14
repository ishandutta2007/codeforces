#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5;

pii id[maxn];
int arr[maxn],l[maxn],r[maxn],ans;

void add(int a)
{
    if(l[a-1]&&l[a+1])
    {
        int l1=a-l[a-1],l2=r[a+1]-a;
        ans+=(l1+l2+2)/2-(l1+1)/2-(l2+1)/2;
        l[r[a+1]]=l[a-1];
        r[l[a-1]]=r[a+1];
    }
    else if(l[a-1])
    {
        int l1=a-l[a-1];
        if(l1%2==0)ans++;
        r[l[a-1]]=a;
        l[a]=l[a-1];
        r[a]=a;
    }
    else if(l[a+1])
    {
        int l1=r[a+1]-a;
        if(l1%2==0)ans++;
        r[a]=r[a+1];
        l[a]=a;
        l[r[a+1]]=a;
    }
    else
    {
        l[a]=a;
        r[a]=a;
        ans++;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
        id[i].x=arr[i];
        id[i].y=i;
    }
    sort(id+1,id+n+1);

    for(int i=1;i<=n;i++)
    {
        add(id[i].y);
        int cnt=0;
        if(!l[1]||(r[1]-l[1])%2)cnt++;
        if(!l[n]||(r[n]-l[n])%2)cnt++;
        if(ans*2-1+cnt>=k)
        {
            cout<<id[i].x;
            return 0;
        }
    }

    return 0;
}