#include <bits/stdc++.h>
using namespace std;

const int N=200050;

int a[N],b[N];
set<int> pos;

int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),pos.insert(i);
    int q;scanf("%i",&q);
    while(q--){
        int t;scanf("%i",&t);
        if(t==1){
            int p,x;scanf("%i%i",&p,&x);
            while(x>0){
                auto it=pos.lower_bound(p);
                if(it!=pos.end()&&*it>=p){
                    int y=*it;
                    int dif=a[y]-b[y];
                    if(x<dif)b[y]+=x,x=0;
                    else{
                        x-=dif;
                        b[y]+=dif;
                        pos.erase(it);
                    }
                }else break;
            }
        }else{
            int x;scanf("%i",&x);
            printf("%i\n",b[x]);
        }
    }
    return 0;
}