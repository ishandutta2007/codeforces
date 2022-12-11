#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int t,n,a[N],b[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
        if(a[0]!=b[0]){
            puts("NO");
            continue;
        }
		bool pd=1;
		vector<pair<int,int>>ans;
		for(int i=1;pd&&i<n;i++){
			if(a[i]==b[i])continue;
			int o;
			for(o=i;o<n;o++){
				if(a[o]==b[i]){
					if(a[o-1]==a[i-1]||o+1<n&&a[o+1]==a[i-1])break;
				}
			}
			if(o==n){
				pd=0,puts("NO");
				break;
			}
			if(o+1<n&&a[o+1]==a[i-1]){
				reverse(a+i-1,a+o+2);
				ans.push_back({i-1,o+1});
				continue;
			}
			bool pdd=0;
			for(int l=o-1;!pdd&&l>=i-1;l--){
				for(int r=o;r<n;r++){
                    if(a[l]==a[r]){
                        reverse(a+l,a+r+1);
                        ans.push_back({l,r});
                        pdd=1;
                        break;
                    }
                }
			}
			if(!pdd){
				pd=0,puts("NO");
				break;
			}
			for(o=i;o<n;o++){
				if(a[o]==b[i]){
					if(o+1<n&&a[o+1]==a[i-1])break;
				}
			}
			reverse(a+i-1,a+o+2);
			ans.push_back({i-1,o+1});
		}
		if(pd){
            printf("YES\n%d\n",(int)ans.size());
			for(auto [x,y]:ans)printf("%d %d\n",x+1,y+1);
		}
	}
}