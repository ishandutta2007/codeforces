#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define inf 0x3f3f3f3f
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
const ll Mod=998244353;
#define maxn 105
using namespace std;
int main()
{
    sync
    double h,l;
    cin>>h>>l;
    printf("%.12lf",(l*l-h*h)/2/h);
    cout<<endl;
}