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

vector<set<int>> chd(100001);
vector<set<int>> prt(100001);
vector<int> order;
int currentsize=0;
vector<int> chd2;
unordered_set<int> s2;

void dfspushorder(int v, bool visited[]){
    visited[v]=true;
    for (auto c:chd[v]){
            if (not visited[c]) dfspushorder(c,visited);
        }
    order.PB(v);
}

int dfscount(int v, bool visited[]){
    visited[v]=true;
    s2.insert(v);
    int res=1;
    for (auto c:prt[v]){
            if (not visited[c]) {res+=dfscount(c,visited);}
        }
    for (auto c:chd[v]){
        chd2.PB(c);
    }
    //cout<<v<<" et "<<res<<endl;
    return res;
}


int main(){
    int n,m,h;
    RIII(n,m,h);
    VI hours(1,0);
    REP(i,n){ 
        int hi;
        RI(hi);
        hours.PB(hi);}
    REP(k,m){
        int i,j;
        RII(i,j);
        int m=(hours[i]-hours[j]+h)%h;
        if (m==1) {chd[j].insert(i);prt[i].insert(j);}
        if (m==(-1+h)) {chd[i].insert(j);prt[j].insert(i);}
    }
    
    
    bool visited[100001]={false};
    REPP(i,1,n+1){
            if (not visited[i]) {dfspushorder(i,visited);}
        }
    int res=1000000;
    int beststart=-1;
    bool vis2[100001]={false};
    reverse(ALL(order));
    for (auto i: order){
      /*  cout<<i<<endl;
        for (auto j:prt[i]){cout<<j<<" ";} 
        cout<<endl;*/
        if (not vis2[i]){
            int rt;
            chd2.resize(0);
            s2.clear();
            rt=dfscount(i,vis2);
           /* cout<<i<<" "<<rt<<endl;
            for (auto j:s2){cout<<j<<" ";} 
            cout<<endl;
            for (auto j:chd2){cout<<j<<" ";} */
            bool isgood=true;
            for (auto j:chd2){if (not s2.count(j)) {isgood=false; break;}}
            
            if (isgood) {
                res=min(res,rt); 
                if (res==rt) {beststart=i; /*cout<<beststart<<" et "<<res<<endl;*/}}
        }
    }
    bool tochange[100001]={false};
    
    dfspushorder(beststart,tochange);
    printf("%d\n",res);
    REP(i,n+1){
        if (tochange[i]) printf("%d ",i);
    }    
}