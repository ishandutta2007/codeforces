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
    DRII(nb0,nb1);
    DRII(nb2,nb3);
    if (nb0){
        nb1-=nb0-1;
        if (nb3){
            nb2-=nb3-1;
            if (min(nb2,nb1)>=1 and abs(nb2-nb1)<=1){
                //OK
                printf("YES\n");
                if (nb1>nb2) {printf("1 "); nb1--;}
                printf("0 ");
                REP(i,nb0-1) printf("1 0 ");
                REP(i,nb1) printf("1 2 ");
                REP(i,nb3-1) printf("3 2 ");
                printf("3");
                if (nb2>nb1) printf(" 2");
            }
            else{
                printf("NO");
            }
        }
        else{
            if (nb2<=nb1 and nb2+2>=nb1){
                //OK
                printf("YES\n");
                if (nb1>nb2) {printf("1 "); nb1--;}
                printf("0 ");
                REP(i,nb0-1) printf("1 0 ");
                REP(i,nb2) {printf("1 2"); if (i<nb2-1) printf(" ");}
                if (nb1>nb2) {printf(" 1"); nb1--;}
            }
            else{
                //NOK
                printf("NO");
            }
        }
    }
    else{
        if (nb3){
            nb2-=nb3-1;
            if (nb2>=nb1 and nb1+2>=nb2){
                //OK
                printf("YES\n");
                if (nb1<nb2) {printf("2 "); nb2--;}
                REP(i,nb1) printf("1 2 ");
                REP(i,nb3-1) printf("3 2 ");
                printf("3");
                if (nb2>nb1) printf(" 2");
            }
            else{
                //NOK
                printf("NO");
            }
        }
        else{
            if (abs(nb1-nb2)<=1){
                //OK
                printf("YES\n");
                if (nb2>nb1) printf("2 ");
                REP(i,min(nb1,nb2)) {printf("1 2"); if (i<min(nb1,nb2)-1) printf(" ");}
                if (nb2<nb1) {if (min(nb1,nb2)) printf(" "); printf("1");}
            }
            else{
                //NOK
                printf("NO");
            }
        }
    }
    printf("\n");
}