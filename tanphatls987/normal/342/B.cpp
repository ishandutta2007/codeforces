#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=1e5+10;

int n,m,st,en,t,x,y;
int main(){
    scanf("%d%d%d%d",&n,&m,&st,&en);
    int ct=1;
    char dir=(st>en)?'L':'R',mov=(st>en?-1:1);
    FOR(i,1,m){
        scanf("%d%d%d",&t,&x,&y);
//        printf("%d %d\n",i,ct);
        while (st!=en&&ct<t){
            printf("%c",dir);
            st+=mov;ct++;
        }
        if (st!=en) {
            if ((st>=x&&st<=y)||(st+mov>=x&&st+mov<=y)) printf("X");
            else {
                printf("%c",dir);
                st+=mov;
            }
            ct++;
        }else break;
    }
    while (st!=en){
        printf("%c",dir);
        st+=mov;ct++;
    }
}