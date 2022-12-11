#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[2*MAXN],tmp[2*MAXN];
void backup()
{
    for(int i=0;i<2*n;i++) tmp[i]=a[i];
}
void restore()
{
    for(int i=0;i<2*n;i++) a[i]=tmp[i];
}
void apply_a()
{
    for(int i=0;i<n;i++) swap(a[2*i],a[2*i+1]);
}
void apply_b()
{
    for(int i=0;i<n;i++) swap(a[i],a[n+i]);
}
bool check_sorted()
{
    for(int i=0;i<2*n;i++) if(a[i]!=i+1) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",&a[i]);
    backup();
    int ans=INF;
    int res=0;
    for(int i=0;i<=n;i++)
    {
        if(check_sorted()) {ans=min(ans,res); break;}
        apply_a();
        apply_b();
        res+=2;
    }
    res=1;
    restore();
    apply_b();
    for(int i=0;i<=n;i++)
    {
        if(check_sorted()) {ans=min(ans,res); break;}
        apply_a();
        apply_b();
        res+=2;
    }
    res=0;
    restore();
    for(int i=0;i<=n;i++)
    {
        if(check_sorted()) {ans=min(ans,res); break;}
        apply_b();
        apply_a();
        res+=2;
    }
    res=1;
    restore();
    apply_a();
    for(int i=0;i<=n;i++)
    {
        if(check_sorted()) {ans=min(ans,res); break;}
        apply_b();
        apply_a();
        res+=2;
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}