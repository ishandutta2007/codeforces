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
    VI ps;
     
    int findp(int i){
        if (ps[i]!=i) ps[i]=findp(ps[i]);
        return ps[i];
    }
     
    void merge(int i,int j){
        i=findp(i);
        j=findp(j);
        if (i!=j) ps[j]=i;
    }
     
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        VI mxr(n,-1);
        VI mnr(n,m);
        VI mxc(m,-1);
        VI mnc(m,n);
        vector<VI> t(n,VI(m,0));
        REP(i,n){
            cin>>a[i];
            REP(j,m){
                if (a[i][j]=='#'){
                    t[i][j]=1;
                    mxr[i]=j;
                    if (mnr[i]==m) mnr[i]=j;
                    mxc[j]=i;
                    if (mnc[j]==n) mnc[j]=i;
                }
             //   cout<<t[i][j]<<",";
            }
          //  cout<<endl;
        }
       // for (auto i:mnr) { cout<<i<<" ";} cout<<endl;
      //  for (auto i:mnc) { cout<<i<<" ";} cout<<endl;
     //   for (auto i:mxr) { cout<<i<<" ";} cout<<endl;
      //  for (auto i:mxc) { cout<<i<<" ";} cout<<endl;
        int nbrv=0;
        REP(i,n){
            if (mxr[i]==-1) nbrv++;
        }
     
        int nbcv=0;
        REP(j,m){
            if (mxc[j]==-1) nbcv++;
        }
        
        bool isok=true;
        if (nbcv*nbrv==0 and nbcv+nbrv!=0) isok=false;
        REP(i,n){
            if (mxr[i]!=-1){
                REPP(j,mnr[i],mxr[i]+1){
                    if (!t[i][j]) {isok=false; break;}
                }
            }
            if (!isok) break;
        }
        REP(j,m){
            if (mxc[j]!=-1){
                REPP(i,mnc[j],mxc[j]+1){
                    if (!t[i][j]) {isok=false; break;}
                }
            }
            if (!isok) break;
        }
        //cb de groupes
        int nbg=0;
        if (isok){
            ps=VI(n);
            REP(i,n) ps[i]=i;
            VI whom(m,-1);
            REP(i,n){
                if (mxr[i]!=-1) 
                    REPP(j,mnr[i],mxr[i]+1){
                  //      cout<<i<<" "<<j<<endl;
                        if (whom[j]!=-1) {
                            merge(whom[j],i);
                        }
                        else {whom[j]=i;}
                    }
            }
            REP(i,n){
                if (mxr[i]!=-1 and ps[i]==i) nbg++;
            }
        }
     
        //for (auto i:ps) { cout<<i<<" ";}
        //cout<<endl;
        if (isok){
            cout<<nbg<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }