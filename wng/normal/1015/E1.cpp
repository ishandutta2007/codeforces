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
    int n,m;
    RII(n,m);
    
    vector<VI> v(n,VI(m));
    vector<VI> ok(n,VI(m));
    vector<VI> val(n,VI(m));
    
    VI uexpl(n);
    VI uexpc(m);
    
    REP(i,n){
        char a[m];
        RS(a);
        REP(j,m){
            if (a[j]=='*') {
                v[i][j]=1;
                uexpl[i]+=1;
                uexpc[j]+=1;
               // cout<<i<<" "<<j<<endl;
            }
        } 
    }
    
    //for (auto i: uexpl) {cout<<i<<" ";} cout<<endl;
    int nbd=0;
    REP(i,n){ 
        REP(j,m){
            if (v[i][j] and (uexpl[i] or uexpc[j])){
                int size=1;
                int ips=i+size;
                int ims=i-size;
                int jps=j+size;
                int jms=j-size;
                while ((uexpl[i] or uexpc[j]) and ims>=0 and ips<n and jms>=0 and jps<m){
                    if (v[ips][j] and v[ims][j] and v[i][jms] and v[i][jps]){
                        
                        int ii=i;
                        int jj=j;
                        if (!ok[ii][jj]) {
                            ok[ii][jj]=1;
                            uexpl[ii]--;
                            uexpc[jj]--;
                        }
                        
                        ii=ips;
                        jj=j;
                        if (!ok[ii][jj]) {
                            ok[ii][jj]=1;
                            uexpl[ii]--;
                            uexpc[jj]--;
                        }                        
                         ii=ims;
                        jj=j;
                        if (!ok[ii][jj]) {
                            ok[ii][jj]=1;
                            uexpl[ii]--;
                            uexpc[jj]--;
                        }    
                         ii=i;
                        jj=jps;
                        if (!ok[ii][jj]) {
                            ok[ii][jj]=1;
                            uexpl[ii]--;
                            uexpc[jj]--;
                        }    
                        ii=i;
                        jj=jms;
                        if (!ok[ii][jj]) {
                            ok[ii][jj]=1;
                            uexpl[ii]--;
                            uexpc[jj]--;
                        }      
                        val[i][j]=size;
                    }
                    else {break;}
                    size++;
                    ips++;
                    ims--;
                    jps++;
                    jms--;
                }
            }
            if (val[i][j]) {nbd++;
            /*cout<<i<<" "<<j<<" "<<nbd<<endl;*/}
            //if (i==2) {for (auto k: uexpl) {cout<<k<<" ";} cout<<endl;}
            
        }
    }
     
    //for (auto i: uexpl) {cout<<i<<" ";} cout<<endl;
    
    REP(i,n){if (uexpl[i]) {printf("-1\n");return 0;}}
    printf("%d\n",nbd);
    REP(i,n){
        REP(j,m){
            if (val[i][j]){
                printf("%d %d %d\n",i+1,j+1,val[i][j]);
            }
        }
    }
    
}