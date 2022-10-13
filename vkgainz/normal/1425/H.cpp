#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        bool pos;
        if((a+b)%2==0){
            pos = true;
        }
        else
            pos = false;
        bool ans[4];
        memset(ans,false,sizeof(ans));
        if(pos){
            if(a || d){
                ans[3] = true;
            }
            if(b || c){
                ans[2] = true;
            }
        }
        else{
            if(a || d){
                ans[0] = true;
            }
            if(b || c){
                ans[1] = true;
            }
        }
        for(int i=0;i<4;i++){
            if(ans[i]) cout << "Ya" << " ";
            else cout << "Tidak" << " ";
        }
        cout << endl;
    }
}