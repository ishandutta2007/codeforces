#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll ccw(pll a, pll b, pll c){
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

int n;
pll arr[2010];
int chk[2010];
char str[2010];
vector<int> ans;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld%lld",&arr[i].x,&arr[i].y);
    scanf("%s",str);
    pll mini = arr[0];
    int t=0;
    for (i=0;i<n;i++) {
        if (mini>arr[i]) {
            mini=arr[i];t=i;
        }
    }
    ans.push_back(t);
    chk[t] = 1;
    int j;
    for (i=0;i<n-2;i++) {
        if (str[i]=='L') {
            t = -1;
            for (j=0;j<n;j++) {
                if (chk[j]) continue;
                if (t<0||ccw(arr[ans.back()],arr[t],arr[j])<0) t=j;
            }
        }
        else {
            t = -1;
            for (j=0;j<n;j++) {
                if (chk[j]) continue;
                if (t<0||ccw(arr[ans.back()],arr[t],arr[j])>0) t=j;
            }
        }
        ans.push_back(t);
        chk[t] = 1;
    }
    for (i=0;i<n;i++) {
        if (chk[i]) continue;
        ans.push_back(i);
    }
    for (int &v :ans)printf("%d ",v+1);
    printf("\n");

    return 0;
}