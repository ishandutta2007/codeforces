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

VI ps;

int findp(int i){
    if (ps[i]!=i){
        ps[i]=findp(ps[i]);
    }
    return ps[i];
}

void merge(int i,int j){
    ps[findp(i)]=ps[findp(j)];
}

//On ignore les a et b, ca fait des composantes...
//Puis on mate les a et b, on regarde quelles composantes ont a et b.
//Composante juste a ===>  ja+=nb
//Composante juste b ===>  jb+=nb
//both a and b ===> jab+=nb
//nb de couples de villes qui forcent  passer par les deux = (ja+1)*(jb+1)

int main(){
    DRI(nbt);
    while (nbt--){
        DRII(n,m);
        DRII(a,b);
        a--; b--;
        ps=VI(n);
        REP(i,n){ps[i]=i;}
        VPII badedges(0);
        REP(i,m){
            DRII(x,y);
            x--; y--;
            if ((x-a) and (x-b) and (y-a) and (y-b)) merge(x,y);
            else {if (!(min(a,b)==min(x,y) and max(a,b)==max(x,y))) badedges.PB({x,y});}
        }
        VI trackfriends(n,0);
       // cout<<badedges.size()<<" !!!"<<endl;
        for (auto e:badedges){
            int x,y;
            x=e.F;
            y=e.S;
            if ((x-a) and (x-b)) {swap(x,y);}
            if (x==a) {trackfriends[findp(y)]|=1;}
            if (x==b) {trackfriends[findp(y)]|=2;}
           // cout<<x<<" "<<y<<" "<<trackfriends[findp(y)]<<endl;
        }

        VI nbc(n,0);
        REP(i,n){
            nbc[findp(i)]++;
        }
        int ja(0),jb(0);
        REP(i,n){
            if (nbc[i]){
                if (trackfriends[i]==1) {ja+=nbc[i];}
                if (trackfriends[i]==2) {jb+=nbc[i];}
            }
        }
      //  for (auto i: trackfriends) cout<<i<<" "; cout<<endl;
      //  for (auto i: ps) cout<<i<<" "; cout<<endl;
      //  for (auto i: nbc) cout<<i<<" "; cout<<endl;
        LL res=(LL)(ja)*(jb);
        printf("%I64d\n",res);
    }

}