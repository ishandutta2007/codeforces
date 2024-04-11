#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b)
{
    if(b==1)
    {
        return a%p;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        return (po(a,b-1)*a)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
int pr[200001];
int pr1[200001];
int pr2[200001];
int g[200001];
int go(int l,int r)
{
    int val1,val2;
    int d=g[l];
    val1=(((pr[r])*(r-l)+((pr1[r]-pr1[l]-pr2[r]*l+pr2[l]*l)%p))%p)*d;
    val2=pr[r]*d;
    int ans;
    val1%=p;
    val2%=p;
    ans=val1*inv(val2);
    ans%=p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector <int> a(n);
    set <int> ch;
    ch.insert(0);
    ch.insert(n);
    int t=inv(100LL);
    pr[0]=1;
    pr1[0]=0;
    pr2[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]*=t;
        a[i]%=p;
        pr[i+1]=pr[i]*a[i];
        pr[i+1]%=p;
        pr1[i+1]=pr1[i]+((pr[i]*(1-a[i]))%p)*(i+1);
        pr2[i+1]=pr2[i]+(pr[i]*(1-a[i]));
        pr1[i+1]%=p;
        pr2[i+1]%=p;
        pr1[i+1]+=p;
        pr2[i+1]+=p;
        pr1[i+1]%=p;
        pr2[i+1]%=p;
    }
    for(int i=0;i<=n;++i)
    {
        g[i]=inv(pr[i]);
    }
    int val1,val2;
    //cout<<pr[n]<<" "<<pr1[n]<<endl;
    val1=pr[n]*n+pr1[n];
    val2=pr[n];
    int ans;
    val1%=p;
    val2%=p;
    ans=val1*inv(val2);
    ans%=p;
    int k;
    int d1,d2;
    set <int>::iterator it;
    //cout<<ans<<" ans "<<endl;
    for(int i=0;i<q;++i)
    {
        cin>>k;
        k--;
        if(ch.count(k)==0)
        {
            it=ch.lower_bound(k);
            d2=(*it);
            it--;
            d1=(*it);
            ans+=go(d1,k);
            ans+=go(k,d2);
            ans-=go(d1,d2);
            ans%=p;
            ans+=p;
            ans%=p;
            ch.insert(k);
            cout<<ans<<endl;
        }
        else
        {
            ch.erase(k);
            it=ch.lower_bound(k);
            d2=(*it);
            it--;
            d1=(*it);
            ans-=go(d1,k);
            ans-=go(k,d2);
            ans+=go(d1,d2);
            ans%=p;
            ans+=p;
            ans%=p;
            cout<<ans<<endl;
        }
    }
    return 0;
}