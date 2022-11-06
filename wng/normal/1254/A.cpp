#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
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


int r,c;

PII numtopair(int i){
    int numrow=i/c;
    int numcol= numrow%2?c-1-i:i;
    return {numrow,numcol};
}

int pairtonum(PII p){
    return p.F*c + (p.F%2?c-1-p.S:p.S);
}

const string alph="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main(){
    DRI(t);
    char s[10002];
    REP(nt,t){
        RII(r,c);
        DRI(k);
        VI res(r*c);
        VI cells(r*c,0);
        int n=r*c;
        int ts=0;
        REP(i,r){
            RS(s);
            REP(j,c){
                if (s[j]=='R') {cells[pairtonum({i,j})]=1; ts++;}
            }
        }
        int cur=0;
        int idp=0;
        //for (auto i:cells) cout<<i<<" "; cout<<endl;
        while (k){
            int toatt=ts/k;
            //cout<<k<<" "<<ts<<" "<<toatt<<" "<<ts<<" "<<cur;
            int nbatt=0;
            int ca=0;
            while (!ca or nbatt<toatt or (cur<n and !cells[cur])) {
                res[cur]=k-1;
                if (cells[cur]) nbatt++;
                cur++;
                ca++;
            }
            //cout<<" "<<ca<<endl;
            ts-=nbatt;
            k--;
        }
        REP(i,r){
            REP(j,c){
                printf("%c",alph[res[pairtonum({i,j})]]);
            }
            printf("\n");
        }
    }
}