#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int lint;

vector<lint>a;
lint n;
vector<vector<lint> >st;
vector<lint>maxpow;
vector<lint>pow2;

lint getmin(lint l,lint r){
    //printf("l=%d r=%d\n",l,r);
    lint len=r-l+1;
    return min(st[l][maxpow[len]],st[r-pow2[maxpow[len]]+1][maxpow[len]]);
}

lint solve(lint l,lint r,lint sub){
    //printf("In %d %d\n",l,r);
    if(l>r){return 0;}
    if(l==r){return 1;}
    lint h=getmin(l,r)-sub;
    //printf("For %d %d h=%d\n",l,r,h);
    lint ans=h;
    vector<lint>z;
    for(lint i=l;i<=r;i++){
        if(a[i]-sub-h<=0){z.push_back(i);}
    }
    //for(size_t i=0;i<z.size();i++){printf("%d ",z[i]);}printf("\n");
    if(z[0]>l){ans+=solve(l,z[0]-1,sub+h);}
    if(z[z.size()-1]<r){ans+=solve(z[z.size()-1]+1,r,sub+h);}
    for(lint i=0;i<(lint)z.size()-1;i++){
        ans+=solve(z[i]+1,z[i+1]-1,sub+h);
    }
    ans=min(ans,r-l+1);
    //printf("For %d..%d (sub=%d) ans=%d\n",l,r,sub,ans);
    return ans;
}

int main(){
    scanf("%lld",&n);
    a.resize(n);st.resize(n);
    maxpow.resize(n+1);
    for(lint i=0;i<n;i++){
            scanf("%lld",&a[i]);
    }
    lint mp=0;
    for(lint i=1;i<=n;i++){
        lint tmax=0;
        lint j=1;
        while(j<=i){j*=2;tmax++;}
        tmax--;
        maxpow[i]=tmax;mp=max(tmax,mp);
    }
    pow2.resize(mp+1);
    pow2[0]=1;
    for(lint i=1;i<=mp;i++){
        pow2[i]=pow2[i-1]*2;
    }
    for(lint i=n-1;i>=0;i--){
        st[i].resize(maxpow[n-i]+1);
        for(lint k=0;k<=maxpow[n-i];k++){
            //printf("In %d %d\n",i,k);
            st[i][k]=(k==0)? a[i] : min(st[i][k-1],st[i+pow2[k-1]][k-1]);
            //printf("For %d %d st=%d\n",i,k,st[i][k]);
        }
    }
    printf("%lld",solve(0,n-1,0));
    return 0;
}