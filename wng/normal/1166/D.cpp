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

int main(){
    DRI(q);
    REP(numtest,q){
        LL a,b,m;
        scanf("%I64d%I64d%I64d",&a,&b,&m);
        LL nbt=1;
        if (a==b) {printf("1 %I64d\n",a); continue;}
        LL tocomp=b-(a+1)*nbt;
        int zz=1;
        bool isok=false;
        while (!isok and tocomp>=0){
            //cout<<nbt<<" "<<tocomp<<endl;
            if (tocomp<=(m-1)*(nbt)) {
                VL res(zz+1,1);
                res[0]=a;
                nbt>>=1;
                int k=1;
                while (nbt){
                    if (tocomp>=nbt){
                        LL trm=min(tocomp/nbt,m-1);
                        res[k]+=trm;
                        tocomp-=trm*nbt;
                    }
                    nbt>>=1;
                    k++;
                }
                if (tocomp>0) {res[k]+=tocomp;}
                assert(tocomp<=m-1);
        //        for (auto kk: res) {cout<<kk<<" ";} cout<<endl;
                printf("%d ",k+1);
                printf("%I64d",a);
                LL vb=a;
                LL sum=a;
                REPP(j,1,k+1){
                    vb=sum+res[j];
                    sum+=vb;
                    printf(" %I64d",vb);
                }
                assert(vb==b);
                printf("\n");
                isok=true;
            }
            nbt<<=1;
            zz++;
            tocomp=b-(a+1)*nbt;
        }
        if (!isok) {printf("-1\n");}
    }
}