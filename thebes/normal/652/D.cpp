#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MN = 2e5+5;
map<int,int> mp;
int N, i, x, y, bit[MN], ord[MN], ans[MN]; pii arr[MN];
void upd(int p){for(;p<=N;p+=p&-p)bit[p]++;}
int qu(int p){int r=0;for(;p;p-=p&-p)r+=bit[p]; return r;}
bool cmp(int i,int j){return arr[i].first>arr[j].first;}

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d%d",&x,&y);
        arr[i] = {x,y};
        mp[y] = 0;
        ord[i] = i;
    }
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++)
        it->second = ++i;
    sort(ord+1,ord+N+1,cmp);
    for(i=1;i<=N;i++){
        ans[ord[i]]=qu(mp[arr[ord[i]].second]);
        upd(mp[arr[ord[i]].second]);
    }
    for(i=1;i<=N;i++) printf("%d\n",ans[i]);
    return 0;
}