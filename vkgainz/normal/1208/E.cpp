#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 1e6+5;
ll ans[MX];
ll upd[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,w; cin >> n >> w;
    vector<int> a[n];
    int mx[n];
    for(int i=0;i<n;i++) {
        int l; cin >> l;
        a[i] = vector<int>(l);
        mx[i] = -1000000000;
        for(int j=0;j<l;j++) {
            cin >> a[i][j];
            mx[i] = max(mx[i], a[i][j]);
        }
    }
    memset(ans, 0, sizeof(ans));
    for(int i=0;i<n;i++) {
        if(w>=2*a[i].size()+1) {
            int currmx = 0;
            for(int j=0;j<a[i].size();j++) {
                currmx = max(currmx, a[i][j]);
                ans[j+1]+=currmx;
            }
            currmx = 0;
            for(int j=a[i].size()-1;j>=0;j--) {
                currmx = max(currmx, a[i][j]);
                ans[w-((a[i].size()-1)-j)]+=currmx;
            }
            //l+1...w-l
            upd[a[i].size()]-=max(mx[i],0);
            upd[w-a[i].size()]+=max(mx[i],0);
        }
        else {
            deque<int> q;
            int idx = 0;
            bool zero = false;
            for(int j=1;j<=w;j++) {
                if(idx<a[i].size()) {
                    while(!q.empty() && a[i][q.back()]<=a[i][idx]) {
                        q.pop_back();
                    }
                    q.push_back(idx++);
                }
                zero = (a[i].size()<=(j-1))||(a[i].size()<=(w-j));
                if(zero) ans[j]+=max(a[i][q.front()],0);
                else ans[j]+=a[i][q.front()];
                if(((a[i].size()-q.front())+j)>=w+1) {
                    q.pop_front();
                }
            }
        }
    }
    for(int i=w;i>=1;i--) {
        upd[i]+=upd[i+1];
    }
    for(int i=1;i<=w;i++) cout << ans[i]+upd[i] << "\n";
}