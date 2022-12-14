#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=2e5+10;
const ll mod=998244353;

int arr[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
    int n,ma=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        printf("%d ",ma+a);
        ma=max(ma,ma+a);
    }

	return 0;
}