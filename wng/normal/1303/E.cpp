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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nbt;
    cin>>nbt;
    while (nbt--){
        string s,t;
        cin>>s;
        cin>>t;
        int n=SZ(s);
        int m=SZ(t);
        bool isok=false;
        REP(i,m){
            string t1=t.substr(0,i+1);
            string t2=t.substr(i+1,m-i-1);
            t1+="#";
            t2+="#";
           // cout<<"trying "<<t1<<" "<<t2<<endl;
            VI b2(i+2,-1);
            b2[0]=0;
            REP(j,n){
                for(int k= i+1;k>=0;k--){
                    if (b2[k]>=0){
                        if (s[j]==t1[k]) {b2[k+1]=max(b2[k+1],b2[k]);}
                        if (s[j]==t2[b2[k]]) {b2[k]++;}
                    }
                }
            }
            if (b2[i+1]==m-i-1) isok=true;
           // cout<<isok<<endl;
        }
        if (isok) {cout<<"YES\n";}
        else {cout<<"NO\n";}
    }

}