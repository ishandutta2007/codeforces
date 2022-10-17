#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1e9+7;
int a[105];
int main()
{
    int n,k;
    cin>>n>>k;
    int sum = 0;
    for(int i=1;i<=n;++i) cin>>a[i],sum+=a[i];
    int ans = -1;
    for(int i=1;i<=k;++i)
    {
        int temp = 0;
        for(int j=i;j<=n;j+=k)
        {
            temp += a[j];
        }
        ans = max(ans,abs(sum-temp));
    }
    cout <<ans <<endl;
}