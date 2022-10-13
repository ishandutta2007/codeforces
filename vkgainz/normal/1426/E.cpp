#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[3];
int b[3];
int x[9];
int getNum(){
    int c[3];
    int d[3];
    for(int i=0;i<3;i++) c[i] = a[i];
    for(int i=0;i<3;i++) d[i] = b[i];
    int ans = 0;
    for(int i=0;i<9;i++){
        int r1 = x[i]/3;
        int r2 = x[i]%3;
        int m = min(c[r1],d[r2]);
        c[r1]-=m;
        d[r2]-=m;
        if(x[i]==1 || x[i]==5 ||x[i]==6) ans+=m;
    }
    return ans;
}
int main(){
    int n; cin >> n;
    for(int i=0;i<3;i++) cin >> a[i];
    for(int i=0;i<3;i++) cin >> b[i];
    int most = 0;
    int least = 1000000000;
    for(int i=0;i<9;i++) x[i] = i;
    most = max(most,getNum());
    least = min(least,getNum());
    while(next_permutation(x,x+9)){
        most = max(most,getNum());
        least = min(least,getNum());
    }
    cout << least << " " << most << endl;
}