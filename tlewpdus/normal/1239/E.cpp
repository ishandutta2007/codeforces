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

int n, tar, mini = INF, minb;
int arr[60], brr[30];
char pcnt[17000000];
vector<int> lis[27];
map<int,int> lo;

int num[27];
void calc(int arr[]) {
    vector<int> sum(17000000,0);
    for (int i=1, c=0;c<n;i*=2,c++) {
        lo[i]=c;
    }
    for (int i=0;i<(1<<(n-1));i++) {
        num[pcnt[i]]++;
    }
    for (int i=0;i<n-1;i++) {
        lis[i].reserve(num[i]+2);
    }
    lis[0].push_back(0);
    for (int i=1;i<(1<<(n-1));i++) {
        sum[i]=sum[i&(i-1)]+arr[lo[i&-i]];
        lis[pcnt[i]].push_back(sum[i]);
    }
    vector<int>().swap(sum);
}

void calc2(int arr[]) {
    vector<int> sum(17000000,0);
    for (int i=1;i<(1<<(n-1));i++) {
        sum[i]=sum[i&(i-1)]+arr[lo[i&-i]];
        int t = n-1-pcnt[i];
        int p = upper_bound(lis[t].begin(),lis[t].end(),tar/2-sum[i])-lis[t].begin();
        if (p<lis[t].size()) {
            if (mini>abs(2*(sum[i]+lis[t][p])-tar)) {
                mini = abs(2*(sum[i]+lis[t][p])-tar);
                minb = i;
            }
        }
        p--;
        if (p>=0) {
            if (mini>abs(2*(sum[i]+lis[t][p])-tar)) {
                mini = abs(2*(sum[i]+lis[t][p])-tar);
                minb = i;
            }
        }
    }
    vector<int>().swap(sum);
}

pii calc3(int arr[]) {
    int sum = 0;
    for (int i=0;i<n-1;i++){
        if (minb>>i&1) {
            sum += arr[i];
        }
    }
    int t = n-1-pcnt[minb];
    int p = upper_bound(lis[t].begin(),lis[t].end(),tar/2-sum)-lis[t].begin();
    if (p<lis[t].size()) {
        if (mini==abs(2*(sum+lis[t][p])-tar)) {
            return {t,lis[t][p]};
        }
    }
    p--;
    if (p>=0) {
        if (mini==abs(2*(sum+lis[t][p])-tar)) {
            return {t,lis[t][p]};
        }
    }
}

int calc4(int arr[], int t, int p){
    vector<int> sum(17000000,0);
    if (t==0) return 0;
    for (int i=1;i<(1<<(n-1));i++) {
        sum[i]=sum[i&(i-1)]+arr[lo[i&-i]];
        if (pcnt[i]==t&&sum[i]==p) {
            return i;
        }
    }
    vector<int>().swap(sum);
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n*2;i++) scanf("%d",&arr[i]);
    pcnt[0] = 0;
    for (int i=1;i<(1<<(n-1));i++) pcnt[i]=pcnt[i&(i-1)]+1;
    sort(arr,arr+2*n);
    int t0 = arr[0], t1 = arr[1];
    for (int i=0;i<2*n-2;i++) arr[i]=arr[i+2];
    for (int i=0;i<2*n-2;i++) tar+=arr[i];
    for (int i=0;i<n-1;i++) brr[i]=arr[i+n-1];
    calc(arr);
    calc2(brr);
    pii tmp = calc3(brr);
    int minb2= calc4(arr,tmp.first,tmp.second);
    vector<int> ans, ans2;
    for (int i=0;i<n-1;i++) {
        if (minb2>>i&1) ans.push_back(arr[i]);
        else ans2.push_back(arr[i]);
        if (minb>>i&1) ans.push_back(brr[i]);
        else ans2.push_back(brr[i]);
    }
    sort(ans.begin(),ans.end());
    sort(ans2.begin(),ans2.end());
    printf("%d ",t0);
    for (int i=0;i<n-1;i++) printf("%d ",ans[i]);
    printf("\n");
    for (int i=n-2;i>=0;i--) printf("%d ",ans2[i]);
    printf("%d\n",t1);

	return 0;
}