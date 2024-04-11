#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
#define FI first
#define SE second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct node
{
    int x,y,z;
    node(){}
    node(int a,int b,int c):x(a),y(b),z(c){}
    node operator +(const node &a) const {return node(x+a.x,y+a.y,z+a.z);}
    node operator -(const node &a) const {return node(x-a.x,y-a.y,z-a.z);}
    void out() {printf("%d %d %d\n",x,y,z);}
};
vector<node> ans;

int a[maxn+5];
int b[maxn+5];

int backup[maxn+5],bn;

bool check(int n)
{
    rep(i,1,n) if(a[i]!=b[i]) return 0;
    return 1;
}

void put(int a[],node nn)
{
    a[nn.x]^=1;
    a[nn.y]^=1;
    a[nn.z]^=1;
}

void CK(int n)
{
    rep(i,1,n) a[i]=0;
    for(auto e: ans) put(a,e);
    rep(i,1,n) assert(a[i]==backup[i]);
}

void bf(int n)
{
    node w[20];
    int cnt=0;
    rep(i,1,n) rep(j,i+1,n)
    {
        if(j*2-i<=n) w[++cnt]=node(i,j,j*2-i);
    }
    int N=1<<cnt;
    rep(t,0,N-1)
    {
        rep(i,1,n) b[i]=0;
        rep(i,1,cnt) if(t&(1<<(i-1))) put(b,w[i]);
        if(check(n))
        {
            puts("YES");
            rep(i,1,cnt) if(t&(1<<(i-1))) ans.pb(w[i]);
            printf("%d\n",(int)ans.size());
            for(auto e: ans) e.out();
            CK(n);
            return;
        }
    }
    puts("NO");
}

vector<node> w[(1<<6)+5];
int mark[(1<<6)+5];


int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) backup[i]=a[i];
    bn=n;

    if(n<=7) bf(n);
    else
    {
        vector<node> tmp;
        tmp.pb(node(0,0,0));
        rep(y,0,5) rep(z,y+1,6) tmp.pb(node(y*2-z,y,z));
        for(auto it1: tmp) for(auto it2: tmp)
        {
            rep(i,1,6) b[20+i]=0;
            put(b+20,it1);
            put(b+20,it2);
            int x=0;
            rep(i,0,5) x+=b[21+i]<<i;
            if(mark[x]==0)
            {
                mark[x]=1;
                if(it1.z) w[x].pb(it1);
                if(it2.z) w[x].pb(it2);
            }
        }
        //rep(i,0,(1<<6)-1) if(mark[i]) printf("%d: %d\n",i,w[i].size()); else assert(0);
        while(n>=13)
        {
            n-=6;
            int x=0;
            rep(i,0,5) x+=a[n+1+i]<<i;
            for(auto e: w[x]) put(a+n,e);
            for(auto e: w[x]) ans.pb(e+node(n,n,n));
        }
        node B(-2,-1,0);
        while(n>2)
        {
            if(a[n])
            {
                put(a+n,B);
                ans.pb(node(n,n,n)+B);
            }
            n--;
        }
        node C[3];
        C[0]=node(0,3,6);
        C[1]=node(3,4,5);
        C[2]=node(4,5,6);
        if(a[2]) rep(i,0,2) put(a+2,C[i]),ans.pb(node(2,2,2)+C[i]);
        if(a[1]) rep(i,0,2) put(a+1,C[i]),ans.pb(node(1,1,1)+C[i]);

        puts("YES");
        printf("%u\n",ans.size());
        for(auto e: ans) e.out();

        CK(bn);
    }

    return 0;
}