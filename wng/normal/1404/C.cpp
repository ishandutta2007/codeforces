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
int lim= 1<<19;
vector<LL> st(lim,0);
int n;

void inc(int ii, int v){
    while (ii<lim){
        st[ii]+=v;
        ii+=ii&-ii;
    }
}

int getv(int ii){
    int res=0;
	while (ii>0){
		res+=st[ii];
		ii-=ii&-ii;
	}
    return res;
}
vector<LL> st2(lim,0);

void inc2(int ii, int v){
    while (ii<lim){
        st2[ii]+=v;
        ii+=ii&-ii;
    }
}

int getv2(int ii){
    int res=0;
	while (ii>0){
		res+=st2[ii];
		ii-=ii&-ii;
	}
    return res;
}

int main(){
    RI(n);
    DRI(q);
    VI a(n);
    REP(i,n){
        RI(a[i]);
        a[i]--;
    }
    vector<pair<PII,int>> qs(q);
    VI rs(q,-1);
    REP(i,q){
        DRII(x,y);
        qs[i]={{x,y},i};
    }
    sort(ALL(qs));
    VI areok(n,0);
    set<PII> totej;
    int totok=0;
    REP(i,n){
        if (a[i]<=i){
            int nbneeded = i-a[i];
            int extra = (totok - nbneeded);
            // je debranche avant si extra
            //cout<<i<<endl;
            if (extra>=0){
                int debranche;
                if (extra==totok) debranche=i;
                else{
                    int tt=0;
                    int t=1;
                    while (t<i+1) t<<=1;
                    while (t){
                  //      if (tt+t<=n) cout<<(t+tt)<<" "<<"xx"<<" "<<getv2(tt+t)<<" "<<extra<<endl;
                        if (tt+t<=n and getv2(tt+t)<=extra) tt+=t;
                        t>>=1;
                    }
                    debranche=tt;
                } 
                //cout<<"deb "<<i<<" "<<debranche<<endl;
                inc(i+1,1);
                totej.insert({debranche,i});
                inc2(debranche+1,1);
                //cout<<"deb "<<i<<" "<<debranche<<endl;
                areok[i]++;
                totok++;
            }
        }
    }
    //printf("totok : %d\n", totok);
   // printf("st %d\n", getv(13));
    int curtej=0;
    for (auto qq: qs){
        int x,y;
        x=qq.F.F;
        y=qq.F.S;
        int idq=qq.S;
        /*
        int nbt=0;
        while (x>curtej){
            if (areok[curtej]){
                nbt++;
                areok[curtej]=0;
                inc(curtej+1, -1);
            }
            curtej++;
        }*/
        auto ntt= totej.begin();
      //  for (auto i:totej){
     //       cout<<"<"<<i.F<<" "<<i.S<<endl;
      //  }
        while (ntt!=totej.end()){
       //     cout<<"je me demande si je dois tej "<<(ntt->F)<<","<<(ntt->S)<<") "<<x<<endl;
            if (!areok[ntt->S]) {ntt++; continue;}
            if (ntt->F < x){
                areok[ntt->S]=0;
                inc(ntt->S+1,-1);
                curtej++;
                ntt++; continue;
            }
            break;
        }
        if (ntt!=totej.begin()) totej.erase(totej.begin(), ntt);
        
        int res=getv(n-y);
        rs[idq]=res;
    //    cout<<"res "<<x<<" "<<y<<" : "<<res<<" (curtej = "<<curtej<<")"<<endl;
    }

    REP(i,q){
        printf("%d\n",rs[i]);
    }

}