#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005;
int n,x;
int a[N];
int main() {
    cin>>n>>x;
    for (int i = 1; i <= n; i++){
        int y;
        cin>>y;
        a[y]++;
    }
    int ans=0;
    for (int i=0;i<x;i++)
        if (a[i]==0)
            ans++;
    ans+=a[x];
    cout<<ans<<endl;
	return 0;
}