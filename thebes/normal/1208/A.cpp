#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

int t, a, b, n, i;

int main(){
    for(scanf("%d",&t),i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&n);
        if(n%3==0) printf("%d\n",a);
        else if(n%3==1) printf("%d\n",b);
        else if(n%3==2) printf("%d\n",a^b);
    }
    return 0;
}