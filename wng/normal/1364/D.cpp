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


int main(){
    DRIII(n,m,k);
    vector<VI> cs(n,VI(0));
    REP(i,m){
        DRII(x,y);
        x--;
        y--;
        cs[x].PB(y);
        cs[y].PB(x);
    }
    int p=0;
    queue<PII> q;
    VI cols(n,-1);
    VI ps(n,-1);
    q.push({0,0});
    VI nb(2,0);
    PII ennemis={-1,-1};
    bool isok=true;
    while (isok and p<k){
        PII nx=q.front();
        int v=nx.F;
        int t=nx.S;
        q.pop();
        cols[v]=t;
        nb[t]++;
        //cout<<"assign "<<t<<" to "<<v<<endl;
        for (auto c: cs[v]){
            if (cols[c]==cols[v]){
                //J'ai fini
                //cout<<c<<" "<<v<<" "<<cols[c]<<" "<<cols[v]<<endl;
                ennemis={c,v};
                isok=false;
                break;
            }
            if (c!=0 and ps[c]==-1){
                ps[c]=v;
                q.push({c,1-t});
            }
        }
        p++;
    }
    if (isok){
        printf("1\n");
        int left =(k-1)/2+1;
        if (nb[0]>=left){
            REP(i,n){
                if (cols[i]==0) {printf("%d ",i+1); left--;}
                if (!left) break;
            }
        }
        else {
            REP(i,n){
                if (cols[i]==1) {printf("%d ",i+1); left--;}
                if (!left) break;
            }
        }
        printf("\n");
    }
    else{
        VI r1(1,ennemis.F);
        int sr1=1;
        while (r1[sr1-1]!=0) {
            int nw=ps[r1[sr1-1]];
            r1.PB(nw);
            sr1++;
        }
        VI r2(1,ennemis.S);
        int sr2=1;
        while (r2[sr2-1]!=0) {
            int nw=ps[r2[sr2-1]];
            r2.PB(nw);
            sr2++;
        }
        while (min(sr1,sr2)>1 and r1[sr1-2]==r2[sr2-2]) {sr1--; sr2--;}

        VI res(0);
        REP(i,sr1) {res.PB(r1[i]);}

        for (int i=sr2-2; i>=0;i--){
            res.PB(r2[i]);
        }
       /* for (auto i:r1){
            cout<<i<<" ";
        }
        cout<<"was r1"<<endl;
        for (auto i:r2){
            cout<<i<<" ";
        }
        cout<<"was r2"<<endl;*/
        printf("2\n");
        printf("%d\n",SZ(res));
        REP(i,SZ(res)){
            printf("%d ",res[i]+1);
        }
        printf("\n");
       /* for (auto i:ps){
            cout<<i<<" ";
        }
        cout<<endl;*/
    }
}