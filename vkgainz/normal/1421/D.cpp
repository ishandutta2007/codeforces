#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main() {
    int t; cin >> t;
    while(t--) {
        int x,y; 
        cin >> x >> y;
        vector<int> c(6);
        for(int i=0;i<6;i++) cin >> c[i];
        for(int x=0;x<10;x++) {
            for(int i=0;i<6;i++) {
                c[i] = min(c[i],c[(i+5)%6]+c[(i+1)%6]);
            }
        }
        ll ans = 0;
        if(y>=0 && x<=0){
            ans = y*1LL*c[1]-x*1LL*c[2];
        }
        else if(y<=0 && x>=0) {
            ans = -y*1LL*c[4]+x*1LL*c[5];
        }
        else if(y>=0 && x>=0) {
            if(y>=x) {
                ans = x*1LL*c[0]+(y-x)*1LL*c[1];
            }
            else {
                ans = y*1LL*c[0]+(x-y)*1LL*c[5];
            }
        }
        else if(y<=0 && x<=0) {
            if(abs(y)>=abs(x)) {
                ans = -x*1LL*c[3]+(x-y)*1LL*c[4];
            }
            else {
                ans = -y*1LL*c[3]+(y-x)*1LL*c[2];
            }
        }
        cout << ans << endl;
    }
    
}