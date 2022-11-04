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
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
const int maxn=8010;
struct node
{
    int l,r;
}a[105];
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<min(k-1,n-k)+3*n<<endl;
    return 0;
}