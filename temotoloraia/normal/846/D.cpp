#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=505;
int n,m,k,q;
int a[N][N];
int b1[N][N],b2[N][N];
int c1[N][N],c2[N][N];
deque<int>Q;
int main()
{
    cin>>n>>m>>k>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=-1;
    while (q--){
        int x,y,t;
        cin>>x>>y>>t;
        a[x][y]=t;
    }
    for (int i=1;i<=n;i++){
        while (Q.size()>0)
            Q.pop_back();
        for (int j=1;j<=k;j++){
            while (Q.size()>0 && a[i][Q.back()]<a[i][j])
                Q.pop_back();
            Q.push_back(j);
        }
        b1[i][1]=a[i][Q.front()];
        for (int j=k+1;j<=m;j++){
            if (Q.front()==j-k)
                Q.pop_front();
            while (Q.size()>0 && a[i][Q.back()]<a[i][j])
                Q.pop_back();
            Q.push_back(j);
            b1[i][j-k+1]=a[i][Q.front()];
        }
        while (Q.size()>0)
            Q.pop_back();
        for (int j=1;j<=k;j++){
            while (Q.size()>0 && a[i][Q.back()]>a[i][j])
                Q.pop_back();
            Q.push_back(j);
        }
        c1[i][1]=a[i][Q.front()];
        for (int j=k+1;j<=m;j++){
            if (Q.front()==j-k)
                Q.pop_front();
            while (Q.size()>0 && a[i][Q.back()]>a[i][j])
                Q.pop_back();
            Q.push_back(j);
            c1[i][j-k+1]=a[i][Q.front()];
        }
    }
    for (int i=1;i<=m-k+1;i++){
        while (Q.size()>0)
            Q.pop_back();
        for (int j=1;j<=k;j++){
            while (Q.size()>0 && b1[Q.back()][i]<b1[j][i])
                Q.pop_back();
            Q.push_back(j);
        }
        b2[1][i]=b1[Q.front()][i];
        for (int j=k+1;j<=n;j++){
            if (Q.front()==j-k)
                Q.pop_front();
            while (Q.size()>0 && b1[Q.back()][i]<b1[j][i])
                Q.pop_back();
            Q.push_back(j);
            b2[j-k+1][i]=b1[Q.front()][i];
        }
        while (Q.size()>0)
            Q.pop_back();
        for (int j=1;j<=k;j++){
            while (Q.size()>0 && c1[Q.back()][i]>c1[j][i])
                Q.pop_back();
            Q.push_back(j);
        }
        c2[1][i]=c1[Q.front()][i];
        for (int j=k+1;j<=n;j++){
            if (Q.front()==j-k)
                Q.pop_front();
            while (Q.size()>0 && c1[Q.back()][i]>c1[j][i])
                Q.pop_back();
            Q.push_back(j);
            c2[j-k+1][i]=c1[Q.front()][i];
        }
    }
    int ans=-1;
    for (int i=1;i<=n-k+1;i++)
        for (int j=1;j<=m-k+1;j++)
            if (c2[i][j]+1)
                if (ans==-1 || ans>b2[i][j])
                    ans=b2[i][j];
    cout<<ans<<endl;
    return 0;
}