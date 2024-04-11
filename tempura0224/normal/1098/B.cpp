#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
string agct[]={"ACGT","ACTG","AGCT","AGTC","ATCG","ATGC",
"CAGT","CATG","GACT","GATC","TACG","TAGC",
"CGAT","CTAG","GCAT","GTAC","TCAG","TGAC",
"CGTA","CTGA","GCTA","GTCA","TCGA","TGCA"};
int main(){
    int n,m;
    cin>>n>>m;
    string s[n];
    rep(i,n)cin>>s[i];
    int ans=inf,idx=0;
    rep(i,24){
        int cnt=0;
        rep(j,n)rep(k,m){
            if(j%2){
                if(s[j][k]!=agct[i][(k+2)&3])++cnt;
            }
            else {
                if(s[j][k]!=agct[i][k&3])++cnt;
            }
        }
        if(cnt<ans){
            ans=cnt;
            idx=i;
        }
    }
    rep(i,24){
        int cnt=0;
        rep(j,n){
            int cnt1=0,cnt2=0;
            rep(k,m){
                if(j&1){
                    if(s[j][k]!=agct[i][k&1])++cnt1;
                    if(s[j][k]!=agct[i][(k+1)&1])++cnt2;
                }
                else {
                    if(s[j][k]!=agct[i][k%2+2])++cnt1;
                    if(s[j][k]!=agct[i][(k+1)%2+2])++cnt2;
                }
            }
            cnt+=min(cnt1,cnt2);
        }
        if(cnt<ans){
            ans=cnt;
            idx=100+i;
        }
    }

    rep(i,24){
        int cnt=0;
        rep(j,m){
            int cnt1=0,cnt2=0;
            rep(k,n){
                if(j&1){
                    if(s[k][j]!=agct[i][k&1])++cnt1;
                    if(s[k][j]!=agct[i][(k+1)&1])++cnt2;
                }
                else {
                    if(s[k][j]!=agct[i][k%2+2])++cnt1;
                    if(s[k][j]!=agct[i][(k+1)%2+2])++cnt2;
                }
            }
            cnt+=min(cnt1,cnt2);
        }
        if(cnt<ans){
            ans=cnt;
            idx=200+i;
        }
    }
    string ret[n][m];
    if(idx>=200){
        int i=idx-200;
        rep(j,m){
            int cnt1=0,cnt2=0;
            if(j&1){
                rep(k,n){
                    if(s[k][j]!=agct[i][k&1])++cnt1;
                    if(s[k][j]!=agct[i][(k+1)&1])++cnt2;
                }
                if(cnt1<=cnt2)rep(k,n)s[k][j]=agct[i][k&1];
                else rep(k,n)s[k][j]=agct[i][(k+1)&1];
            }
            else {
                rep(k,n){
                    if(s[k][j]!=agct[i][k%2+2])++cnt1;
                    if(s[k][j]!=agct[i][(k+1)%2+2])++cnt2;
                }
                if(cnt1<=cnt2)rep(k,n)s[k][j]=agct[i][k%2+2];
                else rep(k,n)s[k][j]=agct[i][(k+1)%2+2];
            }
        }
    }
    else if(idx>=100){
        int i=idx-100;
        rep(j,n){
            int cnt1=0,cnt2=0;
            if(j&1){
                rep(k,m){
                    if(s[j][k]!=agct[i][k&1])++cnt1;
                    if(s[j][k]!=agct[i][(k+1)&1])++cnt2;
                }
                if(cnt1<=cnt2)rep(k,m)s[j][k]=agct[i][k&1];
                else rep(k,m)s[j][k]=agct[i][(k+1)&1];
            }
            else {
                rep(k,m){
                    if(s[j][k]!=agct[i][k%2+2])++cnt1;
                    if(s[j][k]!=agct[i][(k+1)%2+2])++cnt2;
                }
                if(cnt1<=cnt2)rep(k,m)s[j][k]=agct[i][k%2+2];
                else rep(k,m)s[j][k]=agct[i][(k+1)%2+2];
            }
        }
    }

    else{
        int i=idx;
        rep(j,n)rep(k,m){
            if(j%2){
                s[j][k]=agct[i][(k+2)&3];
            }
            else {
                s[j][k]=agct[i][k&3];
            }
        }
    }
    rep(i,n)cout<<s[i]<<"\n";
    return 0;
}