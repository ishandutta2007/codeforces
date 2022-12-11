#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

int s[N],n,m,t,x;
vector <int> a[102];
bool comp(int x,int bit){
    if (bit>=10) return false;
    return x>=(1<<bit);
}
int main(){
    scanf("%d%d",&n,&m);
    while (n--){
        scanf("%d%d",&t,&x);
        a[t].push_back(x);
    }
    int csize=0;
    priority_queue <int> q;
    FOR(i,1,m){
        sort(a[i].begin(),a[i].end());
        int m1=a[i].size();
        while (m1&&!comp(csize,m-i)) q.push(-a[i][--m1]),csize++;
        while (m1){
            int cx=-q.top();
            if (a[i][m1-1]>cx){
                q.pop();
                q.push(-a[i][m1-1]);
                m1--;
            }else break;
        }
        int top=0;
        while (!q.empty()){
            int cx=-q.top();q.pop();
            s[++top]=cx;
        }
        csize=(top+1)/2;
        for(int i=top;i>0;i-=2) q.push(-(s[i]+s[i-1]));
        //printf("%d %d %d\n",i,csize,sum);
    }
    cout<<-q.top();
}