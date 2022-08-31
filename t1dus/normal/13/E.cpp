#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,m;
int bl;

int a[100005],nex[100005],steps[100005],b[100005];


int main() {
	
	scanf("%d%d",&n,&m);
	bl = sqrt(n);
	REP(i,n) scanf("%d",&a[i]),b[i] = i/bl;
	REPD(i,n-1){
	    int x = i+a[i];
	    if(x >= n) nex[i] = -1,steps[i] = 1;
	    else if(b[i] == b[x]) nex[i] = nex[x],steps[i] = 1+steps[x];
	    else nex[i] = x,steps[i] =1;
	}
	WL(m){
	    int type,x,y,z; scanf("%d",&type);
	    if(type == 0){
	        scanf("%d%d",&x,&y);
	        x --;
	        a[x] = y;
	        if(x+y >= n) nex[x] = -1,steps[x] = 1;
	        else if(b[x] == b[x+y]) nex[x] = nex[x+y],steps[x] = 1+steps[x+y];
    	    else nex[x] = x+y,steps[x] =1;
    	    while (x > 0 and b[x] == b[x-1]){
    	        x --;
    	        y = a[x];
    	        if(x+y >= n) nex[x] = -1,steps[x] = 1;
    	        else if(b[x] == b[x+y]) nex[x] = nex[x+y],steps[x] = 1+steps[x+y];
        	    else nex[x] = x+y,steps[x] =1;
    	    }
	    }
	    else{
	        scanf("%d",&x);
	        x --;
	        int ans = 0,cur = x;
	        while (x != -1){
	           // cout << x << " ";
	            ans += steps[x];
	            cur = x;
	            x = nex[x];
	        }
	        while(cur < n) x = cur,cur = cur+a[cur];
	        printf("%d %d\n",x+1,ans);
	    }
	}
}