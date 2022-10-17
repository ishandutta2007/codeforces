#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[505][505];
int main()
{
    a[1][1]=4,a[1][2]=8,a[1][3]=7;
    a[2][1]=2,a[2][2]=3,a[2][3]=6;
    a[3][1]=1,a[3][2]=5,a[3][3]=9;
    int n;
    cin>>n;
    if(n<=2) return cout<<-1<<endl,0;
    for(int k=4;k<=n;++k)
    {
        int tp=0;
        for(int i=1;i<=k;++i)
        {
            ++tp;
            a[i][k] = k&1?2*k-tp:tp;
        }
        for(int i=k-1;i>=1;--i)
        {
            ++tp;
            a[k][i] = k&1?2*k-tp:tp;
        }
    }
    int sum = 0;
    for(int k=n;k>=4;--k)
    {
        for(int i=1;i<=k;++i) a[i][k] += sum;
        for(int i=k-1;i>=1;--i) a[k][i] += sum;
        sum += 2*k-1;
    }
    for(int i=1;i<=3;++i) for(int j=1;j<=3;++j) a[i][j]+=sum;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}