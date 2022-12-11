#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,a[N],cnt[N],m;
int solve(int beg,int val){
    for(int i=beg;i<=n;i++)if(a[i]==val)return i;
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        vector<int>v;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            v.push_back(a[i]);
        }
        stable_sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        m=v.size();
        for(int i=0;i<=m;i++)cnt[i]=0;
        for(int i=1;i<=n;i++)cnt[a[i]]++;
        for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
        int l=1,r=0,ans1=-1,ans2=-1,mi=1e9;
        while(r<=m){
            if(r<l){r++;continue;}
            if((cnt[r]-cnt[l-1])*2>=k+n){
                if(mi>v[r-1]-v[l-1])mi=v[r-1]-v[l-1],ans1=r-1,ans2=l-1;
                l++;
            }
            else r++;
        }
        printf("%d %d\n",v[ans2],v[ans1]);
        l=v[ans2],r=v[ans1];
        for(int i=1;i<=n;i++)a[i]=((v[a[i]-1]>=l&&v[a[i]-1]<=r)?1:-1);
        for(int i=1;i<=n;i++)a[i]+=a[i-1];
        int last=1;
        for(int i=1;i<k;i++){
            int now=solve(last,i);
            printf("%d %d\n",last,now);
            last=now+1;
        }
        printf("%d %d\n",last,n);
    }
    return  0;
}