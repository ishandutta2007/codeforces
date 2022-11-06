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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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
        map<int,int> sc;
        sc[a[0]]++;
        sc[a[n-1]]++;
        sc[n+1]++;
        sc[n+2]++;
        int nbtp=0;
        REP(i,n-1){
            if (a[i]==a[i+1]){
                sc[a[i]]+=2;
                nbtp++;
            }
        }
        priority_queue<int, VI> q;
        for (auto m: sc){
            q.emplace(m.S);
            //cout<<m.F<<","<<m.S<<endl;
        }
         //cout<<endl;
        int mostcol=-1;
        int mostrep=0;
        for (auto m:sc){
            if (m.S>mostrep) {
                mostrep	=m.S;
                mostcol = m.F;
            }
        }
        int posplit=0;
        REP(i,n-1){
            if (a[i]!=a[i+1] and a[i]!=mostcol and a[i+1]!=mostcol) posplit++;
        }
        int res=nbtp;
        nbtp+=2;
        while (nbtp){
             //cout<<"ps "<<posplit<<" "<<nbtp<<" "<<res<<endl;
            if (SZ(q)==1){
                //et merde
                //cout<<"choosing "<<nbtp<<" "<<posplit<<endl;
                if (posplit>=nbtp){
                    res+=nbtp;
                    break;
                }
                else
                {
                    res=-1;
                    break;
                }
            }
            else{
                int a=q.top()-1;
                q.pop();
                int b=q.top()-1;
                //cout<<"puhing "<<a<<" "<<b<<endl;
                q.pop();
                if (a) q.push(a);
                if (b) q.push(b);
                nbtp--;
            }
        }
        printf("%d\n", res);
    }
}