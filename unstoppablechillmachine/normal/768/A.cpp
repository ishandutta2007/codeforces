#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second
#define itn int
#define fro for

struct graph
{
    int from,to, cost;
};

struct coor
{
    int x,y;
};

set<int> st;
map<int,int> mp;
queue<int> q;
deque <int> d;
pair<int,int> p;
vector<int> Vec,Vec1;
string s,s1,s2;
stringstream str;
bitset<100000> bt;
char ch;
bool t,t1,used;
int n,m,a,a1,b,c,l,r,mid,kol,sum,k;

vector<int> zfunc(string s1)
{
    vector<int> z;
    z.resize(s.size());
    l=0;
    r=1;
    for (int i=1;i<s.size();i++)
    {
        z[i]=min(z[i-l],max(r-i,0));
        while (i+z[i]<s.size() && s[z[i]]==s[z[i]+i]) z[i]++;
    }
    return z;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    Vec.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Vec[i]);
    }
    sort(Vec.begin(),Vec.end());
    for (int i=0;i<n;i++)
    {
        if (Vec[i]>Vec[0] && Vec[i]<Vec[n-1]) sum++;
    }
    cout<<sum;

    return 0;
}