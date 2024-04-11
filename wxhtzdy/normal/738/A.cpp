#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=105;
int n;
char s[N];

int main() {
    scanf("%d",&n);
    scanf("%s",s);
    rep(i,0,n) if (i<n-2&&s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o') {
        char cc='o';
        int ptr=i;
        while (ptr<n&&s[ptr]==cc) {
            s[ptr]='*';
            cc=(cc^'o'^'g');
            ptr++;
        }
        if (cc=='o') s[ptr-1]='g',ptr--;
        printf("***");
        i=ptr-1;
    } else printf("%c",s[i]);
}