#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=2007;

int q,n,m;

struct arr{
	int bx,by,ex,ey;
}let[27];

char mp[maxn][maxn];


int main(){
	scanf("%d",&q);
	while(q--){
		bool flag=true;
		int ans=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=26;++i){
			let[i].bx=let[i].by=let[i].ex=let[i].ey=-1;
		}
		for (int i=0;i<n;++i){
			cin>>mp[i];
		}
		for (int i=0;i<n;++i){
			for (int j=0;j<m;++j){
				if (mp[i][j]>='a'&&mp[i][j]<='z'){
					int idx=mp[i][j]-'a'+1;
					if (let[idx].bx==-1){
						let[idx].bx=i,let[idx].by=j;
						let[idx].ex=i,let[idx].ey=j;
					}
					else{
						if (i==let[idx].bx&&i==let[idx].ex){
							let[idx].ey=j;
						}
						else{
							if (j==let[idx].by&&j==let[idx].ey){
								let[idx].ex=i;
							}
							else{
								flag=false;
							}
						}
					}
				}
			}
		}
		for (int i=1;i<=26;++i){
			if (let[i].bx==-1) continue;
			else{
				ans=i;
				if (let[i].bx==let[i].ex){
					for (int j=let[i].by;j<=let[i].ey;++j){
						if (mp[let[i].bx][j]>='a'+i-1&&mp[let[i].bx][j]<='z') continue;
						flag=false;
					}
				}
				else{
					for (int j=let[i].bx;j<=let[i].ex;++j){
						if (mp[j][let[i].by]>='a'+i-1&&mp[j][let[i].by]<='z') continue;
						flag=false;
					}
				}
			}
		}
		if (flag){
			printf("YES\n%d\n",ans);
			for (int i=1;i<=ans;++i){
				if (let[i].bx==-1){
					printf("%d %d %d %d\n",let[ans].bx+1,let[ans].by+1,let[ans].ex+1,let[ans].ey+1);
				}
				else{
					printf("%d %d %d %d\n",let[i].bx+1,let[i].by+1,let[i].ex+1,let[i].ey+1);
				}
			}	
		}
		else{
			printf("NO\n");
		}
	}
}