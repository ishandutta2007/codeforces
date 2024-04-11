#include <cstdio>
#include <algorithm>

using namespace std;

#define upper_bound(x) upper_bound(pegs,pegs+n,x)
#define lower_bound(x) lower_bound(pegs,pegs+n,x)
int n,m;
int pos,dir,len;
pair<int,int> input[200013];
int where[200013];
int pegs_[200013];
int pegs2_[200013];
int *pegs,*pegs2;

int go() {
    int r = *(upper_bound(pos+len)-1);
    int nl = len-(r-pos);
    int l = *lower_bound(r-nl);
    int nl2 = nl-(r-l);
    if (l==r) return l;
    if (l!=pos) {
        pos = l;
        len = nl2;
    } else if (pos==l) {
        int diff = r-l;
        int num = len/diff;
        int left = len%diff;
        len = left;
        if (num%2==1) {
            pos = -r;
            swap(pegs,pegs2);
            dir = 3-dir;
        }
    }
    return go();
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%d",&input[i].first);
        input[i].second = i+1;
    }
    sort(input,input+n);
    for (int i=0;i<n;i++) where[input[i].second] = i;
    pegs = pegs_; pegs2 = pegs2_;
    for (int i=0;i<n;i++) pegs[i] = input[i].first;
    for (int i=0;i<n;i++) pegs2[i] = -pegs[n-i-1];
    for (int q=0;q<m;q++) {
        int a;
        scanf("%d%d",&a,&len);
        a = where[a];
        pos = pegs[a];
        dir = 1;
        int e = go();
        if (dir==2) e = -e, swap(pegs,pegs2);
        printf("%d\n",input[lower_bound(e)-pegs].second);
    }

    return 0;
}