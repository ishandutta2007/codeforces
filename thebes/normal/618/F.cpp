#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;

const int MN = 1e6+6;
pii wew[MN];
ll a[MN], b[MN], n, i, j, swp;
vi A, B;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(i=1;i<=n;i++) a[i]+=a[i-1], b[i]+=b[i-1];
    if(a[n]>b[n]) swp=1, swap(a,b);
    for(i=j=n;i>=0;i--){
        while(b[j]>a[i]) j--;
        if(wew[a[i]-b[j]]!=make_pair(0,0)){
            int d = a[i]-b[j];
            for(int k=i+1;k<=wew[d].first;k++) A.push_back(k);
            for(int k=j+1;k<=wew[d].second;k++) B.push_back(k);
            if(swp){
                printf("%d\n",B.size());
                for(auto v:B) printf("%d ",v);
                printf("\n%d\n",A.size());
                for(auto v:A) printf("%d ",v);
                printf("\n");
            }
            else{
                printf("%d\n",A.size());
                for(auto v:A) printf("%d ",v);
                printf("\n%d\n",B.size());
                for(auto v:B) printf("%d ",v);
                printf("\n");
            }
            return 0;
        }
        else wew[a[i]-b[j]]={i,j};
    }
}