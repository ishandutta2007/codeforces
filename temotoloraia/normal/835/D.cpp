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
const int N=5005;
int DP[N][N];
bool fix[N][N],pal[N][N];
int mas[N];
string s;
int n;
int main() {
    cin>>s;
    n=s.size();
    s="#"+s;
    for (int i=1;i<=n;i++){
        int x;
        x=0;
        while (s[i-x]==s[i+x] && i-x>=1 && i+x<=n){
            pal[i-x][i+x]=1;
            x++;
        }
        x=0;
        while (s[i-x]==s[i+x+1] && i-x>=1 && i+x+1<=n){
            pal[i-x][i+x+1]=1;
            x++;
        }
    }
    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout<<pal[i][j]<<" ";
        cout<<endl;
    }*/
    for (int i=1;i<=n;i++)
        DP[i][i]=1;
    for (int i=1;i<n;i++)
        for (int j=1;j<=n;j++)
            if (pal[j][j+i])
                DP[j][j+i]=DP[j][j+(i-1)/2]+1;
    /*cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout<<DP[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mas[DP[i][j]]++;
    for (int i=n-1;i>=1;i--)
        mas[i]+=mas[i+1];
    for (int i=1;i<=n;i++)
        cout<<mas[i]<<" ";
    return 0;
}