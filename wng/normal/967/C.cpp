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

const int inf = 200000000;


int main(){
    int n,m,cl,ce,v;
    RIII(n,m,cl);RII(ce,v);
    VI s(cl);
    map<int,int> stairs;
    REP(i,cl){
        RI(s[i]);
        stairs[s[i]]=i;
    }
    VI e(ce);
    map<int,int> elev;
    REP(i,ce){
        RI(e[i]);
        elev[e[i]]=i;
    }
    
    int q;
    RI(q);
    REP(i,q){
        int x1,y1,x2,y2;
        RII(x1,y1);RII(x2,y2);
        if (x1==x2) { printf("%d\n",abs(y1-y2));}
        else {
            int eby1,eby2,eay1,eay2;
            auto elb1=elev.lower_bound(y1);
            if (elb1!=elev.end()){
            eay1=elb1->F;}
            else {eay1=inf;}
            if (elb1!=elev.begin())
            {
                elb1--;
            eby1=elb1->F;
            }
            else {
            eby1=-inf;
            }
            auto elb2=elev.lower_bound(y2);
            if (elb2!=elev.end()){
            eay2=elb2->F;}
            else {eay2=inf;}
            if (elb2!=elev.begin())
            {
                elb2--;
            eby2=elb2->F;
            }
            else {
            eby2=-inf;
            }
            int res=2*inf;
            int travel=((abs(x1-x2)-1)/v+1);
            res=min(res,travel+abs(y1-eay1)+abs(y2-eay1));
            res=min(res,travel+abs(y1-eay2)+abs(y2-eay2));
            res=min(res,travel+abs(y1-eby1)+abs(y2-eby1));
            res=min(res,travel+abs(y1-eby2)+abs(y2-eby2));
           // cout<<eay1<<" "<<eay2<<" "<<eby1<<" "<<eby2<<" "<<res<<endl;
            //Le meme pour les escaliers
            
            int sby1,sby2,say1,say2;
            auto slb1=stairs.lower_bound(y1);
            if (slb1!=stairs.end()){
            say1=slb1->F;}
            else {say1=inf;}
            if (slb1!=stairs.begin())
            {
                slb1--;
            sby1=slb1->F;
            }
            else {
            sby1=-inf;
            }
            auto slb2=stairs.lower_bound(y2);
            if (slb2!=stairs.end()){
            say2=slb2->F;}
            else {say2=inf;}
            if (slb2!=stairs.begin())
            {
                slb2--;
            sby2=slb2->F;
            }
            else {
            sby2=-inf;
            }
            int travels=abs(x1-x2);
            res=min(res,travels+abs(y1-say1)+abs(y2-say1));
            res=min(res,travels+abs(y1-say2)+abs(y2-say2));
            res=min(res,travels+abs(y1-sby1)+abs(y2-sby1));
            res=min(res,travels+abs(y1-sby2)+abs(y2-sby2));
            //cout<<say1<<" "<<say2<<" "<<sby1<<" "<<sby2<<" "<<res<<endl;
            
            printf("%d\n",res);
        }
    }
    
 
}