#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int pr[maxn];
int pr1[maxn];
int mysoldebug(vector <int> a)
{
    int n=a.size();
    int sum=0;
    for(int i=0;i<n;++i) {sum+=a[i];}
    int ans=0;
    pr[0]=0;
    pr1[0]=0;
    pr1[1]=0;
    for(int i=0;i<n;++i) {pr[i+1]=pr[i]+a[i];pr1[i+2]=pr1[i]+a[i];}
    int bal=0;
    //cout<<" ok0 "<<endl;
    //CP
    for(int l=0;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[0];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            //if(l==0 && k==2) cout<<sum1<<" sum1 "<<endl;
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        //cout<<l<<' '<<lowk+1<<endl;
        ans+=(lowk+1);
    }
    cout<<ans<<endl;
    //CC
    //cout<<ans<<endl;
    //cout<<"ok1 "<<endl;
    bal=a[n-1];
    for(int l=0;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l-1)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[0];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        ans+=(lowk+1);
    }
    cout<<ans<<endl;
    //cout<<ans<<endl;
    //cout<<" ok2 "<<endl;
    //PC
    for(int i=1;i<n;++i)
    {
        int sum1=pr[i]-pr[0];
        if((2*sum1)>sum)
        {
            ++ans;
        }
    }
    bal=a[n-1];
    for(int l=1;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l-1)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[1];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        ans+=(lowk+1);
    }
    cout<<ans<<endl;
    //cout<<ans<<endl;
    //PP
    bal=0;
    for(int l=1;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[1];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        ans+=(lowk+1);
    }
    cout<<ans<<endl;
    //cout<<ans<<endl;
    return ans+1;
}
int mysol(vector <int> a)
{
    int n=a.size();
    int sum=0;
    for(int i=0;i<n;++i) {sum+=a[i];}
    int ans=0;
    pr[0]=0;
    pr1[0]=0;
    pr1[1]=0;
    for(int i=0;i<n;++i) {pr[i+1]=pr[i]+a[i];pr1[i+2]=pr1[i]+a[i];}
    int bal=0;
    //cout<<" ok0 "<<endl;
    //CP
    for(int l=0;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[0];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            //if(l==0 && k==2) cout<<sum1<<" sum1 "<<endl;
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        //cout<<l<<' '<<lowk+1<<endl;
        ans+=(lowk+1);
    }
    //cout<<ans<<endl;
    //CC
    //cout<<ans<<endl;
    //cout<<"ok1 "<<endl;
    bal=a[n-1];
    for(int l=0;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l-1)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[0];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        ans+=(lowk+1);
    }
    //cout<<ans<<endl;
    //cout<<ans<<endl;
    //cout<<" ok2 "<<endl;
    //PC
    for(int i=1;i<n;++i)
    {
        int sum1=pr[i]-pr[0];
        if((2*sum1)>sum)
        {
            ++ans;
        }
    }
    bal=a[n-1];
    for(int l=1;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l-1)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[1];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        ans+=(lowk+1);
    }
    //cout<<ans<<endl;
    //cout<<ans<<endl;
    //PP
    bal=0;
    for(int l=1;l<=(n-1);++l)
    {
        int lowk=(-1);
        int upk=(n-l)/2;
        while(true)
        {
            if((upk-lowk)==1) break;
            int k=(lowk+upk)/2;
            int sum1=pr[l+1]-pr[1];
            sum1+=pr1[l+2*k+2]-pr1[l+2];
            if((2*sum1+2*bal)<sum)
            {
                 lowk=k;
            }
            else
            {
                 upk=k;
            }
        }
        ans+=(lowk+1);
    }
    //cout<<ans<<endl;
    //cout<<ans<<endl;
    return ans+1;
}
bool ok1(vector <int> c)
{
    sort(c.begin(),c.end());
    vector <int> v;
    for(int i=1;i<c.size();++i)
    {
        v.push_back(c[i]-c[i-1]);
    }
    vector <int> v1=v;
    sort(v1.begin(),v1.end());
    return (v1==v);
}
bool ok2(vector <int> c)
{
    sort(c.begin(),c.end());
    vector <int> v;
    for(int i=1;i<c.size();++i)
    {
        v.push_back(c[i]-c[i-1]);
    }
    vector <int> v1=v;
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    return (v1==v);
}
int rsol(vector <int> a)
{
    int n=a.size();
    int res=0;
    for(int mask=0;mask<(1<<n);++mask)
    {
        vector <int> c,p;
        int sum1=0,sum2=0;
        for(int i=0;i<n;++i)
        {
            if(mask & (1<<i)) {c.push_back(i);sum1+=a[i];}
            else {p.push_back(i);sum2+=a[i];}
        }
        if(sum2>sum1 && ok1(c) && ok2(p))
        {
             ++res;
        }
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(283782);
    int t;
    cin>>t;
    while(t--)
    {
    /*int n;
    n=10;
    vector <int> a(n);
    for(int i=0;i<n;++i) a[i]=rand()%100000+1;
    if(mysol(a)!=rsol(a))
    {
        for(auto h:a) cout<<h<<' ';
        cout<<endl;
        cout<<mysol(a)<<' '<<rsol(a)<<endl;
        assert(false);
    }*/
    //vector <int> a={0,0,0};
    //cout<<mysoldebug(a)<<endl;
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int res=mysol(a);
    int p=998244353;
    cout<<(res%p)<<endl;
    }
    return 0;
}