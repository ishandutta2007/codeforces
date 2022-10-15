#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 500007;
int n,C1[maxn],C2[maxn];
int ans,p1[maxn],p2[maxn];
pair<int, int> fk[maxn];


bool cmp2(int u,int v){
    if(fk[u].second < fk[v].second){
        return 1;
    }
    else{
        if (fk[u].second==fk[v].second&&fk[u].first>fk[v].first)
            return 1;
    }
    return 0;
}
int lowbit(int u){
    return u & (-u);
}

void update(int u,int w){
    for (int i = u; i <= n;i+=lowbit(i))
        C1[i] += w, C2[i] += 1;
}

pair<int,int> query(int u){
    int ans = 0,ret=0;
    for (int i = u; i > 0;i-=lowbit(i))
        ans += C1[i], ret += C2[i];
    return {ans,ret};
}

#undef int
int main(){
    cin >> n;
    for (int i = 1; i <= n;++i){
        cin >> fk[i].second;
        p1[i] = i;
    }
    for (int i = 1; i <= n;++i){
        cin >> fk[i].first;
        p2[i] = i;
    }
    sort(fk + 1, fk + n + 1);
    sort(p1 + 1, p1 + n + 1, cmp2);
    for (int i = 1; i <= n;++i){
        p2[p1[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        update(p2[i], fk[i].second);
        pair<long long, long long> ret = query(p2[i]);
        ans -= ret.first;
        ans += ret.second * fk[i].second;
//        cout << ret.first << " " << ret.second << endl;
        }
    cout << ans << endl;
}