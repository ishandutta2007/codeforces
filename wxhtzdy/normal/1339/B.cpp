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
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        sort(a,a+n);
        int x=0,y=n-1,nxt=0;
        vector<int> sol;
        while(x<=y){
            if(nxt)sol.push_back(a[y]),--y;
            else sol.push_back(a[x]),++x;
            nxt=1-nxt;
        }
        reverse(sol.begin(),sol.end());
        for(auto c:sol)printf("%i ",c);
        printf("\n");
    }
    return 0;
}