#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F(l,r)   ((a[r][r]-a[l-1][r]-a[r][l-1]+a[l-1][l-1])/2)
using namespace std;
const int INF=1e9;
int n,k;
int DP[4005][805],FR[4005][805];
int a[4005][4005];
int I;
void compute (int l, int r, int L, int R){
    if (l>r)return;
    int mid=(l+r)/2;
    for (int i=L;i<=R && i<mid;i++)
        if (DP[mid][I]>DP[i][I-1]+F(i+1,mid)){
            DP[mid][I]=DP[i][I-1]+F(i+1,mid);
            FR[mid][I]=i;
        }
    if (l==r)return;
    compute(l,mid-1,L,FR[mid][I]);
    compute(mid+1,r,FR[mid][I],R);
}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            char ch=getchar();
            while (ch<'0' || ch>'9')ch=getchar();
            a[i][j]=ch-'0';
            //scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++)
            DP[i][j]=INF;
    for (int i=1;i<=n;i++)
        DP[i][1]=F(1,i);
    for (I=2;I<=k;I++)
        compute(1,n,1,n);
    cout<<DP[n][k]<<endl;
    return 0;
}