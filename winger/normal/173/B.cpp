#pragma comment(linker,"/stack:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <assert.h>
#include <limits.h>
#define _USE_MATH_DEFINES 
#include <math.h> 

#define pb(a) push_back(a) 
#define sz size()
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define mp(a,b) make_pair(a,b)

typedef long long ll;
typedef long double ld;

template<typename T> inline void SWAP(T &a, T &b){T tmp=a;a=b;b=tmp;}
template<typename T> inline T ABS(const T &VAL) {return VAL<0?-VAL:VAL;}
template<typename T> inline T MAX(const T &a, const T &b){return a<b?b:a;}
template<typename T> inline T MIN(const T &a, const T &b){return a<b?a:b;}
template<typename T> inline T SQR(const T &a){return a*a;}

#define MSET(d) memset(d,0,sizeof(d))
#define forn(i,n) for(int i=0;i!=n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i!=b;i++)
#define for1ab(i,a,b) for(int i=a+1;i<=b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define ford1ab(i,a,b) for(int i=b;i!=a;i--)
#define ford(i,n) for(int i=n-1;i!=-1;i--)
#define ford1(i,n) for(int i=n;i!=0;i--)

//const int INTinf = 2147483647;
const int INTinf = 1000000005;
const int nINTinf = 0-2147483648;
const ll LLinf = 9223372036854775807LL;

using namespace std;
typedef pair<int, int> pii;
typedef unsigned int uint;
int n,m;
char a[1005][1005];
int b[1005][1005];
bool col[1005];
bool row[1005];
int step = 1;
vector<pii> koords;
inline void markCol(int nom){
    if (col[nom]) return;
    col[nom] = true;
    for(int i=0;i!=n;i++){
        if (a[i][nom]=='#' && (!b[i][nom])){
            b[i][nom]=step;
            koords.pb(pii(i,nom));
        }
    }
}
inline void markRow(int nom){
    if (row[nom]) return;
    row[nom] = true;
    if (nom == n-1){
        cout << step - 1 << endl;
        exit(0);
    }
    for(int i=0;i!=m;i++){
        if (a[nom][i]=='#' && (!b[nom][i])){
            b[nom][i]=step;
            koords.pb(pii(nom, i));
        }
    }
}
int main(){
#ifdef _DEBUG
    //freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
#endif
    cin >> n >> m;
    forn(i,n){
        cin >> a[i];
    }
    markRow(0);
    for (int i = 0; i < koords.sz; ++i){
        pii val = koords[i];
        step = b[val.X][val.Y] + 1;
        markRow(val.X);
        markCol(val.Y);
    }

    cout << -1 << endl;
    
#ifdef _DEBUG
    //fclose(stdout);   
    fclose(stdin);
#endif
    return 0;
}