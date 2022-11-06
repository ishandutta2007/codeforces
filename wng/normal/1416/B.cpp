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
    CASET{
        DRI(n);
        DRVI(n,a);
        int s=0;
        REP(i,n) s+=a[i];
        vector<pair<int,PII>> ops(0);

        if (s%n){
            printf("-1\n");
            continue;
        }
        int avg=s/n;

        VI nbtz(n);
        VPII sv(0);
        REP(i,n){
            nbtz[i]=(i+1-a[i]%(i+1))%(i+1);
            if (i) sv.PB({nbtz[i],i});
        }
        
        sort(ALL(sv));

        int ij=0;
        int mh=-1;
        while (ij<n-1)
        {
            while (ij<n-1){
                if (sv[ij].F<=a[0]){
                    int w=sv[ij].S;
                    int hm=sv[ij].F;
                    if (a[w]){
                        if (a[w]%(w+1)){
                            ops.PB({hm,{1,w+1}});
                            a[w]+=hm;
                            a[0]-=hm;
                        }  
                        int x=a[w]/(w+1);
                        ops.PB({x,{w+1,1}});
                        a[0]+=a[w];
                        a[w]=0;
                    }
                    ij++;
                }
                else { mh=sv[ij].F-a[0]; break;}
            }
            if (ij<n-1){
                VPII rs;
                REPP(i,1,n){
                    if (a[i]/(i+1)){
                        rs.PB({-(a[i]/(i+1))*(i+1), i});
                    }
                }
                sort(ALL(rs));
                int i=0;
                while (mh>0){
                    if (i<SZ(rs)){
                        mh-=rs[i].F;
                        int w=rs[i].S;
                        int x=a[w]/(w+1);
                        ops.PB({x, {w+1,1}});
                        a[0]+=x*(w+1);
                        a[w]%=w+1;
                        
                    i++;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                if (mh>0){
                    break;
                }
            }
        }
        if (ij<n-1){
            printf("-1\n");
            continue;
        }
        if (avg)
            REPP(i,1,n){
                ops.PB({avg,{1,i+1}});
            }

        int nn=SZ(ops);
        if (nn>3*n){
            printf("-1\n");
            continue;
        }
        printf("%d\n",nn);
        REP(i,nn){
            printf("%d %d %d\n",ops[i].S.F, ops[i].S.S, ops[i].F);
        }
    }

}