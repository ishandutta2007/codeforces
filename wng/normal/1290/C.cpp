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

VI ps, status, bases, sp, nb0, nb1, resass;
int n;
int res;
string s;
    
int findp(int i){
    if (ps[i]!=i){
        int nps=findp(ps[i]);
        if (nps!=ps[i]){
            sp[i]=sp[i]*sp[ps[i]];
            ps[i]=nps;
        }
    }
    return ps[i];
}

void merge(int i,int j,int rel){
    int pi=findp(i);
    int pj=findp(j);
    if (pi!=pj){
        int rrel=rel*sp[i]*sp[j];
        //cout<<"rrel :"<<rrel<<endl;
        res-=resass[pi];
        res-=resass[pj];
        ps[pi]=pj;
        sp[pi]=rrel;
        if (rrel<0){
            nb0[pj]+=nb1[pi];
            nb1[pj]+=nb0[pi];
        }
        else{
            nb0[pj]+=nb0[pi];
            nb1[pj]+=nb1[pi];
        }
        if (status[pi] or status[pj]){
            if (!status[pj]){
                status[pj]=rrel*status[pi];
            }
            resass[pj]=(status[pj]==1)?nb1[pj]:nb0[pj];
        }
        else{
            resass[pj]=min(nb0[pj],nb1[pj]);
        }
        res+=resass[pj];
    }
}

void assignstatus(int i,int st){
    int pi=findp(i);
    //cout<<"assigning status to "<<i<<"  "<<pi<<" "<<st<<" "<<status[pi]<<endl;
    if (!status[pi]){
        res-=resass[pi];
        status[pi]=sp[i]*st;
        resass[pi]=(status[pi]==1)?nb1[pi]:nb0[pi];
        res+=resass[pi];
    }
}
    


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>n>>k;
    cin>>s;
    ps=VI(k);
    status=VI(k,0);
    resass=VI(k,0);
    sp=VI(k,1);
    bases=VI(n);
    REP(i,n){
        bases[i]=s[i]-'0';
    }
    REP(i,k){
        ps[i]=i;
    }
    
    nb0=VI(k,1);
    nb1=VI(k,0);
    vector<VI> lsub(n,VI(0));
    REP(i,k){
        int c;
        cin>>c;
        REP(j,c){
            int v;
            cin>>v;
            v--;
            lsub[v].PB(i);
        }
    }
    res=0;
    REP(i,n){
        if (SZ(lsub[i])==1){
            assignstatus(lsub[i][0],bases[i]?1:-1);
        }
        if (SZ(lsub[i])==2){
            merge(lsub[i][0],lsub[i][1],bases[i]?1:-1);
        }

       /* cout<<"lsub[i] : ";
        for (auto z: lsub[i]) cout<<z<<" "; cout<<endl;
        cout<<"ps : ";
        for (auto z: ps) cout<<z<<" "; cout<<endl;
        cout<<"sp : ";
        for (auto z: sp) cout<<z<<" "; cout<<endl;
        cout<<"nb0 : ";
        for (auto z: nb0) cout<<z<<" "; cout<<endl;
        cout<<"nb1 : ";
        for (auto z: nb1) cout<<z<<" "; cout<<endl;
        cout<<"status : ";
        for (auto z: status) cout<<z<<" "; cout<<endl;
        cout<<"resass : ";
        for (auto z: resass) cout<<z<<" "; cout<<endl;

        cout<<"mon res pour i = "<<i<<" (base ="<<bases[i]<<"): ";*/
        cout<<res<<"\n";
    }
}