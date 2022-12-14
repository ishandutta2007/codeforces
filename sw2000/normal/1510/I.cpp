#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1000 + 10;
const int mod = 1e9 + 7;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double rnd(double l, double r){return uniform_real_distribution<double>(l,r)(rng);}
//int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}

int n,m,lose[N];
int main()
{
	cin>>n>>m;
	while(m--)
    {
        string s;cin>>s;
        double w[2]{};
        int ma=0,mi=inf;
        bool now=0;
        for(int i=0;i<n;i++)ma=max(ma,lose[i]),mi=min(mi,lose[i]);
        for(int i=0;i<n;i++)
        {
            int add=0;
            if(lose[i]==mi)add=100;
            else add=max(add,60-(lose[i]-mi));
            w[s[i]-'0']+=add;
        }
        if(rnd(0,w[0]+w[1])>w[0])now=1;
        cout<<now<<endl;
        cin>>now;
        for(int i=0;i<n;i++)if(s[i]-'0'!=now)lose[i]++;
    }
	return 0;
}