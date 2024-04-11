#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
int arr[510];
vector<int> vec;
vector<int> sec;

int main() {
    int i;

    scanf("%d",&n);
    int s = 0, c = 0;
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        s += arr[i];
        if (arr[i]!=1) {
            c++;
            vec.push_back(i);
        }
        else sec.push_back(i);
    }
    if (s<2*(n-1)) {
        puts("NO");
        return 0;
    }
    printf("YES %d\n",min(c+1,n-1));
    printf("%d\n",n-1);
    for (i=0;i+1<vec.size();i++) {
        arr[vec[i]]--;
        arr[vec[i+1]]--;
        printf("%d %d\n",vec[i]+1,vec[i+1]+1);
    }
    int fl = 0;
    for (i=0;i<sec.size();i++) {
        int t = -1;
        if (!fl&&arr[vec[0]]) {
            t = vec[0];
            fl = 1;
        }
        else if (arr[vec.back()]) {
            t = vec.back();
        }
        else {
            for (int j=0;j<vec.size();j++) if (arr[vec[j]]) {
                t = vec[j];
                break;
            }
        }
        arr[t]--;
        arr[sec[i]]--;
        printf("%d %d\n",t+1,sec[i]+1);
    }

    return 0;
}