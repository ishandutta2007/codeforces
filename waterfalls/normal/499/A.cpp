#include <cstdio>

using namespace std;

int n,x;
long long on[100010];

int main() {
    scanf("%d%d",&n,&x);
    for (int i=0;i<100010;i++) on[i] = 0;
    for (int i=0;i<n;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        on[l]+=1;
        on[r+1]-=1;
    }
    for (int i=1;i<100010;i++) on[i]+=on[i-1];
    for (int i=1;i<100010;i++) on[i]+=on[i-1];
    int ans = 0;
    for (int i=1;i<100010;i++) {
        if (on[i]-on[i-1]) ans+=1;
        else if (on[100009]==on[i]) break;
        else if (i+x-1<100010 && on[i+x-1]==on[i]) i+=x-1;
        else ans+=1;
    }
    printf("%d\n",ans);

    return 0;
}