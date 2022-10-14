#include <bits/stdc++.h>

#define ff(i,a,b) for(int i=a;i<b;i++)
#define fff(i,a,b) for(int i=a;i<=b;i++)
#define bff(i,a,b) for(int i=a-1;i>=b;i--)
#define bfff(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int a[100005];
int root[100005];
int L[5000005],R[5000005];
int st[5000005];
int br=1;

void Set(int p,int& c,int l,int r,int x,int val)
{
    c=br++, L[c]=L[p], R[c]=R[p], st[c]=st[p]+val;
    if(l==r) return;
    int mid=(l+r)/2;
    if(x<=mid) Set(L[p],L[c],l,mid,x,val);
    else Set(R[p],R[c],mid+1,r,x,val);
}

int sl;

void Query(int c,int l,int r,int k)
{
    if(l==r)
    {
        if(st[c]<=k) sl=max(sl,l);
        return;
    }
    int mid=(l+r)/2;
    if(st[L[c]]>k) 
    {
        Query(L[c],l,mid,k);
        return;
    }
    Query(R[c],mid+1,r,k-st[L[c]]);
    if(sl<mid) Query(L[c],l,mid,k);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n; cin>>n;
    fff(i,1,n) cin>>a[i];
    
    map<int,int> lst;
    lst.clear();
    bfff(i,n,1)
    {
        Set(root[i+1],root[i],1,n,i,1);
        if(lst[a[i]]>0) 
        {
            Set(root[i],root[i],1,n,lst[a[i]],-1);      
        }    
        lst[a[i]]=i;        
    }
    
    fff(k,1,n)
    {
        int ind=1,cnt=0;
        while(ind<=n)
        {
            sl=0; Query(root[ind],1,n,k);
            ind=sl+1;
            cnt++;
        }
        cout<<cnt<<" ";
    }
}