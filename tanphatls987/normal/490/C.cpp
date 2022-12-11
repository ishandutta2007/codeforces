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
const int N=1e6+10;

string s;
int a[N]={0},m1,m2;
int main(){
    cin>>s>>m1>>m2;
    int n=s.length();
    for(int i=n-1,p=1;i>0;i--,p=(p*10)%m2)
        a[i]=(a[i+1]+(s[i]-'0')*p)%m2;
    for(int i=0,cur=0;i<n-1;i++){
        cur=(10*cur+s[i]-'0')%m1;
        if (cur==0&&a[i+1]==0&&s[i+1]!='0'){
            printf("YES\n");
            FOR(j,0,i) printf("%c",s[j]);
            ENDL;
            REP(j,i+1,n) printf("%c",s[j]);
            return 0;
        }
    }
    printf("NO");
}