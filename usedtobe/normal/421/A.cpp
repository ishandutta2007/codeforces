#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<string>
#include<vector>
using namespace std;
#define INF 2000000000
#define Clear(x, Num) memset(x, Num, sizeof(x))
#define Dig(x) ((x>='0') && (x<='9'))
#define Neg(x) (x=='-')
#define G_c() getchar()
typedef long long ll;

int n, a, b, tmp;
int v[110];

inline int gcd(int x, int y) { if (!y) return x; return gcd(y, x%y); }
inline int read(int &x){ char ch; int N=1; while ((ch=G_c()) && (!Dig(ch)) && (!Neg(ch))); if (Neg(ch)) { N=-1; while ((ch=G_c()) && (!Dig(ch))); } x=ch-48; while ((ch=G_c()) && (Dig(ch))) x=x*10+ch-48; x*=N; }
//inline void Insert(int u, int v) { To[Cnt]=v; Next[Cnt]=Head[u]; Head[u]=Cnt++; }

int main()
{
    read(n); read(a); read(b);
    for (int i=1; i<=a; i++)
    { read(tmp), v[tmp]=1; }
    for (int i=1; i<=b; i++)
    { read(tmp); if (!v[tmp]) v[tmp]=2; }
    for (int i=1; i<=n; i++) printf("%d ", v[i]);
}