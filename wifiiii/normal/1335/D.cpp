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

char a[10][10];
int main()
{
    int n=9;
    int t;
    cin>>t;
    while(t--)
    {
        ii ji cin>>a[i][j];
        a[1][1]=a[1][2],a[2][4]=a[2][5],a[3][7]=a[3][8];
        a[4][2]=a[4][3],a[5][5]=a[5][6],a[6][8]=a[6][9];
        a[7][3]=a[7][2],a[8][6]=a[8][5],a[9][9]=a[9][8];
        ii {ji cout<<a[i][j];cout<<endl;}
    }
}