#include <bits/stdc++.h>
using namespace std;
int n;
int query(int l, int r){
    printf("%d %d ",1,r-l+1);
    printf("%d ",1);
    for(int i=l;i<=r;i++){
        printf("%d ",i);
    }
    printf("\n");
    fflush(stdout);
    int x;
    cin>>x;
    return x;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++){
        int n;
        scanf("%d",&n);
        int l=2;
        int r=n;
        int maxd=query(2,n);
        if(maxd==-1)	exit(12345);
        int farthest=-1;
        while(l<r){
			int m=(l+r)/2;
			int x=query(l, m);
			if(x==maxd)	r=m;
            else	l=m+1;
        }
        farthest=l;
        printf("%d %d ",1,n-1);
        printf("%d ",farthest);
        for(int i=1;i<=n;i++)
            if(i!=farthest)
                printf("%d ",i);
        printf("\n");
        int x;
        cin>>x;
        printf("-1 %d\n",x);
        fflush(stdout);
    }
}