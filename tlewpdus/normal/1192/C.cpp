#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int MAXW = 62;

int n;
ll C[65][65];
ll E[65][65][65];
string word[100100];

int ma(char ch) {
    if (ch>='a'&&ch<='z') return ch-'a';
    if (ch>='A'&&ch<='Z') return ch-'A'+26;
    return ch-'0'+52;
}

int f[5] = {1,1,2,6,24};
int c[4], p;
ll calc(int i, int j, int k, int l) {
    p = 0;
    c[0]=c[1]=c[2]=c[3]=0;
    c[0]++;
    if (j!=i) p++;
    c[p]++;
    if (k!=j) p++;
    c[p]++;
    if (l!=k) p++;
    c[p]++;
    int ans = 24;
    for (int i=0;i<=p;i++) ans/=f[c[i]];
    return ans;
}

ll solve(int s, int e) {
    vector<string> vec;
    for (int i=s;i<=e;i++) vec.push_back(word[i]);
    int sz = vec.size();
    for (int i=0;i<sz;i++) {
        string s = vec[i];
        reverse(s.begin(),s.end());
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    memset(C,0,sizeof(C));
    for (int i=0;i<vec.size();i++) {
        C[ma(vec[i][0])][ma(vec[i].back())]++;
    }
    for (int i=0;i<MAXW;i++) {
        for (int j=i;j<MAXW;j++) {
            for (int k=j;k<MAXW;k++){
                E[i][j][k] = 0;
                for (int a=0;a<MAXW;a++) {
                    E[i][j][k] += C[a][i]*C[a][j]*C[a][k];
                }
                E[i][j][k]%=MOD;
            }
        }
    }
    ll ans = 0;
    for (int i=0;i<MAXW;i++) {
        for (int j=i;j<MAXW;j++) {
            for (int k=j;k<MAXW;k++) {
                for (int l=k;l<MAXW;l++) {
                    ans += E[i][j][k]*E[i][j][l]%MOD*E[i][k][l]%MOD*E[j][k][l]%MOD*calc(i,j,k,l)%MOD;
                }
            }
        }
    }
    return ans%MOD;
}

char tmp[12];
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%s",tmp);
        word[i] = string(tmp);
    }
    sort(word,word+n,[](string &a, string &b){return a.size()<b.size();});
    int p = 0;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        if (i==n-1||word[i].size()!=word[i+1].size()) {
            ans += solve(p,i);
            p=i+1;
        }
    }
    printf("%lld\n",ans%MOD);

    return 0;
}