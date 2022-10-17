#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[15][15],id[15][15],nxt[105];
double ans[110][2];
int main()
{
    for(int i=1;i<=10;++i)
        for(int j=1;j<=10;++j)
            cin>>a[i][j];
    int tot = 100, f = 1;
    for(int i=1;i<=10;++i)
    {
        if(f == 1) for(int j=1;j<=10;++j) id[i][j] = tot--;
        else for(int j=10;j>=1;--j) id[i][j] = tot--;
        f = -f;
        for(int j=1;j<=10;++j)
            if(a[i][j]) nxt[id[i][j]] = id[i-a[i][j]][j];
    }
    for(int i=99;i>=94;--i) ans[i][0]=ans[i][1]=6;
    for(int i=94;i>=1;--i)
    {
        double sum = 0;
        for(int j=i+1;j<=i+6;++j) sum += ans[j][1];
        ans[i][0] = ans[i][1] = sum / 6 + 1;
        if(nxt[i]) ans[i][1] = min(ans[i][1], ans[nxt[i]][0]);
    }
    cout << fixed << setprecision(10) << ans[1][1] << endl;
}