#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll r;
int n;
char str[1000100];
int ans[80100];

struct tup {
    ll t1, t2;
    int typ;
};

ll gcd(ll a, ll b) {
    if (!a) return b;
    return gcd(b%a,a);
}
pll nor(pll a) {
    ll g = gcd(a.first,a.second);
    return pll(a.first/g,a.second/g);
}

int main() {
    int t;

    scanf("%d",&t);
    while(t--){
        scanf("%lld ",&r);
        stack<ll> st;
        stack<char> tmp;
        fgets(str,1000000,stdin);
        n = strlen(str);
        while(str[n-1]=='\n'||str[n-1]==' ') n--;
        str[n] = 0;
        string arr;
        for (int i=0;i<n;i++) {
            if (str[i]==' ') continue;
            if (str[i]=='(') {
                tmp.push('(');
            }
            else if (str[i]=='*') {
                arr.push_back('*');
            }
            else if (str[i]=='S'||str[i]=='P') {
                tmp.push(str[i]);
            }
            else {
                while(!tmp.empty()&&tmp.top()!='(') {
                    arr.push_back(tmp.top());
                    tmp.pop();
                }
                if (!tmp.empty()) tmp.pop();
            }
        }
        int p = 0;
        vector<tup> trr;
        //printf("%s\n",arr.c_str());
        for (int i=0;i<arr.size();i++) {
            if (arr[i]=='*') {
                st.push(1);
                trr.push_back({0,0,2});
            }
            else if(arr[i]=='S') {
                ll t1 = st.top(); st.pop();
                ll t2 = st.top(); st.pop();
                st.push(min(t1,t2));
                trr.push_back({t1,t2,0});
            }
            else {
                ll t1 = st.top(); st.pop();
                ll t2 = st.top(); st.pop();
                //printf("%lld, %lld -> %lld\n",t1,t2,t1+t2);
                st.push(t1+t2);
                trr.push_back({t1,t2,1});
            }
        }
        vector<plll> tt;
        tt.push_back({st.top(),pll(r,1)});
        vector<ll> ans;
        for (int i=(int)trr.size()-1;i>=0;i--) {
            plll tmp = tt.back();
            tt.pop_back();
            if (trr[i].typ==0) {
                if (trr[i].t1<trr[i].t2) {
                    tt.push_back({trr[i].t2,pll(0,1)});
                    tt.push_back({trr[i].t1,tmp.second});
                }
                else {
                    tt.push_back({trr[i].t2,tmp.second});
                    tt.push_back({trr[i].t1,pll(0,1)});
                }
            }
            else if (trr[i].typ==1) {
                pll tttt = nor(pll(trr[i].t1+trr[i].t2,trr[i].t2));
                tttt.first *= tmp.second.first;
                tttt.second*= tmp.second.second;
                tttt = nor(tttt);
                //printf("%lld, %lld\n",tttt);
                tt.push_back({trr[i].t2,tttt});
                tttt = nor(pll(trr[i].t1+trr[i].t2,trr[i].t1));
                tttt.first *= tmp.second.first;
                tttt.second*= tmp.second.second;
                tttt = nor(tttt);
                tt.push_back({trr[i].t1,tttt});
                //printf("%lld, %lld\n",tttt);
            }
            else {
                //printf("POP\n");
                ans.push_back(tmp.second.first/tmp.second.second);
                //printf("%lld!\n",ans.back());
                //tt.pop_back();
            }
        }
        reverse(ans.begin(),ans.end());
        printf("REVOLTING ");
        for (ll &v : ans) {
            printf("%lld ",v);
        }
        puts("");
    }

	return 0;
}