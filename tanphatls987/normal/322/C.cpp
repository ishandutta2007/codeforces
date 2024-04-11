#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=200;

int n,x,y;
ii a[N];
string s;
void solve(){
    n=s.length();
    a[0]=ii(0,0);
    REP(i,0,n){
        a[i+1]=a[i];
        switch (s[i]){
            case 'U':{a[i+1].Y++;break;}
            case 'D':{a[i+1].Y--;break;}
            case 'L':{a[i+1].X--;break;}
            case 'R':{a[i+1].X++;break;}
        }
        //printf("%d %d\n",a[i+1].X,a[i+1].Y);
    }
    //ENDL;
    //printf("tick");
    if (x==0&&y==0) {printf("Yes");return;}
    if (a[n].X==0&&a[n].Y==0){
        FOR(i,1,n) if (x==a[i].X&&y==a[i].Y) {printf("Yes");return;}
    }else{
        int cx,cy;
        if (a[n].X==0){
            REP(i,0,n){
                cx=x-a[i].X,cy=y-a[i].Y;
                if (cx==0&&cy%a[n].Y==0&&cy/a[n].Y>=0) {printf("Yes");return;};
                //printf("%d %d\n",cx,cy);
            }
        }else if (a[n].Y==0){
            REP(i,0,n){
                cx=x-a[i].X,cy=y-a[i].Y;
                if (cy==0&&cx%a[n].X==0&&cx/a[n].X>=0) {printf("Yes");return;};
                //printf("%d %d\n",cx,cy);
            }
        }else{
            REP(i,0,n){
                cx=x-a[i].X,cy=y-a[i].Y;
                if (cx%a[n].X==0&&cy%a[n].Y==0&&(cx/a[n].X==cy/a[n].Y)&&cx/a[n].X>=0) {printf("Yes");return;}
                //printf("%d %d\n",cx,cy);
            }
        }
    }
    printf("No");
}
int main(){
    cin>>x>>y>>s;
    solve();
}