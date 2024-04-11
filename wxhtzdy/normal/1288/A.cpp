#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,d;
        scanf("%i %i",&n,&d);
        if(n>=d){
            printf("YES\n");
            continue;
        }
        bool ok=0;
        for(int i=1;i<=n;i++){
            if(i+(d+i)/(i+1)<=n){
                printf("YES\n");
                ok=1;
                break;
            }
        }
        if(!ok)printf("NO\n");
    }
    return 0;
}