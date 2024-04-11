//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
//#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=1000010;
const ll mod=998244353;
const ll inf=1e18;
int a[N];
int dsu[N];
vector<int>group[N];
int ind[N];
void solve(){
    int n;cin>>n;
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        ind[i]=i;
        dsu[i]=i;
        group[i].push_back(i);
        st.insert({a[i],i});
    }
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int k,w;cin>>k>>w;
            n++;
            dsu[n]=n;
            group[n].push_back(n);
            ind[k]=n;
            a[n]=w;
            st.insert({a[n],n});
        } else if (type==2){
            int k;cin>>k;
            cout<<a[dsu[ind[k]]]<<'\n';
        } else {
            int l,r;cin>>l>>r;
            int m=(l+r)/2;
            pair<int,int>fnd={l,0};
            vector<int>L;
            while (true){
                auto it=st.lower_bound(fnd);
                if (it==st.end() || (*it).first>m) break;
                L.push_back((*it).second);
                st.erase(it);
            }
            if (!L.empty()){
                for (int i=0;i+1<L.size();i++){
                    if (group[L[i]].size()>group[L[i+1]].size()) swap(L[i],L[i+1]);
                }
                int gl=L.back();
                L.pop_back();
                for (int i:L){
                    for (int j:group[i]){
                        group[gl].push_back(j);
                        dsu[j]=gl;
                    }
                    group[i].clear();
                }
                a[gl]=l-1;
                st.insert({a[gl],gl});
            }
            fnd={m+1,0};
            vector<int>R;
            while (true){
                auto it=st.lower_bound(fnd);
                if (it==st.end() || (*it).first>r) break;
                R.push_back((*it).second);
                st.erase(it);
            }
            if (!R.empty()){
                for (int i=0;i+1<R.size();i++){
                    if (group[R[i]].size()>group[R[i+1]].size()) swap(R[i],R[i+1]);
                }
                int gl=R.back();
                R.pop_back();
                for (int i:R){
                    for (int j:group[i]){
                        group[gl].push_back(j);
                        dsu[j]=gl;
                    }
                    group[i].clear();
                }
                a[gl]=r+1;
                st.insert({a[gl],gl});
            }
        }
    }




}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
5
1 2 1
2 3 2
3 4 3
4 5 4
*/