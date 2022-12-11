#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> lli;

#define X first
#define Y second

const int N=1e5+10,M=350;
const int alp=26;

const ll inf=1e16;

int n,a[N];
int f[M][N];

int solve(int pos,int val){
    if (pos>n) return 0;
    if (val>=M) return 1+solve(pos+a[pos]+val,val);
    return f[val][pos];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int j=1;j<M;j++)
        for(int i=n;i>=1;i--){
            int pos=i+a[i]+j;
            f[j][i]=(pos>n)?1:f[j][pos]+1;
        }
    int m;
    scanf("%d",&m);
    while (m--){
        int pos,val;
        scanf("%d%d",&pos,&val);
        printf("%d\n",solve(pos,val));
    }
}