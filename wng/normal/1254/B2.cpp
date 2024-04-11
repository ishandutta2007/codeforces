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
        VI a(n);
        VI ps(1001001,0);
        int lim=1001001;
        for (int j=4; j<lim;j+=2) ps[j]=1;
        REPP(i,3,lim){
            if (!ps[i]){
                LL kk=i*3;
                while (kk<lim) {ps[kk]=1; kk+=i<<1;}
            }
        }
        int g=0;
        LL s=0;
        REP(i,n) {
            RI(a[i]);
            g=__gcd(a[i],g);
            s+=a[i];
        }
        if (g>1) {printf("0\n"); return 0;}
        if (s<=1) {printf("-1\n"); return 0;}
        VL ds;
        if (!(s%2)) { ds.PB(2); while (!(s%2)) s/=2;}
        LL k=3;
        while (k*k<=s and k<lim) {
            if (!ps[k] and !(s%k)) {ds.PB(k); while (!(s%k)) s/=k;}
            k+=2;
        }
        if (s>1) ds.PB(s);
        //cout<<"divs";
        //for (auto i : ds) cout<<i<<" "; cout<<endl;
        LL curbest=(LL)1<<60;
        for (auto d:ds){
            //on fait des tas de d mecs, c forcment mieux si les a  sont 0 ou 1, sinnon on verra
            LL ib=0;
            LL cb=0;
            LL cr=0;
            int way=-1;
            LL pivot = d/2;
            REP(i,n) {
                if (a[i]%d) {
                    if (d%2) {
                        LL ncb=cb+(a[i]%d);
                        LL nbb=min(ncb,pivot)-min(cb,pivot)+ max(0LL,min(pivot,ncb-d));
                        LL nba=min(d,max(pivot+1,ncb))-max(pivot+1,cb) + max(0LL,ncb-d-pivot-1);
                        //cout<<i<<" "<<nba<<" "<<nbb<<" "<<cb<<" "<<ncb<<endl;
                        cr+=(nba-nbb)*i;
                        cb=ncb%d;
                    }
                    else{
                        cb+=a[i]%d;
                        cr+=way*i;
                        way=1;
                        if (cb==d) {cb=0; ib++; way=-1;}
                    }
                    //cout<<d<<" "<<i<<" "<<cr<<endl;
                }
            }
            curbest=min(curbest,cr);
        }
        printf("%I64d\n",curbest);
     
    }