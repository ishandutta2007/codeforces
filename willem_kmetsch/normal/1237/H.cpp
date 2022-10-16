#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=4000+5;
const int M=1e5+5;
const int mod=998244353;
int read(){int x=0;char ch=getchar();while(ch>'9'||ch<'0'){ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,m,k;
char s[N],t[N];
int a[N],b[N];
int c1,c2,c3;
unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
vector<int> ans;
vector<int> p;
void rev(int x)
{
    ans.push_back(x*2);reverse(a+1,a+x+1);
    for (int i=1;i<=x;i++) if (a[i]==1 || a[i]==2) a[i]=3-a[i];
}
void DOIT()
{
    scanf("%s",s+1);scanf("%s",t+1);
    n=strlen(s+1);n/=2;
    c1=c2=c3=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i*2-1]=='0' && s[i*2]=='0') a[i]=0;
        if (s[i*2-1]=='0' && s[i*2]=='1') a[i]=1;
        if (s[i*2-1]=='1' && s[i*2]=='0') a[i]=2;
        if (s[i*2-1]=='1' && s[i*2]=='1') a[i]=3;
        if (t[i*2-1]=='0' && t[i*2]=='0') b[i]=0;
        if (t[i*2-1]=='0' && t[i*2]=='1') b[i]=1;
        if (t[i*2-1]=='1' && t[i*2]=='0') b[i]=2;
        if (t[i*2-1]=='1' && t[i*2]=='1') b[i]=3;
        if (a[i]==0) c1++;else if (a[i]==3) c2++;else c3++;
        if (b[i]==0) c1--;else if (b[i]==3) c2--;else c3--;
    }
    if (c1!=0 || c2!=0 || c3!=0) {puts("-1");return;}
    ans.clear();
    for (int i=n;i>=1;i--)
    {
        if (a[i]==b[i]) continue;
        if (a[1]==b[i] && (a[1]==0 || a[1]==3)) {rev(i);continue;}
        if (a[1]==3-b[i] && (a[1]==1 || a[1]==2)) {rev(i);continue;}
        p.clear();for (int j=1;j<=i;j++) if (a[j]==b[i]) p.push_back(j);
        if (p.size())
        {
            int P=rnd()%p.size();P=p[P];
            rev(P);rev(i);
        } else 
        {
            for (int j=1;j<=i;j++) if (a[j]==3-b[i]) p.push_back(j);
            int P=rnd()%p.size();P=p[P];
            rev(P);rev(1);rev(i);
        }
    }
    cout<<ans.size()<<"\n";
    for (int x:ans) cout<<x<<" ";cout<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}


/* 
*/