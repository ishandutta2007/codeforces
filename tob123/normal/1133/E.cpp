#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define re return
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)),x.resize(unique(all(x))-x.begin())
#define fi first
#define se second
#define ss second.second
#define sf second.first
#define ff first.first
#define fs first.second
#define sqrt(x) sqrt(abs(x))
#define mp make_pair
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define er erase
#define in insert
#define fo(i,n) for((i)=0;(i)<(n);(i)++)
#define ro(i,n) for((i)=n-1;(i)>=0;(i)--)
#define fr(i,j,n) for((i)=(j);(i)<(n);(i)++)
#define rf(i,j,n) for((i)=((n)-1);(i)>=(j);(i)--)
template <class T> using _tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
#define filename ""
    int a[6000];
    int nex[6000];
    bool was[6000][6000];
    int table[6000][6000];
    int n;
int f(int x,int k)
{
    if (x==n) re 0;
    if (was[x][k]) re table[x][k];
    was[x][k]=1;
    re table[x][k]=max(f(x+1,k),(k>0?f(nex[x],k-1)+nex[x]-x:0));
}
int main()
{
    int k;
    cin>>n>>k;
    int i;
    fo(i,n)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int j=0;
    fo(i,n)
    {
        while(j<n&&a[j]-a[i]<=5)
        {
            j++;
        }
        nex[i]=j;
    }
    cout<<f(0,k);
}