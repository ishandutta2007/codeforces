#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=15+1;
int n,a[N],ok=0;
void Do(int k,vector<bool> take){
    if(k==n+1){
        int sum=0;
        for(int i=0;i<n;i++){
            if(take[i])sum+=a[i];
            else sum-=a[i];
        }
        if(sum%360==0)ok=1;
        return;
    }
    vector<bool> take0=take;
    vector<bool> take1=take;
    take0.pb(false);
    take1.pb(true);
    Do(k+1,take0);
    Do(k+1,take1);
}
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    Do(0,{});
    if(ok)cout<<"YES";
    else cout<<"NO";
    return 0;
}