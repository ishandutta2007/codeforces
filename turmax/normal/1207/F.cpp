    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
    int a[501][501];
    int b[500000];
    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        for(int i=0;i<500000;++i)
        {
            b[i]=0;
        }
        int q;
        cin>>q;
        for(int i=0;i<501;++i)
        {
            for(int j=0;j<501;++j)
            {
                a[i][j]=0;
            }
        }
        int t,x,y;
        int sum;
        for(int i=0;i<q;++i)
        {
            cin>>t>>x>>y;
            if(t==1)
            {
                x--;
                b[x]+=y;
                for(int i=1;i<501;++i)
                {
                    a[i][(x%i)]+=y;
                }
            }
            else
            {
                if(x<=500)
                {
                    cout<<a[x][(x+y-1)%x]<<endl;
                }
                else
                {
                    sum=0;
                    if(y==0)
                    {
                        y=x;
                    }
                    for(int i=0;(i*x+y)<=500000;++i)
                    {
                        sum+=b[i*x+y-1];
                    }
                    cout<<sum<<endl;
                }
            }
        }
        return 0;
    }