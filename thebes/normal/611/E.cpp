#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e5+5;
int n, m, i, j, a[3], x, t;
multiset<int> s;

int main(){
    scanf("%d",&n);
    for(i=0;i<3;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++) scanf("%d",&x), s.insert(-x);
    while(s.size()){
        auto b = s.begin();
        int lst = -(*b); s.erase(b);
        int ch = -1, mn = 1<<30, ff = 1<<30;
        for(m=1;m<(1<<3);m++){
            int sm = 0, h = 0;
            for(j=0;j<3;j++){
                if((1<<j)&m) sm += a[j], h ++;
            }
            if(sm>=lst&&(h<mn||(h==mn&&sm<ff))){
                ff = sm;
                mn = h;
                ch = m;
            }
        }
        if(ch==-1){
            printf("-1\n");
            return 0;
        }
        if(s.size()){
            int res = 7^ch;
            vi avail;
            for(j=0;j<3;j++){
                if((1<<j)&res) avail.pb(-a[j]);
            }
            if(avail.size()==1){
                auto it = s.lower_bound(avail[0]);
                if(it!=s.end()) s.erase(it);
            }
            else if(avail.size()==2){
                auto it1 = s.lower_bound(avail[0]);
                if(it1!=s.end()){
                    int val=*it1; s.erase(it1);
                    auto it2 = s.lower_bound(avail[1]);
                    if(it2==s.end()){
                        s.insert(val);
                        auto it = s.lower_bound(avail[0]+avail[1]);
                        if(it!=s.end()) s.erase(it);
                    }
                    else s.erase(it2);
                }
                else{
                    auto it = s.lower_bound(avail[0]+avail[1]);
                    if(it!=s.end()) s.erase(it);
                }
            }
        }
        t++;
    }
    printf("%d\n",t);
    return 0;
}