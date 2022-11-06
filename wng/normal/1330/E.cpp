#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<n; ___I++) scanf("%d", &(X[___I]))  
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;


VI st;
int g,h,mg,mh;

int leaffrom(int i){
        int l=2*i;
        int r=2*i+1;
        if (r<mh){
            if (st[l]>st[r]) return leaffrom(l);
            if (st[l]<st[r]) return leaffrom(r);
        }
        return i;
}

int remove(int i){
        int l=2*i;
        int r=2*i+1;
        if (r<mh){
            if (st[l]>st[r]) {st[i]=st[l]; return remove(l);}
            if (st[l]<st[r]) {st[i]=st[r]; return remove(r);}
        }
        st[i]=0;
        return 0;
}


int main(){
    CASET{
        RII(h,g);
        mg=1<<g;
        mh=1<<h;
        st=VI(mh,0);
        LL r(0);
        REP(i,mh-1){
            RI(st[i+1]);
            r+=st[i+1];
        }
        int nbe=mh-1;
        VI res(0);
        for (int curr=1; curr<mg; curr++){
            while (nbe>=mg){
                int lf=leaffrom(curr);
               // cout<<curr<<" "<<lf<<" "<<mg<<endl;
                if (lf>=mg){
                  //  REP(j,mh) {cout<<st[j+1]<<" ";} cout<<endl;
                    r-=st[curr];
                    remove(curr);
                   // REP(j,mh) {cout<<st[j+1]  <<" ";} cout<<endl;
                    res.PB(curr);          //printf("%d%c", curr,nbe==mg?'\n':' ');
                    nbe--;
                }
                else{
                    break;
                }
            }
        }
        printf("%I64d\n",r);
        REP(i,SZ(res)){
            printf("%d%c", res[i],(i==SZ(res)-1)?'\n':' ');
        }
    }
}