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
        DRI(n);
        VL a(n);
        vector<VI> fams(60,VI(0));
        REP(i,n) {
           scanf("%lld",&(a[i]));
            }
        VL dpi(60);
        REP(i,60) {dpi[i]=(LL)1<<i;}
        REP(i,n){
            REP(j,60){
                if (a[i]&dpi[j]) {
                //    cout<<"ok "<<a[i]<<" "<<dpi[j]<<" "<<j<<endl;
                    if (fams[j].size()==2){
                        //print que c bon
                        printf("3\n");
                        return 0;
                    }
                    else{
                        fams[j].PB(i);
                    }
                }
            }
        }
        //le cycle passe forcment uniquement par des familles de 2 noeuds. Chaque noeud doit appartenir  au moins deux familles de deux mecs
     
        map<int,set<int>> m; // les familles des mecs
        map<int,int> numerocand; //on number les nodes cool
        int nc=0;
        REP(i,60){
            if (fams[i].size()==2){
                for (auto j: fams[i]){m[j].insert(i);
                    if (numerocand.find(j)==numerocand.end()) {numerocand[j]=nc++;}
                }
            }
        }
        /*
        bool cont=true;
        while (cont){
            cont=false;
            REP(i,)
        } */
        vector<VI> sp(nc,VI(nc,10000));
        REP(i,nc) {sp[i][i]=0;}
        int res=10000;
     
     
    //    cout<<"nc = "<<nc<<endl;
        REP(i,60){
      //      printf("%d ",fams[i].size());
            if (fams[i].size()==2){
                int c1=numerocand[fams[i][0]];
                int c2=numerocand[fams[i][1]];
                if (sp[c1][c2]==1) continue;
                if (sp[c1][c2]+1<res){
                        res=sp[c1][c2]+1;
                    }
                sp[c1][c2]=1;
                sp[c2][c1]=1;
                REP(ii,nc){
                    REPP(j,ii+1,nc){
                        sp[ii][j]=min(min(sp[ii][j],sp[ii][c1]+sp[j][c2]+1),sp[ii][c2]+sp[j][c1]+1);
                        sp[j][ii]=sp[ii][j];
                    }
                }
               /* cout<<"I processed "<<c1<<" and "<<c2<<endl;
        REP (pi,nc){
            REP(pj,nc){
                cout<<sp[pi][pj]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
            }
        }
     
     
        if (res<10000){
            printf("%d\n",res);
        }
        else{
            printf("-1\n");
        }
    }