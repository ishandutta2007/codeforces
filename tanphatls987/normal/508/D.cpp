#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=4e3+10;

string str;
int n,h[N],deg[N],b[200010];
vector <int> a[N];
struct CV{
    int operator()(char x){
        if (x>='0'&&x<='9') return x-'0';
        if (x>='a'&&x<='z') return x-'a'+10;
        return 36+x-'A';
    }
    char operator()(int x){
        if (x<10) return x+'0';
        if (x<36) return x-10+'a';
        return x-36+'A';
    }
}cv;
void solve(){
    int st,c1=0,c2=0;
    REP(i,0,3844){
        int v=a[i].size();
        if (v>deg[i]) st=i,c1++;
        if (deg[i]>v) c2++;
    }
    if (c1>1||c2>1) {
        printf("NO");
        return;
    }
    if (!c1) REP(i,0,3884) if (deg[i]){
        st=i;break;
    }
    stack <int> s;
    s.push(st);
    int top=0;
    while (!s.empty()){
        int x=s.top();
        if (h[x]==a[x].end()-a[x].begin()){
            b[++top]=x;
            s.pop();
            continue;
        }
        s.push(a[x][h[x]]);
        h[x]++;
    }
    //FORD(i,top,1) printf("%d ",b[i]);
    if (top<n+1||a[st].size()-deg[st]>1){
        printf("NO\n");
        return;
    }
    printf("YES\n%c%c",cv(st/62),cv(st%62));
    FORD(i,top-1,1) printf("%c",cv(b[i]%62));
}
int main(){
    //INPUT;
    cin>>n;
    REP(i,0,n){
        cin>>str;
        int x=cv(str[0])*62+cv(str[1]),y=62*cv(str[1])+cv(str[2]);
        a[x].push_back(y);
        deg[y]++;
    }
    solve();
}