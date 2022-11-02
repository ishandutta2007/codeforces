#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int n,M,T;
int who[20013];
deque<pair<int,int> > cur;

int parse() {
    int a,b,c;
    scanf("%d%*c%d%*c%d",&a,&b,&c);
    return a*3600+b*60+c;
}

int main() {
    scanf("%d%d%d",&n,&M,&T);
    int which = 1;
    int next = parse();
    int maxOn = 0;
    int num = 1;
    for (int t=0;t<86400;t++) {
        while (cur.size()>0 && cur[0].first<=t-T) cur.pop_front();
        while (t==next) {
            if (cur.size()<M) cur.push_back(make_pair(t,num)), who[which-1] = num++;
            else {
                who[which-1] = cur[cur.size()-1].second;
                cur.pop_back();
                cur.push_back(make_pair(t,who[which-1]));
            }
            if (which<n) {
                next = parse();
                which+=1;
            } else next = -1;
        }
        maxOn = max(maxOn,(int) cur.size());
    }
    if (maxOn==M) {
        printf("%d\n",num-1);
        for (int i=0;i<n;i++) printf("%d\n",who[i]);
    } else printf("No solution\n");

    return 0;
}