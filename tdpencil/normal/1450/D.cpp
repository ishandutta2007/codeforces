    #include <bits/stdc++.h> 
    #include <string>
    #include <cmath> 
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<string> vs;
    typedef vector<char> vc;
    typedef vector<vs> vvs;
    typedef vector<vc> vvc;
    typedef vector<ll> vll;
    typedef vector<vi> vvi;
    typedef vector<vll> vvll;
    typedef map<int,int> mpii;
    typedef map<int,vi> mpivi;
    typedef map<string,int> mpsi;
    typedef map<pii,int> map_pair;
    typedef set<int> seti;
    #define	bits(n)						( (n==0)?0:((int)log2(n)+1) )
    #define endl '\n'
    #define FOR(i,n) SFOR(i,0,n)
    #define SFOR(i,m,n) for(i=m;i<n;i++)
    #define FORD(i,n) for(i=n-1;i>=0;i--)
    #define digits(i)   (int)((log(i)/log(10))+1)		
    #define inf							(int)1e9
    #define eps							1e-9
    #define pi							3.1415926535897932384626433832795
    #define mod							1000000007
    #define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
    #define pb push_back
    #define all(s) s.begin(), s.end()
    #define sz(s) s.size()
    #define si(t) scanf("%d",&(t))
    #define ss(t) scanf("%s",(t))
    #define sll(t) scanf("%lld",&(t))
    #define maX(a,b)					( (a) > (b) ? (a) : (b))
    #define miN(a,b)					( (a) < (b) ? (a) : (b))
    #define check_bit(var,pos) ((var) & (1<<(pos)))
    #define prn1(x)                cout<<#x<<": "<<x<<endl
    #define prn2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
    #define prn3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
    #define prn4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
    #define prn5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
    #define prn6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
    const int N = 1e5;
   struct myfun
    {
        public:
    bool operator()(pair<double,double> a,pair<double,double>  b)
    {
       // prn2(a.first,b.first);
    //    prn2(a.second/a.first,b.second/b.first);
        return a.second/a.first<=b.second/b.first;
    }
    };
void A()
{
    int t;
    cin>>t;
    for(int kk=0;kk<t;kk++)
    {
        int n;
        cin>>n;
       
        
    }
}

void B()
{
    int t;
    cin>>t;
    for(int kk=0;kk<t;kk++)
    {
        int n;
        cin>>n;
        vi vec(n);        
        vi mp(n+2,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            mp[vec[i]]++;
            if(mp[vec[i]]==1) cnt++;
        }
        vi ans(n,0);
        int l=0;
        int r=n-1;
        int i=1;
        while(l<r)
        {
           // prn5(i,l,r,vec[l],vec[r]);
           if(!mp[i]) {
               i--;
               break;
           }
           if(vec[l]==i &&mp[i]==1 )
            {
                l++;
                mp[i]--;
            }
            else if(vec[r]==i  && mp[i]==1)
            {
                r--;
                mp[i]--;
            }
            else 
            {
                break;
            }
            
            
            i++;
        }
        //prn3(i,cnt,n);
        for(int j=0;j<i;j++)
        {
            ans[j]=1;
        }
        if(cnt==n) ans[n-1]=1;
        else ans[n-1]=0;
        for(int i=n-1;i>=0;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;
        
    }
   
}

void D()
{
    
}

    int main() {
        boost;
        //clock_t t;
        //t=clock();
       //freopen("C:\\Users\\asderfers\\Documents\\codeforce\\hello\\in.txt", "r", stdin);
        //freopen("C:\\Users\\asderfers\\Desktop\\in.txt", "r", stdin);
       // freopen("C:\\Users\\asderfers\\Desktop\\out.txt", "w", stdout);
        //freopen("J.txt", "r", stdin);
        B();
        //B();
        //C();
          //D1();
        //t = clock() - t;
        //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
        return 0;
    }