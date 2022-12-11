#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

string s;
int main(){
    cin>>s;
    int a=0,b=0,c=0,i=0;
    while (s[i]=='|') i++,a++;
    i++;
    while (s[i]=='|') i++,b++;
    i++;
    while (s[i]=='|') i++,c++;
    if (a+b!=c&&a+b-2!=c&&a+b+2!=c) {
            printf("Impossible");
            return 0;
    }
    if (a+b+2==c) {
        c--,a++;
    }
    if (a+b-2==c) {c++;
        if (a>1) a--;else b--;
    }
    FOR(i,1,a) printf("|");
    printf("+");
    FOR(i,1,b) printf("|");
    printf("=");
    FOR(i,1,c) printf("|");
}