/*
* Author : Max Nguyen
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rfor(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) fo(i, 0, j, 1)
#define rrep(i, j) rfor(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 17;
const int N1 = 105;
int a[N1], b[60];
int n;
int dp[1 << N][N1], dpTruyVet[1 << N][N1];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57};

void generateB(){
    fo(j, 1, 60, 1){
        int temp = 0;
        rep(k, N){
            if(j % prime[N-k-1] == 0){
                temp = temp*2 + 1;
            }else{
                temp = temp*2;
            }
        }
        b[j] = temp;
    }

//    fo(j, 1, 60, 1) {
//        printf("%d\n", b[j]);
//    }
}

void findKey(){
    dp[0][0] = 0;
    rep(setN, (1 << N)){
        rep(i, n){
            fo(j, 1, 60, 1){
                int temp = b[j];
                if((temp & setN) > 0){
                    continue;
                }
                if(dp[temp | setN][i + 1] > (dp[setN][i] + abs(a[i] - j))){
                    dp[temp | setN][i + 1] = dp[setN][i] + abs(a[i] - j);
                    dpTruyVet[temp | setN][i + 1] = j;
                }
            }
        }
    }
    int id = inf;
    int minN = inf;
    rep(setN, (1 << N)){
        if(dp[setN][n] < minN){
            minN = dp[setN][n];
            id = setN;
        }
    }
//    printf("%d\n", minN);
    vector<int> ans;
    rfor(i, n, 1, 1){
        int a = dpTruyVet[id][i];
//        printf("%d %d %d\n", i, id, a);
        ans.pb(a);
        id = id ^ b[a];
    }
    rrep(i, ((int) ans.size()) - 1){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main(){
    io

    cin >> n;
    rep(i, n){
        cin >> a[i];
    }
    rep(i, (1 << N)){
        rep(j, n+1){
            dp[i][j] = inf;
        }
    }
    generateB();
    findKey();
//    rep(i, (1 << 3)){
//        rep(j, n){
//            cout << dpTruyVet[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}