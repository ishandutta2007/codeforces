#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= (int)n; ++i)
#define dep(i,a,n) for (int i = a; i >= (int)n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
const int N=11111;
struct zcc{int x,y;}a[N];
int l,m,n,t;
set<pii>S;
bool cmp1(const zcc &a,const zcc &b){return a.x<b.x;}
void divi(int l,int r){
    if(l==r)return;
    int mid=l+r>>1;divi(l,mid);divi(mid+1,r);
    rep(i,l,r)S.insert(mp(a[mid].x,a[i].y));
}
int main()
{
    scanf("%d",&n);rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y),S.insert(mp(a[i].x,a[i].y));
    sort(a+1,a+1+n,cmp1);divi(1,n);
    printf("%d\n",S.size());re(S,set<pii>)printf("%d %d\n",it->X,it->Y);
    return 0;
}