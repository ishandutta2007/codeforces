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

    LL score(int a, int b, int c){
        return ((LL)a-b)*((LL)a-b)+((LL)a-c)*((LL)a-c)+((LL)c-b)*((LL)c-b);
    }

    int main(){
        CASET{
            set<int> x,y,z;
            DRIII(n1,n2,n3);
            REP(i,n1){
                DRI(a);
                x.insert(a);
                
            }
            REP(i,n2){
                DRI(a);
                y.insert(a);
            }
            REP(i,n3){
                DRI(a);
                z.insert(a);
            }   
            LL minres=1LL<<62;
            //cout<<minres<<endl;

            for (auto k:x){
                auto ab= y.lower_bound(k);
                auto aa=ab;
                if (aa!=y.begin()) ab--;
                if (aa==y.end()) aa--;
                auto bb= z.lower_bound(k);
                auto ba=bb;
                if (bb!=z.begin()) bb--;
                if (ba==z.end()) ba--;
                
                bool isaeq=false;
                bool isbeq=false;
                if (*aa==k){
                    isaeq=true;
                    aa++;
                }
                if (*ba==k){
                    isbeq=true;
                    ba++;
                }
                if (ba==z.end()) ba--;
                if (aa==y.end()) aa--;
                if (isaeq and isbeq) {minres=0; break;}
                if (isaeq) {
                    minres=min(minres,score(k,k,*ba));
                    minres=min(minres,score(k,k,*bb));
                }
                if (isbeq) {
                    minres=min(minres,score(k,k,*aa));
                    minres=min(minres,score(k,k,*ab));
                }

                minres=min(minres,score(k,*ab, *ba));
                minres=min(minres,score(k,*bb, *aa));

            }
 
            for (auto k:y){
                auto ab= x.lower_bound(k);
                auto aa=ab;
                if (aa!=x.begin()) ab--;
                if (aa==x.end()) aa--;
                auto bb= z.lower_bound(k);
                auto ba=bb;
                if (bb!=z.begin()) bb--;
                if (ba==z.end()) ba--;
                
                bool isaeq=false;
                bool isbeq=false;
                if (*aa==k){
                    isaeq=true;
                    aa++;
                }
                if (*ba==k){
                    isbeq=true;
                    ba++;
                }
                if (ba==z.end()) ba--;
                if (aa==x.end()) aa--;
                if (isaeq and isbeq) {minres=0; break;}
                if (isaeq) {
                    minres=min(minres,score(k,k,*ba));
                    minres=min(minres,score(k,k,*bb));
                }
                if (isbeq) {
                    minres=min(minres,score(k,k,*aa));
                    minres=min(minres,score(k,k,*ab));
                }

                minres=min(minres,score(k,*ab, *ba));
                minres=min(minres,score(k,*bb, *aa));

            }

            for (auto k:z){
                auto ab= y.lower_bound(k);
                auto aa=ab;
                if (aa!=y.begin()) ab--;
                if (aa==y.end()) aa--;
                auto bb= x.lower_bound(k);
                auto ba=bb;
                if (bb!=x.begin()) bb--;
                if (ba==x.end()) ba--;
                
                bool isaeq=false;
                bool isbeq=false;
                if (*aa==k){
                    isaeq=true;
                    aa++;
                }
                if (*ba==k){
                    isbeq=true;
                    ba++;
                }
                if (aa==y.end()) aa--;
                if (ba==x.end()) ba--;
                if (isaeq and isbeq) {minres=0; break;}
                if (isaeq) {
                    minres=min(minres,score(k,k,*ba));
                    minres=min(minres,score(k,k,*bb));
                }
                if (isbeq) {
                    minres=min(minres,score(k,k,*aa));
                    minres=min(minres,score(k,k,*ab));
                }

                minres=min(minres,score(k,*ab, *ba));
                minres=min(minres,score(k,*bb, *aa));

            }

            printf("%I64d\n",minres);

        }

    }