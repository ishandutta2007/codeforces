#include <cstdio>
#include <algorithm>

using namespace std;

int hy,ay,dy,hm,am,dm,h,a,d;

int main() {
    scanf("%d%d%d%d%d%d%d%d%d",&hy,&ay,&dy,&hm,&am,&dm,&h,&a,&d);
    int ans = 2147483647;
    for (int hAdd=0;hAdd<=10000;hAdd++) {
        for (int dAdd=0;dAdd<=100;dAdd++) {
            int cur = hAdd*h+dAdd*d;
            if (dy+dAdd>=am) {
                if (ay>dm) ans = min(ans,cur);
                else ans = min(ans,cur+(dm-ay+1)*a);
            } else {
                int turns = (hy+hAdd-1)/(am-dy-dAdd);
                if (turns==0) continue;
                if ((ay-dm)*turns>=hm) ans = min(ans,cur);
                else ans = min(ans,cur+(((hm-1)/turns+1+dm)-ay)*a);
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}