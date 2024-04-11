#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("26c.inp","r",stdin)
#define OUTPUT freopen("26c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10;

int n,m,x,y,z,a[N][N];
int main(){
    cin>>n>>m>>x>>y>>z;
    if ((n*m)%2){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int cn=n,cm=m;
    memset(a,-1,sizeof(a));
    if (cn%2){
        if (2*x<cm){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        for(int i=1;2*i<=cm;i++) a[cn][2*i]=a[cn][2*i-1]=24+i%2;
        cn--;
        x-=cm/2;
    }
    if (cm%2){
        if (2*y<cn){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        for(int i=1;2*i<=cn;i++) a[2*i][cm]=a[2*i-1][cm]=24+i%2;
        cm--;
        y-=cn/2;
    }
    x>>=1,y>>=1;
    if (4*(z+x+y)<cn*cm){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;2*i<=cn;i++)
        for(int j=1;2*j<=cm;j++){
            //printf("%d %d %d %d %d\n",i,j,x,y,z);
            if (z){
                a[i*2][j*2]=a[i*2-1][j*2]=a[i*2][j*2-1]=a[i*2-1][j*2-1]=(i+j)%2;
                z--;
            }else if (x){
                int v=j%2;
                a[i*2][j*2]=a[i*2][j*2-1]=3-v;
                a[i*2-1][j*2]=a[i*2-1][j*2-1]=2+v;
                x--;
            }else{
                int v=i%2;
                a[i*2][j*2]=a[i*2-1][j*2]=4+v;
                a[i*2-1][j*2-1]=a[i*2][j*2-1]=5-v;
                y--;
            }
        }
    FOR(i,1,n){
        FOR(j,1,m) printf("%c",'a'+a[i][j]);
        ENDL;
    }
}