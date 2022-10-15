#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int t;
int n;
vector<PI> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        int q=sqrt(n),tm=n;
        VI ans;
        ans.clear();
        for (int i=2;i<=q;++i){
            if (n%i==0){
                ans.pb(i);
                n/=i;
            }
            if (ans.size()==2) break;
        }
        if (ans.size()>=2&&ans[0]!=n&&ans[1]!=n&&n>1){
            cout<<"YES"<<endl;
            cout<<ans[0]<<" "<<ans[1]<<" "<<n<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}