#include <bits/stdc++.h>
using namespace std;
struct node{
    int oper,end;
}b[200007];
int n,m,a[200007],ans[200007];  
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
    int sum=1,t[200007];
    t[sum++]=1;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&b[i].oper,&b[i].end);
        while(b[t[sum-1]].end<=b[i].end&&sum>1)	sum--;
        t[sum++]=i;
    }
    for(int i=n;i>=b[t[1]].end+1;i--)
		ans[i]=a[i];
    sort(a+1,a+1+b[t[1]].end);
    int low=1,high=b[t[1]].end;
    for(int i=2;i<sum;++i){
        if(b[t[i-1]].oper==1){
            for(int j=b[t[i-1]].end;j>=b[t[i]].end+1;--j)
                ans[j]=a[high--];
        }
        else{
            for(int j=b[t[i-1]].end;j>=b[t[i]].end+1;--j)
                ans[j]=a[low++];
        }
    }
    for(int i=1;i<=b[t[sum-1]].end;++i){
        if(b[t[sum-1]].oper==2)
            ans[i]=a[high--];
        else
            ans[i]=a[low++];
    }
    for(int i=1;i<=n;++i)	cout<<ans[i]<<" ";
    return 0;
}
/*
10 5
1 6 9 4 3 5 12 11 2 7
1 9
2 4
2 6
1 7
2 5
*/