#include <bits/stdc++.h>
using namespace std;
int q,n;
int a[200001];
inline int Read(){
    int F=1,Num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') F=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        Num=Num*10+ch-'0';
        ch=getchar();
    }
    return Num*F;
}
int cnt[200007]={0};
int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d",&q);
	while(q--){
		n=Read();
		for(int i=0;i<=n+2;i++)	cnt[i]=0;
		for(int i=0;i<n;i++)	a[i]=Read();
		sort(a,a+n);
		int num=1;
		cnt[1]++;
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1])	num++;
			cnt[num]++;
		}
		sort(cnt+1,cnt+num+1);
		reverse(cnt+1,cnt+num+1);
		int ans=0,last=1,rem=0;
		for(int i=2;i<=num+1;i++){
//			cout<<"ans="<<ans<<"\trem="<<rem<<endl;
			if(cnt[i]!=cnt[i-1]){
				int dif=cnt[i-1]-cnt[i];
				if(dif>i-last+rem){
					ans+=(cnt[i-1]-(i-last+rem)+1+cnt[i-1])*(i-last+rem)/2;
					rem=0;
				}
				else{
					ans+=(cnt[i]+(cnt[i-1]+1))*dif/2;
					rem+=(i-last-dif);
				}
				last=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*2
12
13
1 1 1 1 2 2 2 3 3 4 4 5 5
17
1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4
19
1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 5 5
22
1 1 1 1 1 1 2 2 2 2 2 2 3 3 3 3 3 3 4 4 5 5
35
1 1 1 1 1 1 1 2 2 2 2 2 2 2 3 3 3 3 3 3 3 4 4 4 4 5 5 5 5 6 6 6 6 7 7
18
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5 5
9
1 1 1 1 2 2 2 2 3
13
1 1 1 1 1 2 2 2 2 2 3 3 4
6
1 1 1 2 2 2
17
1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 4 5
37
1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 6 6 6 6
*/