#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int w,h,n;
set<int> x;
set<int> y;
set<pair<int,pair<int,int> > > xs;
set<pair<int,pair<int,int> > > ys;

int main() {
    scanf("%d%d%d",&w,&h,&n);
    x.insert(0); x.insert(w);
    y.insert(0); y.insert(h);
    xs.insert(make_pair(-w,make_pair(0,w)));
    ys.insert(make_pair(-h,make_pair(0,h)));
    for (int i=0;i<n;i++) {
        char type;
        int a;
        scanf(" %c%d",&type,&a);
        if (type=='V') {
            int above = *x.lower_bound(a);
            int below = *(--x.lower_bound(a));
            x.insert(a);
            xs.insert(make_pair(below-a,make_pair(below,a)));
            xs.insert(make_pair(a-above,make_pair(a,above)));
            while (*(++x.find(xs.begin()->second.first))!=xs.begin()->second.second) xs.erase(xs.begin());
            printf("%I64d\n",(long long) xs.begin()->first*ys.begin()->first);
        } else {
            int above = *y.lower_bound(a);
            int below = *(--y.lower_bound(a));
            y.insert(a);
            ys.insert(make_pair(below-a,make_pair(below,a)));
            ys.insert(make_pair(a-above,make_pair(a,above)));
            while (*(++y.find(ys.begin()->second.first))!=ys.begin()->second.second) ys.erase(ys.begin());
            printf("%I64d\n",(long long) xs.begin()->first*ys.begin()->first);
        }
    }

    return 0;
}