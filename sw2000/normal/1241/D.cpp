#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

struct A
{
    int w,id,v;
}arr[maxn];

bool cmp1(A a,A b)
{
    return a.w<b.w;
}

bool cmp2(A a,A b)
{
    return a.id<b.id;
}

struct B
{
    int l,r;
}brr[maxn];

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
            scanf("%d",&arr[i]);
            arr[i].id=i;
        }
        sort(arr,arr+n,cmp1);
        arr[0].v=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i].w==arr[i-1].w)
            {
                arr[i].v=arr[i-1].v;
            }
            else arr[i].v=arr[i-1].v+1;
        }
        int cnt=arr[n-1].v+1;
        sort(arr,arr+n,cmp2);
        for(int i=0;i<cnt;i++)
        {
            brr[i].l=inf;
            brr[i].r=-1;
        }
        for(int i=0;i<n;i++)
        {
            brr[arr[i].v].l=min(brr[arr[i].v].l,i);
            brr[arr[i].v].r=max(brr[arr[i].v].r,i);
        }
        int len=1,ma=1;
        for(int i=1;i<cnt;i++)
        {
            if(brr[i].l>brr[i-1].r)len++;
            else len=1;
            ma=max(ma,len);
        }
        cout<<cnt-ma<<endl;
    }
	return 0;
}