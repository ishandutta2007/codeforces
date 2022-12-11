#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#define INPUT freopen("digitsum.inp","r",stdin);
#define OUTPUT freopen("digitsum.out","w",stdout);
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)

using namespace std;

typedef long long ll;


int a,b,n,m,s[100010];
int main(){
    cin>>a>>b>>n;
    m=10*a%b;
    if (m>0&&b-m>9) {printf("-1");return 0;}
    cout<<a;
    if (m) {cout<<b-m;n--;}
    FOR(i,1,n) cout<<0;
}