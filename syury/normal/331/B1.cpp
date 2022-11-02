#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>p,a;
int n,q;

int main(){
    scanf("%d",&n);
    p.resize(n);a.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);a[i]--;
        p[a[i]]=i;
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);x--;y--;
        if(t==2){swap(a[x],a[y]);swap(p[a[x]],p[a[y]]);}
        else{
            int m=1;
            int curr=x+1;
            while(curr<=y){
                if(p[curr]<p[curr-1]){m++;}
                curr++;
            }
            printf("%d\n",m);
        }
    }
    return 0;
}