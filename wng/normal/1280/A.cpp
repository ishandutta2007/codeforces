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

int mod=1000000007;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nbt;
    cin>>nbt;
    while (nbt--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        VI a(max(x+1,(int)s.size()));
        REP(i,(int)s.size()){
            a[i]=s[i]-'0';
        }
        int l=0;
        int r=s.size();
        LL resout=r;
        while (l<x){
            l+=1;
            if (r<=x) {
                LL ir=r;
                REP(i,a[l-1]-1){
                    if (r<=x) 
                        REP(j,ir-l){
                            a[r]=a[l+j];
                            r++;
                //          cout<<"pff"<<ir<<" "<<l+j<<endl;
                            if (r>x) break;
                        }
                }
            }
            resout+=(resout-l+mod)*(a[l-1]-1);
            resout%=mod;
        //    cout<<"l: "<<l<<" "<<resout<<endl;
       // for (auto i:a) {cout<<i<<" ";} cout<<"\n";
        }
        cout<<resout<<"\n";
    }
}