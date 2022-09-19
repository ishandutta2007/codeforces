    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
    const int p=998244353;
    map <int,int> u;
    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<m;++i) {cin>>b[i];u[b[i]]=i;}
        int mi=*min_element(a,a+n);
        if(mi!=b[0])
        {
            cout<<0;
            return 0;
        }
        int ans=1;
        int curr=(m-1);
        int l=(-1);
        int i=n;
        while(i>=1)
        {
            i--;
            if(a[i]<b[curr])
            {
                if(l==(-1))
                {
                    cout<<0;
                    return 0;
                }
                curr--;
                if(curr<0)
                {
                    cout<<0;
                    return 0;
                }
                ans*=(l-i);
                ans%=p;
                i++;
                l=(-1);
            }
            if(a[i]==b[curr] && l==(-1))
            {
                l=i;
            }
        }
        if(curr!=0)
        {
            cout<<0;
            return 0;
        }
        cout<<ans;
        return 0;
    }