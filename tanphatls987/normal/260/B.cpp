#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define INPUT freopen("digitsum.inp","r",stdin);
#define OUTPUT freopen("digitsum.out","w",stdout);
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)

using namespace std;

typedef long long ll;

string s;
const int t[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int h[3][13][32]={0},n;
void solve(){
    REP(i,0,n-9){
        bool ok=true;
        int dd=0,mm=0,yy=0;
        FOR(j,0,9){
            if (j==2||j==5){
                if (s[i+j]!='-') {ok=false;break;}
            }else{
                if (s[i+j]=='-') {ok=false;break;}
                if (j<2) dd=10*dd+s[i+j]-'0';else
                {if (j<5) mm=10*mm+s[i+j]-'0';else yy=10*yy+s[i+j]-'0';}
            }
        }
        //printf("%d %d %d\n",dd,yy,mm);
        if (yy<2013||yy>2015) ok=false;
        if (mm<1||mm>12) ok=false;
        if (dd<1||dd>t[mm]) ok=false;
        if (ok) h[yy-2013][mm][dd]++;
    }
    int dd=0,yy=0,mm=0;
    FOR(i,0,2)
        FOR(j,1,12)
            FOR(k,1,t[j]) if (h[yy][mm][dd]<h[i][j][k]) yy=i,mm=j,dd=k;
    if (dd<10) cout<<0;
    cout<<dd<<'-';
    if (mm<10) cout<<0;
    cout<<mm<<'-'<<yy+2013;
}
int main(){
    cin>>s;
    n=s.length();
    solve();
}