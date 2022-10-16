#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];

int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    int last=0;
    rep(i,1,n) if(s[last]!='/' || s[i]!='/') s[++last]=s[i];
    if(s[last]=='/' && last>1) last--;
    s[last+1]=0;
    puts(s+1);
    return 0;
}