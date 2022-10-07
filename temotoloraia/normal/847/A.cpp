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
int n;
int l[N], r[N];
int np,mas[N];
void dfs (int k){
    mas[++np]=k;
    if (r[k])
        dfs(r[k]);
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>l[i]>>r[i];
    for (int i=1;i<=n;i++)
        if (l[i]==0)
            dfs(i);
    for (int i=1;i<n;i++)
        r[mas[i]]=mas[i+1];
    for (int i=2;i<=n;i++)
        l[mas[i]]=mas[i-1];
    for (int i=1;i<=n;i++)
        cout<<l[i]<<" "<<r[i]<<endl;
	return 0;
}