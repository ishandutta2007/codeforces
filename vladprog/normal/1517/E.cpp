#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=998244353;

int a[N],s[N],p[N];

int sum(int l,int r)
{
//    return -1e9;
    return s[r]-s[l-1];
}

void cutl(int&l,int b)
{
    if(l%2!=b%2)
        l++;
}

void cutr(int&r,int b)
{
    if(r%2!=b%2)
        r--;
}

void cut(int&l,int&r,int b)
{
    cutl(l,b);
    cutl(r,b);
}

int par(int l,int r,int b)
{
//    return -1e9;
    cut(l,r,b);
    if(l>r)
        return 0;
    return p[r]-p[l-2];
}

void gen(string&str,string cur,int l,int r)
{
    for(int i=l;i<=r;i++)
        str[i]=cur[(i-l)%cur.size()];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
//        cout<<n<<" -> ";
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<1<<"\n";
            continue;
        }
        if(n==2)
        {
            if(a[1]==a[2])
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
            continue;
        }
        s[0]=0;
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i];
        p[0]=0;
        p[1]=a[1];
        for(int i=2;i<=n;i++)
            p[i]=p[i-2]+a[i];
        int bound=(sum(1,n)-1)/2;
        int ans=0;
        /// C(C...C)(PC...PC)(P...P)P
        ///       i        j
//        cout<<"C(C...C)(PC...PC)(P...P)P\n";
        for(int i=1;i<=n-1;i++)
        {
            if(sum(1,i)>bound)
                break;
            int l=i,r=n-1;
            while(l<r)
            {
                int j=(l+r+1)/2;
                int cur=sum(1,i)+par(i+1,j,i);
                if(cur<=bound)
                    l=j;
                else
                    r=j-1;
            }
            int j=(l+r+1)/2;
            cutr(j,i);
//            cout<<i<<" "<<j<<" -> "<<(j-i)/2+1<<" :\n";
//            for(int t=i;t<=j;t+=2)
//            {
//                string str(n+1,' ');
//                gen(str,"C",1,1);
//                gen(str,"C",2,i);
//                gen(str,"PC",i+1,j);
//                gen(str,"P",j+1,n-1);
//                gen(str,"P",n,n);
//                cout<<str<<"\n";
//            }
            ans+=(j-i)/2+1;
        }
        /// P(C...C)(PC...PC)(P...P)P
        ///       i        j
//        cout<<"P(C...C)(PC...PC)(P...P)P\n";
        for(int i=2;i<=n-1;i++)
        {
            if(sum(2,i)>bound)
                break;
            int l=i,r=n-1;
            while(l<r)
            {
                int j=(l+r+1)/2;
                int cur=sum(2,i)+par(i+1,j,i);
                if(cur<=bound)
                    l=j;
                else
                    r=j-1;
            }
            int j=(l+r+1)/2;
            cutr(j,i);
//            cout<<i<<" "<<j<<" -> "<<(j-i)/2+1<<" :\n";
//            for(int t=i;t<=j;t+=2)
//            {
//                string str(n+1,' ');
//                gen(str,"P",1,1);
//                gen(str,"C",2,i);
//                gen(str,"PC",i+1,t);
//                gen(str,"P",t+1,n-1);
//                gen(str,"P",n,n);
//                cout<<str<<"\n";
//            }
            ans+=(j-i)/2+1;
        }
        /// C(C...C)(PC...PC)(P...P)C
        ///       i        j
//        cout<<"C(C...C)(PC...PC)(P...P)C\n";
        for(int i=1;i<=n-1;i++)
        {
            if(sum(1,i)+a[n]>bound)
                break;
            int l=i,r=n-2;
            while(l<r)
            {
                int j=(l+r+1)/2;
                int cur=sum(1,i)+par(i+1,j,i)+a[n];
                if(cur<=bound)
                    l=j;
                else
                    r=j-1;
            }
            int j=(l+r+1)/2;
            cutr(j,i);
//            cout<<i<<" "<<j<<" -> "<<(j-i)/2+1<<" :\n";
//            for(int t=i;t<=j;t+=2)
//            {
//                string str(n+1,' ');
//                gen(str,"C",1,1);
//                gen(str,"C",2,i);
//                gen(str,"PC",i+1,t);
//                gen(str,"P",t+1,n-1);
//                gen(str,"C",n,n);
//                cout<<str<<"\n";
//            }
            ans+=(j-i)/2+1;
        }
        /// P(C...C)(PC...PC)(P...P)C
        ///       i        j
//        cout<<"P(C...C)(PC...PC)(P...P)C\n";
        for(int i=2;i<=n-1;i++)
        {
            if(sum(2,i)+a[n]>bound)
                break;
            int l=i,r=n-2;
            while(l<r)
            {
                int j=(l+r+1)/2;
                int cur=sum(2,i)+par(i+1,j,i)+a[n];
                if(cur<=bound)
                    l=j;
                else
                    r=j-1;
            }
            int j=(l+r+1)/2;
            cutr(j,i);
//            cout<<i<<" "<<j<<" -> "<<(j-i)/2+1<<" :\n";
//            for(int t=i;t<=j;t+=2)
//            {
//                string str(n+1,' ');
//                gen(str,"P",1,1);
//                gen(str,"C",2,i);
//                gen(str,"PC",i+1,t);
//                gen(str,"P",t+1,n-1);
//                gen(str,"C",n,n);
//                cout<<str<<"\n";
//            }
            ans+=(j-i)/2+1;
        }
        /// (P...P)(C...C)
        ///         i
//        cout<<"(P...P)(C...C)\n";
        for(int i=3;i<=n+1;i++)
            if(sum(i,n)<=bound)
            {
//                cout<<i<<" -> "<<1<<" :\n";
//                string str(n+1,' ');
//                gen(str,"P",1,i-1);
//                gen(str,"C",i,n);
//                cout<<str<<"\n";
                ans++;
            }
        /// done
//        cout<<"done\n";
        cout<<ans%MOD<<"\n";
    }
}