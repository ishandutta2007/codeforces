#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= (int)n; ++i)
#define dep(i,a,n) for (int i = a; i >= (int)n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
const int N=5555;
int l,m,n,t,l1,l2,a[27],l3;
char s1[N],s2[N],ch,s3[N];
string ans;
int bo,f;
int find(int x){
    rep(i,x+1,25)if(a[i]){a[i]--;return i+'a';}return 0;
}
int dfs(int x){
    if(x>l2){if(l1>l3)bo=x;return 1;}
    if(a[s2[x]-'a']){
        a[s2[x]-'a']--;dfs(x+1);a[s2[x]-'a']++;
    }if(bo)return 1;
    if(find(s2[x]-'a')){bo=x+1;f=1;return 1;}
}
int main()
{
    scanf("%s%s",s1+1,s2+1);l1=strlen(s1+1);l3=l2=strlen(s2+1);
    rep(i,1,l1)a[s1[i]-'a']++;rep(i,1,l2)a[s2[i]-'a']--;
    int boo=1;//rep(i,0,25)if(a[i]!=0)boo=1;if(!boo){puts("-1");return 0;}
    rep(i,1,l1-1)if(s1[i]!=s1[i+1])boo=0;rep(i,1,l2)if(s2[i]!=s1[1])boo=0;
    if(boo&&l2>=l1){puts("-1");return 0;}
    memset(a,0,sizeof(a));rep(i,1,l1)a[s1[i]-'a']++;l2=min(l1,l2);
    dfs(1);if(!bo){puts("-1");return 0;}
    memset(a,0,sizeof(a));rep(i,1,l1)a[s1[i]-'a']++;
    //printf("%d %d\n",bo,f);
    rep(i,1,bo-1-f)printf("%c",s2[i]),a[s2[i]-'a']--;
    if(f)printf("%c",find(s2[bo-1]-'a'));
    rep(i,0,25)rep(j,1,a[i])printf("%c",i+'a');puts("");
    return 0;
}