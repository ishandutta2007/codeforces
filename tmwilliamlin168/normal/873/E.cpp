#include <bits/stdc++.h>

using namespace std;
pair<int,int> a[3010];
int n,i,j,z,lo,val,val1,val2,val3,VAL1,VAL2,poz1,poz2,hi,b[3010],aint[12010];
void upd(int poz,int val)
{
    poz+=z;
    aint[poz]=val;
    for(poz>>=1;poz;poz>>=1)
        aint[poz]=max(aint[2*poz],aint[2*poz+1]);
}
int getMax(int p,int st,int dr,int a,int b)
{
    if(a>dr||b<st)
        return 0;
    if(a<=st&&dr<=b)
        return aint[p];
    return max(getMax(2*p,st,(st+dr)/2,a,b),getMax(2*p+1,(st+dr)/2+1,dr,a,b));
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }sort(a+1,a+n+1);
    for(z=1;z<n;z<<=1);z--;
    for(i=n;i>=1;i--)
        upd(i,a[i].first-a[i-1].first);
    for(i=n;i>=1;i--)
        for(j=i-1;j>=1;j--)
        {
            if((n-i+1)*2<(i-j))continue;
            if((n-i+1)>2*(i-j))continue;
            lo=max(n-i+1,i-j)/2+max(n-i+1,i-j)%2;
            hi=min(n-i+1,i-j)*2;
            if(j-lo<=0)continue;
            val=getMax(1,1,z+1,max(1,j-hi),j-lo);
            VAL1=a[i].first-a[i-1].first;
            VAL2=a[j].first-a[j-1].first;
            if(val1<VAL1)
                val1=VAL1,poz1=i,val2=VAL2,poz2=j,val3=val;
            else
                if(val1==VAL1)
                {
                    if(val2<VAL2)
                        val1=VAL1,poz1=i,val2=VAL2,poz2=j,val3=val;
                    else
                        if(val2==VAL2)
                            if(val3<val)
                                val1=VAL1,poz1=i,val2=VAL2,poz2=j,val3=val;
                }
        }
    lo=max(n-poz1+1,poz1-poz2)/2+max(n-poz1+1,poz1-poz2)%2;
    for(i=n;i>=poz1;i--)
        b[a[i].second]=1;
    for(i=poz1-1;i>=poz2;i--)
        b[a[i].second]=2;
    for(i=poz2-1;i>=1;i--)
        if(a[i].first-a[i-1].first==val3)
            if(poz2-i>=lo)
                break;
    for(j=poz2-1;j>=i;j--)
        b[a[j].second]=3;
    for(i=i-1;i>=1;i--)
        b[a[i].second]=-1;
    for(i=1;i<=n;i++)
        cout<<b[i]<<' ';
    return 0;
}