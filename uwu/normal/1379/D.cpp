#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Time{ll h, m;} arr[MAXN];
struct Item{ll x; int idx;};
bool cmp(Item a, Item b){
    return a.x<b.x;
}
vector<Item> uwu;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,h,m,k; cin >> n >> h >> m >> k;
    h*=2; m/=2;
    for (int i=1;i<=n;++i){
        cin >> arr[i].h >> arr[i].m;
        arr[i].h*=2;
        if (arr[i].m>=m) arr[i].h++, arr[i].m-=m;
        uwu.push_back({arr[i].m,i}); uwu.push_back({arr[i].m+m,i});
    }
    sort(uwu.begin(),uwu.end(),cmp);
    int pl=0,pr=0,cnt=1;
    while (uwu[pr].x<k){
        pr++, cnt++;
        while (uwu[pl].x<=uwu[pr].x-k) pl++, cnt--;
    }
    ll ans=pr,min=cnt-1;
    for (;pr<uwu.size();++pr,++cnt){
        while (uwu[pl].x<=uwu[pr].x-k) pl++, cnt--;
        if (cnt-1<min) min=cnt-1, ans=pr;
    }
    cout << min << " " << uwu[ans].x%m << '\n';
    for (int i=1;i<=min;++i){
        cout << uwu[ans-i].idx << " ";
    }
    cout << '\n';

}