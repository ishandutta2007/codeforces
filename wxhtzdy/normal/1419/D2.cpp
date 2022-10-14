#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    vector<int> ans;
    ans.push_back(a[n/2]);
    int l=0,r=n/2+1;
    for(int i=1;i<n;i++){
        if(i%2==0)ans.pb(a[r]),r++;
        else ans.pb(a[l]),l++;
    }
    int k=0;
    for(int i=1;i<n-1;i++)if(ans[i]<ans[i-1]&&ans[i]<ans[i+1])k++;
    printf("%i\n",k);
    for(int c:ans)printf("%i ",c);
    return 0;
}