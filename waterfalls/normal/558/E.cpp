#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef pair<pair<int,int>,char> Seg;

#define MP make_pair
#define A first
#define B second

int n,q;
char S[100013];
set<Seg> segs;
int has[26];

int main() {
    scanf("%d%d %s",&n,&q,&S);
    for (int i=0;i<n;i++) segs.insert(MP(MP(i,1),S[i]));
    for (int Q=0;Q<q;Q++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a-=1; b-=1;
        if (a) {
            Seg aa = *(--segs.lower_bound(MP(MP(a,0),0)));
            if (aa.A.A+aa.A.B>a) {
                segs.erase(aa);
                segs.insert(MP(MP(aa.A.A,a-aa.A.A),aa.B));
                segs.insert(MP(MP(a,aa.A.A+aa.A.B-a),aa.B));
            }
        }
        Seg bb = *(--segs.lower_bound(MP(MP(b+1,0),0)));
        if (bb.A.A+bb.A.B>b+1) {
            segs.erase(bb);
            segs.insert(MP(MP(bb.A.A,b-bb.A.A+1),bb.B));
            segs.insert(MP(MP(b+1,bb.A.A+bb.A.B-b-1),bb.B));
        }
        for (int i=0;i<26;i++) has[i] = 0;
        while (true) {
            auto l = segs.lower_bound(MP(MP(a,0),0));
            if (l==segs.end() || l->A.A>b) break;
            has[l->B-'a']+=l->A.B;
            segs.erase(l);
        }
        int start = a;
        int from = 0;
        int to = 25;
        int diff = 1;
        if (c==0) swap(from,to), diff = -diff;
        for (int i=from;i!=to+diff;i+=diff) {
            if (has[i]>0) {
                segs.insert(MP(MP(start,has[i]),i+'a'));
                start+=has[i];
            }
        }
    }
    for (auto s: segs) {
        for (int i=0;i<s.A.B;i++) printf("%c",s.B);
    }
    printf("\n");

    return 0;
}