#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin >> n ;
   
    int s1 =0, diff =0,s2 =0;
    for(int i =0,x,y;i<n;++i){
        cin >> x >> y;
        s1 += x ; s2 += y;
        if(x%2!=y%2)diff++;
        
    }
    if(s1%2==0 && s2%2==0){cout << 0 << endl;return 0;}
    if(s1%2 != s2%2){cout << -1 << endl;return 0;}
    if(s1%2==1 && s2%2==1){
        if(diff) cout << 1 << endl;
        else cout << -1 << endl;
    }
}