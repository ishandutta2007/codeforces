    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
    vector <int> v1;
    vector <int> v2;
    const int p=1e9+9;
    int mod=555;
    void strhash1(string s)
    {
        v1.resize(s.size()+1);
        v1[0]=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            v1[i+1]=s[i]+mod*v1[i];
            v1[i+1]%=p;
        }
    }
    void strhash2(string s)
    {
        v2.resize(s.size()+1);
        v2[0]=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            v2[i+1]=s[i]+mod*v2[i];
            v2[i+1]%=p;
        }
    }
    const int maxn=1000010;
    int po[maxn];
    int dehas1(int x,int y)
    {
        return ((v1[y]-v1[x]*po[y-x])%p+p)%p;
    }
    int dehas2(int x,int y)
    {
        return (((v2[y]-v2[x]*po[y-x])%p)+p)%p;
    }
    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int u=1;
        for(int i=0;i<maxn;++i)
        {
            po[i]=u;
            u*=mod;
            u%=p;
            po[i]%=p;
        }
        int q;
        cin>>q;
        while(q--)
        {
        string s;
        cin>>s;
        string s1=s;
        reverse(s1.begin(),s1.end());
        v1.clear();
        v2.clear();
        strhash1(s);
        strhash2(s1);
        int n=s.size();
        int l=0;
        int r=(n-1);
        string t1;
        string t2;
        while(s[l]==s[r])
        {
            if((t1.size()+t2.size())<=(n-2))
            {
                t1+=s[l];
                t2+=s[r];
                ++l;
                r--;
            }
            else
            {
                break;
            }
        }
        reverse(t2.begin(),t2.end());
        pair <int,int> ans1;
        for(int i=r;i>=(l-1);i--)
        {
            if(dehas1(l,i+1)==dehas2(n-i-1,n-l))
            {
                ans1={l,i+1};
                break;
            }
        }
        for(int i=l;i<=min(r,r-ans1.second+ans1.first);++i)
        {
            if(dehas1(i,r+1)==dehas2(n-r-1,n-i))
            {
                ans1={i,r+1};
                break;
            }
        }
        string h;
        for(int i=ans1.first;i<ans1.second;++i)
        {
            h+=s[i];
        }
        cout<<t1<<h<<t2<<endl;
        }
        return 0;
    }