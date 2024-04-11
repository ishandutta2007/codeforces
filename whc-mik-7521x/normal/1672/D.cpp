#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N],b[N],cnt[N];
int main(){
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[i]=0;
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        int pd=0;
        int r1=n,r2=n;
        while(r1>0&&r2>0){
            if(a[r1]!=b[r2]){
                if(cnt[a[r1]])cnt[a[r1]]--,r1--;
                else{
                    pd=1;
                    break;
                }
            }
            else{
                int now=r2;
                while(now&&b[r2]==b[now]) now--;
                cnt[b[r2]]+=r2-now-1;
                r2=now;
                r1--;
            }
        }
        puts(pd?"NO":"YES");
    }
	return 0;
}