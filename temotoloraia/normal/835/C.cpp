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
using namespace std;
const int N=100005;
int n,Q,C;
int mas[20][105][105];
int a[N],b[N],s[N];
int X1,Y1,X2,Y2,t;
int ans;
int main() {
    cin>>n>>Q>>C;
    C++;
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&s[i]);
    for (int i=0;i<C;i++){
        for (int j=1;j<=n;j++){
            mas[i][a[j]][b[j]]+=(s[j]+i)%C;
        }
        for (int j=1;j<=100;j++)
            for (int l=1;l<=100;l++)
                mas[i][j][l]+=mas[i][j][l-1]+mas[i][j-1][l]-mas[i][j-1][l-1];
    }
    while (Q--){
        scanf("%d%d%d%d%d",&t,&X1,&Y1,&X2,&Y2);
        t%=C;
        //cout<<t<<" "<<X1<<" "<<X2<<" "<<Y1<<" "<<Y2<<" ";
        ans=mas[t][X2][Y2]-mas[t][X1-1][Y2]-mas[t][X2][Y1-1]+mas[t][X1-1][Y1-1];
        printf("%d\n",ans);
    }
    return 0;
}