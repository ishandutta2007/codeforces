#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=3e5+10;
const int MOD=1e9+7;
const int inf=1e9+10;
const int maxv=40;

int n,a[N],h[N];
string s1,s2;

bool check(int mid){
    memset(h,0,sizeof(h));
    for(int i=1;i<=mid;i++) h[a[i]-1]=1;
    int len=0;
    for(int i=0;i<n;i++) if (!h[i])
        if (len<s2.length()&&s1[i]==s2[len]) len++;
    return len==s2.length();
}
int solve(){
    int L=1,R=n;
    while (L<=R){
        int mid=(L+R)/2;
        if (check(mid)) L=mid+1;
        else R=mid-1;
    }
    return R;
}
void prepare(){
    cin>>s1>>s2;
    n=s1.length();
    for(int i=1;i<=n;i++) cin>>a[i];
}
int main(){
    prepare();
    cout<<solve();
}