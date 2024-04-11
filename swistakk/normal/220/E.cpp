#include <iostream>
#include <algorithm>
#define uint long long int
#define M 131072
#define N 100005
using namespace std;
uint drz[2*M+5][2];
// uint drzpref[2*M+5];
int dosort[N];
int zonk[N];
int t[N];
bool cmp(int a, int b)
{
    if(zonk[a]<zonk[b])
    {
        return 1;
    }
    return 0;
}
int dod(int a, int ind, int war)
{
    a+=M-1;
    while(a)
    {
        drz[a][ind]+=war;
        a/=2;
    }
}
int czyt(int a, int b, int ind)
{
    if(a>b)
    {
        return 0;
    }
    uint w=0;
    a+=M-1;
    b+=M-1;
    w+=drz[a][ind];
    if(a!=b)
    {
        w+=drz[b][ind];
    }
    while(a/2 != b/2)
    {
        if(a%2==0)
        {
            w+=drz[a+1][ind];
        }
        if(b%2==1)
        {
            w+=drz[b-1][ind];
        }
        a/=2;
        b/=2;
    }
    return w;
}
int main()
{
    ios_base::sync_with_stdio(0);
    uint n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        dosort[i]=i;
        cin>>zonk[i];
    }
    sort(dosort+1, dosort+1+n, cmp);
    for(int i=1; i<=n; i++)
    {
        if(zonk[dosort[i]]==zonk[dosort[i-1]])
        {
            t[dosort[i]]=t[dosort[i-1]];
        }
        
        else
        {
            t[dosort[i]]=i;
        }
    }
    /* for(int i=1; i<=n; i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl; */
        
        
    uint inv=0;   
    int r=2*n;
    for(int i=n; i>=1; i--)
    {
        inv+=czyt(1, t[i]-1, 1);
        if(inv>k)
        {
            r=i+1;
            inv-=czyt(1, t[i]-1, 1);
            break;
        }
        dod(t[i], 1, 1);
    }
    if(r==2*n)
    {
        cout<<n*(n-1)/2<<endl;
        return 0;
    }
    // cout<<r<<endl;
    uint wynik=0;
    for(int i=1; i<=n-1; i++)
    {
        inv+=czyt(t[i]+1, n, 0);
        inv+=czyt(1, t[i]-1, 1);
        dod(t[i], 0, 1);
        while(r<=n && inv>k)
        {
            inv-=czyt(t[r]+1, n, 0);
            inv-=czyt(1, t[r]-1, 1);
            dod(t[r], 1, -1);
            r++;
        }
        wynik+=n-r+1;
        /* cout<<i<<" "<<r<<" "<<inv<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<czyt(i, i, 0)<<" ";
        }
        cout<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<czyt(i, i, 1)<<" ";
        }
        cout<<endl; */
        // cout<<czyt(1, n, 0)<<" plum "<<czyt(1, n, 1)<<endl;
        if(r==n+1)
        {
            cout<<wynik<<endl;
            // system("pause");
            return 0;
        }
    }
}