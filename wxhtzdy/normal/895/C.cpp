#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int sz=1<<19+1;
vector<int> p;
vector<long long> curr(sz,0),op(sz,0);
map<int,int> cnt;
bool prime(int x){
    for(int i=2;i*i<=x;i++)if((x%i)==0)return 0;
    return 1;
}
int main(){
    for(int i=2;i<=70;i++)if(prime(i))p.push_back(i);
    //printf("%i\n",p.size());
    int n;scanf("%i",&n);
    for(int i=0;i<n;i++){
        int a;scanf("%i",&a);
        for(int c:p)while((a%(c*c))==0)a/=(c*c);
        //printf("%i\n",a);
        cnt[a]++;
    }
    curr[0]=1;
    for(int i=1;i<=70;i++){
        if(cnt[i]){
            long long m=1;
            for(int rep=0;rep<cnt[i]-1;rep++)m=2*m%mod;
            for(int j=0;j<(int)op.size();j++)op[j]=0;
            int pw=0;
            for(int c=0;c<(int)p.size();c++)if(i%p[c]==0)pw^=1<<c;
            for(int c=0;c<(int)curr.size();c++){
                op[c^pw]+=m*curr[c];
                op[c^pw]%=mod;
                op[c]+=m*curr[c];
                op[c]%=mod;
            }
            swap(op,curr);
        }
    }
    curr[0]=(curr[0]+mod-1)%mod;
    cout<<curr[0];
    return 0;
}