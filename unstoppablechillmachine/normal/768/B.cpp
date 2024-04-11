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
ll n,m,a[100],a1,b,c,l,r,mid,kol,sum,k,x,maxj,r1,maxi,n1;

/*vector<int> zfunc(string s1)
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
}*/

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    if (!n)
    {
        cout<<0;
        exit(0);
    }
    n1=n;
    while(n1>3) n1/=2;
    if (n1==3) t=true;
    x=1;
    a[0]=x;
    for (int i=1;i<=50;i++)
    {
        x*=2;
        a[i]=x;
    }
    for (int i=0;i<=50;i++)
    {
        if (n/a[i]>0) sum+=a[i];
        maxi=i;
    }

    mid=sum/2+1;
    cin>>l>>r1;
    for (ll i=l;i<=r1;i++)
    {
        if (i==0)
        {
            if (t) kol++;
            continue;
        }
        if (i%2==1)
        {
            kol++;
            continue;
        }
        n1=n;
        r=sum+1;
        l=1;
        while(r-l>1)
        {
            mid=(l+r)/2;
            //cout<<mid<<" ";
            if(mid==i)
            {
                if (n1%2==1)
                {
                    kol++;
                    //cout<<i<<endl;
                }
                l=r;
                //cout<<n1<<" "<<i<<" "<<endl;
            }
            else
            {
                if (mid>i) r=mid;
                else l=mid;
                n1/=2;
            }
        }
    }

    cout<<kol;

    /*cin>>n>>k>>x;
    Vec.resize(n);
    for (int i=0;i<n;i++)
    {
        cin>>Vec[i];
    }
    sort(Vec.begin(),Vec.end());
    for (int i=0;i<k;i++)
    {
        Vec1=Vec;
        for (int j=0;j<n;j++)
        {
            if (j%2==0) Vec[j]=(Vec[j] ^ x);
        }
        sort(Vec.begin(),Vec.end());
        //copy(Vec.begin(),Vec.end(),ostream_iterator<int>(cout," "));
        //cout<<endl;
        if (Vec1==Vec) break;
    }

    cout<<Vec[0]<<" "<<Vec[n-1];*/


    return 0;
}