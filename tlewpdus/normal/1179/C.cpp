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

struct query {
    int t, b, c;
};

int n, m, q;
int arr[300100], brr[300100];
query que[300100];

const int key = 1048576;
struct idxtree {
    int maxi[key*2+123], sum[key*2+123];
    idxtree() {
        int i;
        for (i=0;i<key*2;i++) maxi[i] = sum[i] = 0;
    }
    void upd(int idx, int val) {
        idx += key;
        sum[idx]+=val;
        maxi[idx] = max(sum[idx],0);
        idx/=2;
        while(idx) {
            maxi[idx] = max(maxi[idx*2],sum[idx*2]+maxi[idx*2+1]);
            sum[idx] = sum[idx*2]+sum[idx*2+1];
            idx/=2;
        }
    }
    int getl() {
        int idx = 1, cur = 0;
        while(idx<key) {
            if (maxi[idx*2]+cur>0) idx*=2;
            else {
                cur += sum[idx*2];
                idx=idx*2+1;
            }
        }
        return idx-key;
    }
} it;

vector<int> comp;

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        comp.push_back(arr[i]);
    }
    for (i=0;i<m;i++) {
        scanf("%d",&brr[i]);
        comp.push_back(brr[i]);
    }
    scanf("%d",&q);
    for (i=0;i<q;i++) {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c); b--;
        que[i] = query({a,b,c});
        comp.push_back(c);
    }
    comp.push_back(-1);
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    int msz = (int)comp.size()-1;
    for (i=0;i<n;i++) {
        arr[i] = lower_bound(comp.begin(),comp.end(),arr[i])-comp.begin();
        it.upd(msz-arr[i],1);
    }
    for (i=0;i<m;i++) {
        brr[i] = lower_bound(comp.begin(),comp.end(),brr[i])-comp.begin();
        it.upd(msz-brr[i],-1);
    }
    for (i=0;i<q;i++) {
        if (que[i].t==1) {
            it.upd(msz-arr[que[i].b],-1);
            arr[que[i].b] = lower_bound(comp.begin(),comp.end(),que[i].c)-comp.begin();
            it.upd(msz-arr[que[i].b],1);
        }
        else {
            it.upd(msz-brr[que[i].b],1);
            brr[que[i].b] = lower_bound(comp.begin(),comp.end(),que[i].c)-comp.begin();
            it.upd(msz-brr[que[i].b],-1);
        }
        printf("%d\n",it.getl()>msz?-1:comp[msz-it.getl()]);
    }

    return 0;
}