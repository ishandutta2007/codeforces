#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k=(1ll<<m)-n;
        int p=(k-1)/2;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            a[i]=0;
            for(char c:s)
                a[i]*=2,
                a[i]+=c-'0';
        }
        sort(a,a+n);
        int lo=0,hi=(1ll<<m)-1;
        while(lo<hi)
        {
            int mi=(lo+hi+1)/2;
            int cur=mi;
            cur-=lower_bound(a,a+n,mi)-a;
            if(cur<p)
                lo=mi+1;
            else if(cur>p)
                hi=mi-1;
            else
                lo=mi;
        }
        for(int i=m-1;i>=0;i--)
            cout<<((lo>>i)&1);
        cout<<"\n";
    }
}