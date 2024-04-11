/****** BISMILLAHIR RAHMANIR RAHIM ******/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;

#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 100002
#define debug cout<<"A"<<endl
#define prnt(a) cout<<a<<endl
#define mod 1000000009
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}

inline ll power(ll a, ll b)
{
    ll multiply=1;
    FOR(i,0,b)
    {
        multiply*=a;
    }
    return multiply;
}

/****** END OF HEADER ******/

int n, m, cost[205][205], resCost[205][205], parent[205];
vi graph[205], primes, factsOf[105];
int u[105], v[105];
ll a[105];
bool status[100005], done[100], visited[205];
set<int> nodeU, nodeV;

void sieve()
{
    for (int i=1; i<=100000; i++)
        status[i]=true;
    status[1]=false;
    for (int i=4; i<=100000; i+=2)
        status[i]=false;
    for (int i=3; i<=sqrt(100000); i+=2)
    {
        for (int j=i*i; j<=100000; j+=(i+i))
        {
            if(status[j])
                status[j]=false;
        }
    }
    for (int i=1; i<=100000; i++)
    {
        if(status[i])
            // prnt(i);
            primes.pb(i);
    }
}

void findPrimeFactors(ll x, int i)
{
    FOR(j,0,primes.size())
    {
        while(x%primes[j]==0)
        {
            x/=primes[j];
            factsOf[i].pb(primes[j]);
        }
    }
    if(x!=1)
        factsOf[i].pb(x);
}

bool bfs(int s, int t)
{
    ms(visited,0);
    qi Q;
    Q.push(s);
    visited[s]=true;
    ms(parent,-1);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        FOR(j,0,graph[u].size())
        {
            int v=graph[u][j];
            if(!visited[v] && resCost[u][v]>0)
            {
                Q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
    }
    return visited[t];
}

int maxFlow(int s, int t)
{
    for(int i=0; i<=n+1; i++)
    {
        for (int j=0; j<=n+1; j++)
            resCost[i][j]=cost[i][j];
    }
    int max_flow=0;
    while(bfs(s,t))
    {
        // debug;
        int path_flow=INT_MAX;
        for(int v=t; v!=s; v=parent[v])
        {
            int u=parent[v];
            // cout<<v<<" ";
            path_flow=min(path_flow,resCost[u][v]);
        }
        // cout<<s<<endl;
        for(int v=t; v!=s; v=parent[v])
        {
            int u=parent[v];
            resCost[u][v]-=path_flow;
            resCost[v][u]+=path_flow;
        }
        max_flow+=path_flow;
        // prnt(path_flow);
    }
    return max_flow;
}

int main()
{
    // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    sieve();
    set<int> usePrimes;
    cin>>n>>m;
    FOR(i,1,n+1)
    {
        cin>>a[i];
        findPrimeFactors(a[i],i);
        FOR(j,0,factsOf[i].size())
            usePrimes.insert(factsOf[i][j]);
        // cout<<i<<" ";
        // FOR(j,0,factsOf[i].size())
        //  cout<<factsOf[i][j]<<" ";
        // cout<<endl;
    }
    FOR(i,0,m)
    {
        cin>>u[i]>>v[i];
        if(v[i]%2)  swap(u[i],v[i]);
        graph[u[i]].pb(v[i]);
        graph[v[i]].pb(u[i]);
        // if(find(graph[0].begin(),graph[0].end(),u[i])==graph[0].end())
        //  graph[0].pb(u[i]);
        // if(find(graph[v[i]].begin(),graph[v[i]].end(),n+1)==graph[v[i]].end())
        //  graph[v[i]].pb(n+1);
    }
    FOR(i,1,n+1)
    {
        i%2 ? graph[0].pb(i) : graph[i].pb(n+1);
    }
    int ans=0;
    itrALL(usePrimes,it)
    {
        int nowPrime=*it;
        // prnt(nowPrime);
        for (int i=0;i<=n+1;i++) for (int j=0;j<=n+1;j++) cost[i][j] = 0;
        FOR(i,0,m)
        {
            int cnt1=0, cnt2=0;
            FOR(j,0,factsOf[u[i]].size())
            {
                if(factsOf[u[i]][j]==nowPrime)
                    cnt1++;
            }
            cost[0][u[i]]=cnt1;
            //cout<<0<<" "<<u[i]<<" "<<cost[0][u[i]]<<endl;
            FOR(j,0,factsOf[v[i]].size())
            {
                if(factsOf[v[i]][j]==nowPrime)
                    cnt2++;
            }
            cost[v[i]][n+1]=cnt2;
            cost[u[i]][v[i]]=min(cnt1,cnt2);
            // cout<<v[i]<<" "<<n+1<<" "<<cost[v[i]][n+1]<<endl;
            // cout<<u[i]<<" "<<v[i]<<" "<<cost[u[i]][v[i]]<<endl;
            // ans+=maxFlow(0,n+1);
            // prnt(ans);
        }
        // FOR(k,0,n+2)
        // {
        //  prnt(k);
        //  FOR(j,0,graph[k].size())
        //  {
        //      cout<<graph[k][j]<<" ";
        //  }
        //  cout<<endl;
        // }
        // prnt(maxFlow(0,n+1));
        ans+=maxFlow(0,n+1);
        // prnt(maxFlow(0,n+1));
        // prnt(maxFlow(0,n+1));
    }
    prnt(ans);
    return 0;
}