#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 2e5+5;
int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> task(m);
    for(int i=0;i<m;i++) {
        cin >> task[i].f >> task[i].s;
    }
    int ret = 0;
    for(int pos=k;pos<=n;pos++) {
        int curr = 0;
        int ch[n+1];
        memset(ch, 0, sizeof(ch));
        for(int i=0;i<m;i++) {
            int numShare = max(0, 1+min(task[i].s, pos)-max(task[i].f, pos-k+1));
            curr+=numShare;
            if(task[i].s>=pos || task[i].f>=pos-k+1) continue;
            --ch[task[i].s-1];
            --ch[task[i].f+k-2];
            ++ch[task[i].f+numShare-2];
            if(task[i].s<pos-k+1)
                ++ch[task[i].s+k-1];
            else
                ++ch[pos-1];
        }
        int mxAdd = 0;
        int currCnt = 0;
        int currCh = 0;
        for(int p2 = pos-1; p2>=k; p2--) {
            currCh+=ch[p2];
            currCnt+=currCh;
            mxAdd = max(mxAdd, currCnt);
        }
        ret = max(ret, curr+mxAdd);
    }
    cout << ret << "\n";
}