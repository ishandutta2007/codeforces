#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N];
bool Valid(vector<int> x){
    int n=(int)x.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(x[i]<=x[j]&&x[j]<=x[k])return false;
                if(x[i]>=x[j]&&x[j]>=x[k])return false;
            }
        }
    }
    return true;
}
int main(){
    int tt;scanf("%i",&tt);
    while(tt--){
        int n;scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++){
            vector<int> b;
            for(int j=i;j<=n;j++){
                b.push_back(a[j]);
                if(!Valid(b))break;
                else ans++;
            }
        }
        printf("%i\n",ans);
    }
    return 0;
}