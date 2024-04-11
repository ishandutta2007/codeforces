//EZ VK CUP(NET)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF=1e9;
ll const BINF=1e18;

#define f first
#define sec second
#define itn int
#define fro for
#define pb push_back

struct graph
{
    int from,to,cost;
};

struct coor
{
    int x,y;
};

/*void dfs(int v)
{
    used[v]=true;
    for (int i=0;i<Vec[v].size();i++)
    {
        if (!used[Vec[v][i]])
        {
            dfs(Vec[v][i]);
        }
    }
}*/

vector<int> Vec,Vec1;
int n,m,a,b,sum,ans,kol,l,r,mid,k,d,dp[1000001];
bool used[1000001],t,t1;
set<int> st;
set<int>::iterator it;
map<int,int> mp;
queue<int> q;
pair<int,int> p,p1;
string s[101],s1,s2;
stringstream str;
char ch,ch1,ch2;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));

    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        if (i>25)
        {
            ch1='A';
            ch2='a'+i%26;
            s[i]=ch1;
            s[i]+=ch2;
        }
        else
        {
            ch1='A'+i-1;
            s[i]=ch1;
        }
    }

    for (int i=0;i<n-k+1;i++)
    {
        cin>>s1;
        if (s1=="YES") Vec.pb(0);
        else Vec.pb(1);
    }

    for (int i=k;i<=n;i++)
    {
        if (Vec[d]) s[i]=s[i-k+1];
        d++;
    }

    for (int i=1;i<=n;i++)
    {
        cout<<s[i]<<" ";
    }


    return 0;
}