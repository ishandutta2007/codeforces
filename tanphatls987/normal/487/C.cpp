#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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

int n;
int power(int x,int y){
    if (y==0) return 1;
    if (y==1) return x;
    int tmp=power(x,y/2);
    if (y%2) return (((1LL*tmp*tmp)%n)*x)%n;
    return (1LL*tmp*tmp)%n;
}
int main(){
    cin>>n;
    if (n==1) {printf("YES\n1");return 0;}
    if (n==4) {printf("YES\n1\n3\n2\n4");return 0;}
    FOR(i,2,sqrt(n)) if (n%i==0) {printf("NO");return 0;}
    printf("YES\n1\n");
    FOR(i,2,n-1) printf("%d\n",(1LL*i*power(i-1,n-2))%n);
    printf("%d",n);
}