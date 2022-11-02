#include<bits/stdc++.h>
using namespace std;
int L,R,a[100],tot,last;
struct Ask{
	int x,y,z;
	Ask(int _x=0,int _y=0,int _z=0){
		x=_x;y=_y;z=_z;
	}
};
vector<Ask> ans;
inline void add(int x,int y,int z){
	ans.push_back(Ask(x,y,z));
}
int main(){
	scanf("%d%d",&L,&R);
	if (L==R){
		puts("YES");
		printf("2 1\n");
		printf("1 2 %d\n",L);
		return 0;
	}
	R=R-L+1;
	while (R){
		a[++tot]=R%4;
		R/=4;
	}
	if (a[tot]==1){
		add(31,32,1);
		last=31;
	}
	else if (a[tot]==2){
		add(30,31,1);
		add(31,32,1);
		add(30,32,1);
		last=30;
	}
	else if (a[tot]==3){
		add(29,30,1);
		add(30,31,1);
		add(31,32,1);
		add(30,32,1);
		add(29,32,1);
		last=29;
	}
	int val=a[tot];
	puts("YES");
	for (int i=tot-1;i;i--){
		for (int j=0;j<(int)ans.size();j++){
			ans[j].z*=4;
			if (ans[j].x==last)ans[j].z-=3;
		}
		for (int j=0;j<(int)ans.size();j++)
			if (ans[j].x==last){
				for (int k=2;k<=3;k++)add(last-k,ans[j].y,ans[j].z);
				ans[j].x--;
			}
		add(last-3,last-2,1);
		add(last-2,last-1,1);
		add(last-3,last-1,3);
		val*=4;
		if (a[i])add(last,32,val-1);
		if (a[i]==1)add(last-3,last,2);
		else if (a[i]==2){
			add(last-3,last,2);
			add(last-2,last,2);
		}
		else if (a[i]==3){
			add(last-1,last,1);
			add(last-3,last,2);
		}
		last-=3;
		val+=a[i];
	}
	if (L==1){
		for (int i=0;i<(int)ans.size();i++)
			if (ans[i].x==last)ans[i].x=1;
	}
	else add(1,last,L-1);
	printf("32 %d\n",(int)ans.size());
	for (Ask i:ans)printf("%d %d %d\n",i.x,i.y,i.z);
}