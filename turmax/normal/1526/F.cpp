#include <bits/stdc++.h>

using namespace std;
#define int long long
bool local=false;
int z1;
int n;
vector <int> a;
mt19937 rnd;
int med(int x,int y,int z)
{
    vector <int> h={x,y,z};
    sort(h.begin(),h.end());
    return h[1];
}
int query(int u,int v,int w)
{
    cout<<"? "<<u+1<<' '<<v+1<<' '<<w+1<<endl;
    if(!local)
    {
        int ans;
        cin>>ans;
        return ans;
    }
    else
    {
        return med(abs(a[u]-a[v]),abs(a[v]-a[w]),abs(a[w]-a[u]));
    }
}
bool check(int x)
{
    //cout<<n<<" n "<<endl;
    if(x==z1) return false;
    int sum=0;
    for(int i=0;i<18;++i)
    {
        int u=rnd()%n;
        int v=rnd()%n;
        if(u==v || u==z1 || u==x || v==z1 || v==x) {i--;continue;}
        int res1=query(u,v,z1);int res2=query(u,v,x);
        if(res1==(res2+1) || res1==res2)
        {
            ++sum;
        }
    }
    //cout<<" trfe "<<endl;
    return (sum==18);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a.clear();
        rnd.seed(4824948+rnd());
        if(local)
        {
            for(int i=0;i<n;++i) a.push_back(i+1);
            shuffle(a.begin(),a.end(),default_random_engine(rand()+rnd()+6432));
            if(a[0]>a[1])
            {
                for(int i=0;i<n;++i) a[i]=(n+1-a[i]);
            }
        }
        int ans1=1e9;
        vector <int> z;
        for(int i=0;i<200;++i)
        {
            int u=rnd()%n;int v=rnd()%n;int w=rnd()%n;
            if(u!=v && v!=w && w!=u)
            {
                int r=query(u,v,w);
                if(r<ans1)
                {
                    ans1=r;
                    z={u,v,w};
                }
            }
        }
        vector <pair<int,int> > v;
        for(int x=0;x<n;++x)
        {
            if(x!=z[1] && x!=z[2])
            {
                int res1=query(x,z[1],z[2]);
                v.push_back({res1,x});
            }
        }
        sort(v.begin(),v.end());reverse(v.begin(),v.end());
        int pos1=v[0].second;
        z1=pos1;int z2=(-1);
        int pos2=v[1].second;
        int pos3=v[2].second;
        int pos4=v[3].second;
        //cout<<z[0]<<' '<<z[1]<<' '<<z[2]<<endl;
        //cout<<pos1<<' '<<pos2<<' '<<pos3<<' '<<pos4<<endl;
        {
            if(check(pos2)) {z2=pos2;}
            else if(check(pos3)) {z2=pos3;}
            else if(check(pos4)) {z2=pos4;}
            else if(check(z[1])) {z2=z[1];}
            else if(check(z[2])) {z2=z[2];}
        }
        if(z2==(-1)) assert(false);
        vector <int> ans(n);
        ans[z1]=1;
        ans[z2]=2;
        for(int i=0;i<n;++i)
        {
            if(i!=z1 && i!=z2)
            {
                ans[i]=query(z1,z2,i)+2;
            }
        }
        if(ans[0]>ans[1]) for(int i=0;i<n;++i) ans[i]=(n+1-ans[i]);
        if(local) {for(int i=0;i<n;++i) cout<<a[i]<<' ';
        cout<<endl;}
        cout<<"! ";
        for(int i=0;i<n;++i) cout<<ans[i]<<' ';
        cout<<endl;
        int res;
        cin>>res;
        if(res==(-1))
        {
            exit(0);
        }
    }
    return 0;
}