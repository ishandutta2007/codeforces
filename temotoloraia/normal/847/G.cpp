#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=200005;
int n;
string s;
int a[7];
int main() {
    cin>>n;
    while (n--){
        cin>>s;
        for (int i=0;i<7;i++)
            a[i]+=s[i]-'0';
    }
    int ans=a[0];
    for (int i=1;i<7;i++)
        ans=max(ans,a[i]);
    cout<<ans<<endl;
	return 0;
}