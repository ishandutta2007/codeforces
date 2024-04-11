#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=60;

int a[N][20],n,m,cp[N],p[1<<20],key[2][1<<10][N];
char s[N];
long double f[1<<20];
vector <int> qc[N],q[N];
int cv(char s){
    if (s>='A'&&s<='Z') return s-'A';
    return 26+s-'a';
}
void solve(){
    f[0]=1;
    long double ans=0;
    int mid=m/2;
    ///split into 2 parts
    REP(bi,1,1<<mid){
        int last=bi^(bi&-bi),cur=__builtin_ffs(bi)-1;
        FOR(i,1,n) qc[key[0][last][i]].push_back(i);
        REP(i,0,n)
            while (!qc[i].empty()){
                int x=qc[i].back();qc[i].pop_back();
                q[a[x][cur]].push_back(x);
            }
        int top=0;
        for(int i=0;top<n;i++)
            while (!q[i].empty()) cp[++top]=q[i].back(),q[i].pop_back();
        for(int i=1,nkey=0;i<=top;i++,nkey++){
            int j=i;
            while (j<top&&key[0][last][cp[j+1]]==key[0][last][cp[i]]&&a[cp[j+1]][cur]==a[cp[i]][cur]) j++;
            FOR(i1,i,j) key[0][bi][cp[i1]]=nkey;
            i=j;
        }
    }
    ///
    REP(bi,1,1<<(m-mid)){
        int last=bi^(bi&-bi),cur=__builtin_ffs(bi)-1;
//        printf("%d %d %d\n",bi,last,cur);
        FOR(i,1,n) qc[key[1][last][i]].push_back(i);
        FOR(i,0,n)
            while (!qc[i].empty()){
                int x=qc[i].back();qc[i].pop_back();
                q[a[x][mid+cur]].push_back(x);
//                printf("%d %d\n",x,a[x][mid+cur]);
            }
        int top=0;
        for(int i=0;top<n;i++)
            while (!q[i].empty()) cp[++top]=q[i].back(),q[i].pop_back();
        for(int i=1,nkey=0;i<=top;i++,nkey++){
            int j=i;
            while (j<top&&key[1][last][cp[j+1]]==key[1][last][cp[i]]&&a[cp[j+1]][mid+cur]==a[cp[i]][mid+cur]) j++;
            FOR(i1,i,j) key[1][bi][cp[i1]]=nkey;
            i=j;
        }
//        FOR(i,1,n) printf("%d %d %d\n",bi,i,key[1][bi][i]);
    }
    ///merge back
    REP(bia,0,1<<mid)
        REP(bib,0,1<<(m-mid)){
            int idx=(bib<<mid)|bia;
            FOR(i,1,n) qc[key[1][bib][i]].push_back(i);
            FOR(i,0,n)
                while (!qc[i].empty()) q[key[0][bia][qc[i].back()]].push_back(qc[i].back()),qc[i].pop_back();
            for(int i=0,top=0;top<n;i++)
                while (!q[i].empty()) cp[++top]=q[i].back(),q[i].pop_back();
            FOR(i,1,n){
                int j=i;
                while (j<n&&key[0][bia][cp[j+1]]==key[0][bia][cp[i]]&&key[1][bib][cp[j+1]]==key[1][bib][cp[i]]) j++;
                p[idx]+=(j==i)?0:(j-i+1);
                i=j;
            }
        }
    REP(bit,1,1<<m){
        int c=__builtin_popcount(bit);
        for(int j=1;j<=bit;j<<=1) if (bit&j){
            int clast=bit^j;
            if (!p[clast]) continue;
            ans+=f[clast]*c*(p[clast]-p[bit])/(p[clast]*(m-c+1));
            f[bit]+=f[clast]*p[bit]/(p[clast]*(m-c+1));
        }
    }
//    REP(i,0,1<<m) printf("%d ",p[i]);ENDL;
//    REP(i,0,1<<m) printf("%.10f ",double(f[i]));ENDL;
    printf("%.10f",double(ans));
}
int main(){
//    INPUT;
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("\n%s",s);
        m=strlen(s);
        REP(j,0,m) a[i][j]=cv(s[j]);
    }
    solve();
}