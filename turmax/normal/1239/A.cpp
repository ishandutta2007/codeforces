    #include <bits/stdc++.h>

    using namespace std;
    #define int long long
    const int p=1e9+7;
    const int maxn=100000;
    int a[maxn][2][2];
    int slv1(int n)
    {
        a[1][0][0]=1;
        a[1][0][1]=1;
        a[1][1][0]=1;
        a[1][1][1]=1;
        for(int i=2;i<n;++i)
        {
            a[i][0][0]=a[i-1][1][0];
            a[i][1][1]=a[i-1][0][1];
            a[i][0][1]=a[i-1][0][0]+a[i-1][1][0];
            a[i][1][0]=a[i-1][0][1]+a[i-1][1][1];
            for(int j=0;j<2;++j)
            {
                for(int k=0;k<2;++k)
                {
                    a[i][j][k]%=p;
                }
            }
        }
        return a[n-1][0][0]+a[n-1][0][1]+a[n-1][1][0]+a[n-1][1][1];
    }
    int slv(int n,int m)
    {
        return slv1(n)+slv1(m)-2;
    }
    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n,m;
        cin>>n>>m;
        if(n>=2 && m>=2)
        {
            cout<<((slv(n,m)+p)%p);
            return 0;
        }
        if(n>=m)
        {
            swap(n,m);
        }
        if(m==1)
        {
            cout<<2;
            return 0;
        }
        if(m==2)
        {
            cout<<4;
            return 0;
        }
        if(m>=3)
        {
            cout<<slv1(m)%p;
            return 0;
        }
        return 0;
    }