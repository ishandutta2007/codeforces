#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n,m,a[N],l[N],r[N],q[N],pw[33][N],qt[N][31];
int st[N*10];
void Set(int c,int sl,int sr,int x){
    if(sl>x||sr<x||sl>sr)return;
    if(sl==sr){st[c]=a[x];return;}
    int mid=(sl+sr)>>1;
    Set(c*2+1,sl,mid,x);
    Set(c*2+2,mid+1,sr,x);
    st[c]=st[c*2+1]&st[c*2+2];
}
int Get(int c,int l,int r,int sl,int sr){
    if(l>r||sl>r||sr<l)return 0;
    if(sl<=l&&r<=sr)return st[c];
    int mid=(sl+sr)>>1;
    int lq=Get(c*2+1,l,mid,sl,sr),rq=Get(c*2+2,mid+1,r,sl,sr);
    if(min(lq,rq)==0)return max(lq,rq);
    else return lq&rq;
}
bool BruteForceCheck(){
    for(int i=0;i<31;i++)qt[0][i]=0;
    for(int i=1;i<=n;i++){
        int x=a[i];
        vector<int> p;
        while(x>0)p.push_back(x%2),x/=2;
        for(int j=0;j<31;j++){
            if(j>=(int)p.size())qt[i][j]=qt[i-1][j];
            else qt[i][j]=qt[i-1][j]+p[j];
        }
    }
    for(int i=1;i<=m;i++){
        int x=0;
        for(int j=0;j<31;j++)if(qt[r[i]][j]-qt[l[i]-1][j]==(r[i]-l[i])+1)x+=1<<j;
        if(x!=q[i])return false;
    }
    return true;
}
int main(){
    scanf("%i %i",&n,&m);
    for(int i=1;i<=m;i++)scanf("%i %i %i",&l[i],&r[i],&q[i]);
    for(int i=0;i<33;i++)for(int j=0;j<N;j++)pw[i][j]=0;
    for(int i=1;i<=m;i++){
        int x=q[i];
        vector<int> p;
        while(x>0)p.push_back(x%2),x/=2;
        for(int j=0;j<(int)p.size();j++)if(p[j]==1)pw[j][l[i]]++,pw[j][r[i]+1]--;
    }
    int bal[33];
    for(int i=0;i<33;i++)bal[i]=0;
    for(int i=1;i<=n;i++){
        a[i]=0;
        for(int j=0;j<33;j++)bal[j]+=pw[j][i];
        for(int j=0;j<33;j++)if(bal[j]>0)a[i]+=1<<j;
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<endl;
    //for(int i=1;i<=n;i++)Set(1,1,n,i);
    bool ok=1;
    if(!BruteForceCheck())ok=0;
    //for(int i=1;i<=m;i++)if(Get(1,l[i],r[i],1,n)!=q[i])ok=0;
    /*for(int i=1;i<=m;i++)cout<<Get(1,l[i],r[i],1,n)<<endl;
    cout<<endl<<endl;*/
    //for(int i=1;i<=10;i++)cout<<st[i]<<endl;
    if(ok){printf("YES\n");for(int i=1;i<=n;i++)printf("%i ",a[i]);}
    else printf("NO");
    return 0;
}