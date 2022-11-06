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

//VI corresp;
vector<LL> st(1<<19,0);

int main(){
    DRI(n);
    //corresp=VI(n);
    VPII a(n);
    VI aa(n);
    REP(i,n) {
        DRI(x);
        a[i]={x,-i};
        aa[i]=x;}
    sort(a.rbegin(),a.rend());
    VI ns(n);
    VI sn(n);
    vector<pair<PII,int>> rs;
    DRI(m);
    VI res(m);
    REP(i,m){
        DRII(k,pos);
        rs.PB({{k,pos},i});
    }
    sort(ALL(rs));
    int j=0;
    REP(i,n){
        //corresp[i]=a[i].F;
        ns[-a[i].S] =i;
        sn[i]=a[i].F;
        //update st
		int ii=-a[i].S+1;
        //cout<<"pushing "<<i<<" "<<ii<<endl;
		while (ii<=st.size()){
			st[ii]+=1;
			ii+=ii&-ii;
		}
        while (j<m and rs[j].F.F==i+1) {
            int ta=1<<19;
            LL rt=-1;
            while (ta){
                LL tt=rt+ta;
                LL ss=0;
                if (tt<st.size()){
                    int ii=tt;
                    while (ii>0){
                        ss+=st[ii];
                        ii-=ii&-ii;
                    }
                    if (ss<rs[j].F.S) {rt=tt;}
                }
                //cout<<"dd"<<tt<<" "<<ss<<" "<<rs[j].F.S<<endl;
                ta>>=1;
            }
            //cout<<j<<" "<<rs[j].S<<" "<<rt<<endl;
            rt++;
            res[rs[j].S]=rt;
            j++;
        }
    }

    REP(i,m){
        //cout<<res[i]<<"->";
        printf("%d\n",aa[res[i]-1]);
    }
    
}