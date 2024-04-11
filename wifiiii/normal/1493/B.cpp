#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int mirror[10] = {0,1,5,-1,-1,2,-1,-1,8,-1};
int get(int x) {
    int ret=0;
    for(int i=0;i<2;++i) {
        if(mirror[x%10]==-1) return -1;
        ret=ret*10+mirror[x%10];
        x/=10;
    }
    return ret;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int h,m;string s;
        cin>>h>>m>>s;
        int a=stoi(s.substr(0,2)),b=stoi(s.substr(3));
        int ok=0;
        for(int i=a;i<h;++i) {
            int lo=0; if(i==a) lo=b;
            for(int j=lo;j<m;++j) {
                int aa=get(j),bb=get(i);
                if(aa>=0 && bb>=0 && aa<h && bb<m) {
                    ok=1;
                    printf("%02d:%02d\n",i,j);
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) puts("00:00");
    }
}