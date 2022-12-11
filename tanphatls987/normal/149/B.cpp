#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
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
#define inf 1000000

const int MOD=1000000007;
const int N=0;

typedef long long ll;

string s;
int convert(char c){
    if (c>='0'&&c<='9') return c-'0';
    else return c-'A'+10;
}
void solve(){
    int br1=0,l=0;
    bool infa=false,infb=false;
    while (s[br1]!=':') br1++;
    while (s[l]=='0'&&l+1<br1) l++;
    if (l==br1-1&&convert(s[l])<24) infa=true;
    int br2=br1+1;
    while (s[br2]=='0'&&br2<s.length()-1) br2++;
    if (s.length()-1==br2&&convert(s[br2])<60) infb=true;
    if (infa&&infb) {printf("-1");return;}
    int ans=0;
    FOR(i,2,61){
        int h=0,m=0,rad=1,no=0;
        FORD(j,br1-1,l) if (convert(s[j])>=i) {no=1;break;}else h+=rad*convert(s[j]),rad*=i;
        rad=1;
        FORD(j,s.length()-1,br2) if (convert(s[j])>=i) {no=1;break;}else m+=rad*convert(s[j]),rad*=i;
        if (h<24&&m<60&&no==0) ans++,printf("%d ",i);
    }
    if (ans==0) printf("0");
}
int main(){
    cin>>s;
    solve();
}