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

int n;
ll s[300100], t[300100];
int ord[300100];

struct tup{
    int i, j, d;
};
vector<tup> vec;
stack<int> st;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&s[i]);
    for (i=0;i<n;i++) scanf("%lld",&t[i]);
    for (i=0;i<n;i++) ord[i] = i;
    sort(ord,ord+n,[](int a, int b){
            return s[a]<s[b];
         });
    sort(t,t+n);
    for (i=0;i<n;i++) {
        if (t[i]>s[ord[i]]) {
            st.push(i);
        }
        else {
            while(!st.empty()&&t[i]<s[ord[i]]) {
                int here = st.top();
                int v = min(t[here]-s[ord[here]],s[ord[i]]-t[i]);
                s[ord[here]]+=v;
                s[ord[i]]-=v;
                vec.push_back({ord[here],ord[i],v});
                if (s[ord[here]]==t[here]) st.pop();
            }
            if (t[i]!=s[ord[i]]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts(st.empty()?"YES":"NO");
    if (st.empty()) {
        printf("%d\n",vec.size());
        for (tup &t :vec) {
            printf("%d %d %d\n",t.i+1,t.j+1,t.d);
        }
    }

    return 0;
}